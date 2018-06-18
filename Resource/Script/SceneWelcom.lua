require("Core/Core")
require("Public/Public")

local ResourcesManager=require("ResourcesManager")

local SceneWelcom=class()

local udpSocketConnectToLoginServer
local udpSocketConnectToPVPServer

local mRoleid=0

local playersTable={}

local mUIRoot=nil

local moveSpeed=0

function SceneWelcom:ctor()
	print("SceneWelcom:ctor")
	
	print(ResourcesManager:DataPath())

end

function SceneWelcom:Init()
	print("SceneWelcom:Init")
	
	local tmpGoUIRoot=GameObject:new("UIROOT")
	mUIRoot=tmpGoUIRoot:AddComponent("UIRoot")
	
	
	
	udpSocketConnectToLoginServer=UDPSocket:new()
	udpSocketConnectToLoginServer:SetReceiveConnectAccepted(Wrap(ReceiveConnectAccepted))
	udpSocketConnectToLoginServer:SetReceiveNewPackListener(Wrap(ReceiveNewPackListener))
	local tmpConnected=udpSocketConnectToLoginServer:Connect(LoginServer_Address,LoginServer_Port)
	if tmpConnected then
		print("Connect GateServer Success")
	end
end

---------------LoginServer---------------------

function ReceiveConnectAccepted(varSocketID)
	print("ReceiveConnectAccepted")
	SendMsgToServer(udpSocketConnectToLoginServer,{msgid=GameMessage.Login_Request})
end


function ReceiveNewPackListener(varSocketID,varJson)
	print("receivetime:" .. Time:GetTimeUS_Str())
	local msgjson=varJson
	
	
	local socketIdStr=varSocketID:ToString()
	print("----ReceiveNewPackListener from:" ..socketIdStr .. " " .. msgjson)
	
	
	local msg=cjson.decode(msgjson)
	

	local msgid=msg["msgid"]
	GameMessage:Print(msgid)

	if msgid==GameMessage.Login_Return then
		local pvpServerIP=msg["pvpip"]
		local pvpSeverPort=msg["port"]
		mRoleid=msg["roleid"]
		udpSocketConnectToPVPServer=UDPSocket:new()
		udpSocketConnectToPVPServer:SetReceiveConnectAccepted(Wrap(ReceiveConnectPVPServerAccepted))
		udpSocketConnectToPVPServer:SetReceiveNewPackListener(Wrap(ReceiveNewPackPVPServerListener))
		local tmpConnected=udpSocketConnectToPVPServer:Connect(pvpServerIP,pvpSeverPort)
		if tmpConnected then
			print("Connect PVPServer Success")
		end
	elseif msgid==GameMessage.Login_PlayerIn then
		local tmpPlayerID=msg["roleid"]
		
		if playersTable[tmpPlayerID]== nil then
			local tmpGoPlayer=GameObject:new("Player")
			playersTable[tmpPlayerID]=tmpGoPlayer
			
			local tmpPlayerNum=0
			for k,v in pairs(playersTable) do 
				print(k)
				print(v)
				tmpPlayerNum=tmpPlayerNum+1
			end
			
			local tmpPlayerImage =tmpGoPlayer:AddComponent("UIImage")
			tmpPlayerImage:Init(ResourcesManager:DataPath() .. "/Resource/UI/hero0.png",false);
			tmpPlayerImage.mTransform:SetLocalPosition(Vector3(0,100*tmpPlayerNum,0))
			tmpPlayerImage:SetDepth(0);
			mUIRoot:AddChild(tmpPlayerImage);
		end
		
		
	end
end

------------------PVPServer---------------------

local connectAccepted=false
local pvpStart=false
local msgIndex=0

function ReceiveConnectPVPServerAccepted(varSocketID)
	print("ReceiveConnectPVPServerAccepted")
	connectAccepted=true
end


local mTablePackWaitDispatch={}
function ReceiveNewPackPVPServerListener(varSocketID,varJson)
	
	local msgjson=varJson
	
	local socketIdStr=varSocketID:ToString()
	print("----ReceiveNewPackListener from:" ..socketIdStr .. " " .. msgjson)
	local msg=cjson.decode(msgjson)
	local msgid=msg["msgid"]
	GameMessage:Print(msgid)
	
	if pvpStart then
		print("Receive:" .. Time:GetTimeUS_Str())
		table.insert(mTablePackWaitDispatch,msg)
	else
		if msgid==GameMessage.PVP_Start then
			pvpStart=true
		end
	end
end




function SceneWelcom:Update(varDeltaTime)
	--print("SceneWelcom:Update " .. varDeltaTime)
	if mUIRoot~=nil then
		mUIRoot:Update(varDeltaTime)
	end

	udpSocketConnectToLoginServer:Update()
	
	if udpSocketConnectToPVPServer~=nil then
		udpSocketConnectToPVPServer:Update()
	end
	
	self:GameUpdate()
end

local receivedMsgIndex=0
function SceneWelcom:GameUpdate()
	--print("SceneWelcom:FixedUpdate")
	if table.getn(mTablePackWaitDispatch)>0 then
		print("mTablePackWaitDispatch Length:" .. table.getn(mTablePackWaitDispatch))
		for key,value in pairs(mTablePackWaitDispatch) do
			print(key)
		end
		local tmpFirst=mTablePackWaitDispatch[1]
		print("tmpFirst msgid:" .. tmpFirst["msgid"] )
		
		local allPlayerActionTable=tmpFirst["data"]
		print("allPlayerActionTable Length:" .. table.getn(allPlayerActionTable) )
		
		for key,value in pairs(allPlayerActionTable) do
			print("key:" .. key)
			local msg=value
			local tmpPlayerID=msg["roleid"]
			local tmpGoPlayer=playersTable[tmpPlayerID]
			local tmpNewPosition=tmpGoPlayer.mTransform:GetLocalPosition()
			tmpNewPosition.mX=math.sin(math.rad(1*receivedMsgIndex*tmpPlayerID))*500
			tmpGoPlayer.mTransform:SetLocalPosition(tmpNewPosition)
		end
		
		receivedMsgIndex=receivedMsgIndex+1
		table.remove(mTablePackWaitDispatch,1)
	end
end

function SceneWelcom:FixedUpdate()
	if msgIndex>0 then
		--return
	end
	if pvpStart then
		local msg={msgid=GameMessage.Move_Request,roleid=mRoleid,x=0,y=0,packIndex=msgIndex,sendTime=Time:GetTimeUS_Str()}
		SendMsgToServer(udpSocketConnectToPVPServer,msg)
		msgIndex=msgIndex+1
	end
end

function SceneWelcom:Draw()
	mUIRoot:Draw()
end

return SceneWelcom