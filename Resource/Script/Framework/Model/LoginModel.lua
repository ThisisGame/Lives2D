require("Framework/Event/EventDispatch.lua")
require("Framework/Event/EventId.lua")
require("Framework/Network/NetMsgDispatch.lua")
require("Framework/Network/GameMessage.lua")
require("ProtoLua/account_pb.lua")



LoginModel=
{

}

function LoginModel:Register()
    EventDispatch:RegisterEventCallback(EventId.Login_RequestVerifyVersion,self,self.Login_RequestVerifyVersion)
    NetMsgDispatch:RegisterNetMsgCallback(GameMessage.GM_VERSION_RETURN,self,self.GM_VERSION_RETURN)
end

--Event回调
function LoginModel:Login_RequestVerifyVersion(varData)
    local tmpMsg=account_pb.GM_VerifyVersion()
    tmpMsg.version="1.4.8"
    tmpMsg.platform=0
    ProtobufStringData.data=tmpMsg:SerializeToString()
    ClientManager.GetSingleton().Login:SendMessageFromLua(GameMessage.GM_VERIFY_VERSION)
end

--Network回调
function LoginModel:GM_VERSION_RETURN()
    local tmpMsg=account_pb.GM_VerifyVersionReturn()
    tmpMsg:ParseFromString(ProtobufStringData.data)
    Debug.Log("VersionReturn:" .. tmpMsg.result)

    SLuaHelper:LoadPulice2AndPulice3Atlas()
end

return LoginModel