ConnectID=
{
    Login,
    PVP,
    Logic,
}


local Connect=require("Framework/Network/Connect")
require("Framework/Network/NetMsgDispatch")

NetworkConnect=
{
    mConnectDic={}
}

function NetworkConnect:Register


function NetworkConnect:Connect(varConnectID,varHost,varPort,varReceiveConnectAcceptedListener)
    local tmpConnect=Connect.new()
    table.insert(mConnectDic,varConnectID,{tmpConnect,varReceiveConnectAcceptedListener})

    tmpConnect:Connect(varConnectID,varHost,varPort,self,self.ReceiveConnectAccepted,self.ReceiveNewPackListener)
end

function NetworkConnect:DisConnect(varConnectID)


end

function NetworkConnect:ReceiveConnectAccepted(varConnectID,varSocketID)
    local tmpConnectInfo= self.mConnectDic[varConnectID]
    tmpConnectInfo[2]()
end

function NetworkConnect:ReceiveNewPackListener(varConnectID,varSocketID,varJson)
    local msgjson=varJson
	local socketIdStr=varSocketID:ToString()
	print("----ReceiveNewPackListener from:" ..socketIdStr .. " " .. msgjson)


	local msg=cjson.decode(msgjson)
	local msgid=msg["msgid"]
    GameMessage:Print(msgid)
    
    NetMsgDispatch:DispatchMsg(msgid,msg)
end

function NetworkConnect:Update()
    for key,value in pairs(self.mConnectDic) do
        value[1]:Update()
    end
end

return NetworkConnect