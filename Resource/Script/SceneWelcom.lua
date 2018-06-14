require("Core/Core")
require("Public/Public")

local ResourcesManager=require("ResourcesManager")

local SceneWelcom=class()

local udpSocketConnectToLoginServer
local udpSocketConnectToPVPServer

local mRoleid=0

function SceneWelcom:ctor()
	print("SceneWelcom:ctor")
	
	print(ResourcesManager:DataPath())
	
	self.mUIRoot=nil
end

local mGoImageBg
function SceneWelcom:Init()
	print("SceneWelcom:Init")
	
	local tmpGoUIRoot=GameObject:new("UIROOT")
	self.mUIRoot=tmpGoUIRoot:AddComponent("UIRoot")
	
	mGoImageBg=GameObject:new("mImage_Bg")
	
	local	mImage_Bg =mGoImageBg:AddComponent("UIImage")
	mImage_Bg:Init(ResourcesManager:DataPath() .. "/Resource/UI/pointer-lb128.png",false);
	
	mImage_Bg.mTransform:SetLocalPosition(Vector3(0,0,0))
	mImage_Bg:SetDepth(0);
	self.mUIRoot:AddChild(mImage_Bg);
	
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
	print("receivetime:" .. os.clock())
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
	end
end

------------------PVPServer---------------------

local pvpStart=false
local msgIndex=0

function ReceiveConnectPVPServerAccepted(varSocketID)
	print("ReceiveConnectPVPServerAccepted")
	
end


local mTablePackWaitDispatch={}
function ReceiveNewPackPVPServerListener(varSocketID,varJson)
	
	local msgjson=varJson
	
	local socketIdStr=varSocketID:ToString()
	--print("----ReceiveNewPackListener from:" ..socketIdStr .. " " .. msgjson)
	local msg=cjson.decode(msgjson)
	local msgid=msg["msgid"]
	--GameMessage:Print(msgid)
	
	if pvpStart then
		table.insert(mTablePackWaitDispatch,msg)
	else
		if msgid==GameMessage.PVP_Start then
			pvpStart=true
		end
	end
end




function SceneWelcom:Update(varDeltaTime)
	--print("SceneWelcom:Update " .. varDeltaTime)
	if self.mUIRoot~=nil then
		self.mUIRoot:Update(varDeltaTime)
	end

	udpSocketConnectToLoginServer:Update()
	
	if udpSocketConnectToPVPServer~=nil then
		udpSocketConnectToPVPServer:Update()
	end
end

function SceneWelcom:FixedUpdate()
	--print("SceneWelcom:FixedUpdate")
	if table.getn(mTablePackWaitDispatch)>0 then
		local tmpFirst=mTablePackWaitDispatch[1]
		
		local msg=tmpFirst["data"][1]
		
		--拿到服务器广播数据，修改客户端表现
		--print(msg["x"] .. "," .. msg["y"])
		
		mGoImageBg.mTransform:SetLocalPosition(Vector3(msg["x"],msg["y"],0))
		
		table.remove(mTablePackWaitDispatch,1)
	end
	
	
	local msg={msgid=GameMessage.Move_Request,roleid=mRoleid,x=Input.mousePosition.mX,y=Input.mousePosition.mY,packIndex=msgIndex}
	SendMsgToServer(udpSocketConnectToPVPServer,msg)
	msgIndex=msgIndex+1
end

function SceneWelcom:Draw()
	self.mUIRoot:Draw()
end

return SceneWelcom