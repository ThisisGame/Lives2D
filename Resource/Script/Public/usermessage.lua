local GameMessage=
{
    Login_Request=1001,
    Login_Return=1002,--返回玩家详细信息


    PVP_Start=2000,

    Move_Request=2001,
    Move_BroadCast=2002,
}


local GameMessageRevert={}

for key,value in pairs(GameMessage) do
    GameMessageRevert[value]=key
end

function GameMessage:Print(varMsgId)
    local str=GameMessageRevert[varMsgId]
    if str==nil then
        print("no such GameMessage:" .. varMsgId)
    else
        print(GameMessageRevert[varMsgId])
    end
end


return GameMessage
