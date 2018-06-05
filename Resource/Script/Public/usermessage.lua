local GameMessage=
{
    LoginServer_Register_To_GateServer_Request=1, --LoginServer向GateServer注册
    LoginServer_Register_To_GateServer_Return=2,

    DBServer_Register_To_LoginServer_Request=3, --DBServer向LoginServer注册
    DBServer_Register_To_LoginServer_Return=4,

    Query_To_DBServer_Request=5,  --其它Server向DBServer发送数据更新请求
    Query_To_DBServer_Return=6, --其它Server发送请求之后，等待DBServer写入数据库成功之后返回，才可以删除数据

    GameServer_Register_To_GateServer_Request=7,
    GameServer_Register_To_GateServer_Return=8,

    GameServer_Register_To_LoginServer_Request=9,
    GameServer_Register_To_LoginServer_Return=10,

    DBServer_Register_To_GameServer_Request=11,
    DBServer_Register_To_GameServer_Return=12,

    GameServer_Notify_GateServer_Account_Certified=13,--GameServer通知GateServer，当前客户端帐号已经认证
    GameServer_Notify_GateServer_RoleId_Certified=14,--GameServer通知GateServer，当前客户端角色已经认证

	Test=15,
	
    --客户端请求GateServer 开始

    --业务-登陆
    Enum_LoginServer_Start=1000,
    Login_Request=1001,
    Login_Return=1002,--返回玩家详细信息

    Verify_Version_Request=1010,
    Verify_Version_Return=1011,

    Register_Request=1020,
    Register_Return=1021,

    --业务-游戏逻辑
    Enum_GameServer_Start=2000,
    RoleList_Request=2001,
    RoleList_Return=2002,

    LoginRole_Request=2010,
    LoginRole_Return=2011,

    CreateRole_Request=2020,
    CreateRole_Return=2021,

    --PlayerInfo_Request=2030,
    RoleInfo_Return=2031,
    RoleInfo_Change_RoomCard=2032,
    RoleInfo_Change_Gold=2033,

    OpenGame_Request=2034,
    OpenGame_Return=2035,

    CreateRoom_Request=2040,
    CreateRoom_Return=2041,

    AddIntoRoom_Request=2050,
    AddIntoRoom_Return=2051, --进入房间之后返回房间玩家列表

    RoomList_Request=2060, --房间列表 所有游戏通用 机器人控制 显示房间标题 诱惑 刺激性 搏一搏 单车变摩托，配合金币回收 刺激玩家，发牌控制
    RoomList_Return=2061,

    PlayerInfo_Request=2070,--房间里面可以查看玩家信息
    PlayerInfo_Return=2071,

    


    --shuiguoji
    SHUIGUOJI_Enum_Start=3000,
    SHUIGUOJI_Now_XiaZhu=3001,
    SHUIGUOJI_XiaZhu_Request=3010,
    SHUIGUOJI_XiaZhu_Return=3011,
    SHUIGUOJI_Now_CaiDaXiao=3020,
    SHUIGUOJI_CaiDaXiao_Request=3030,
    SHUIGUOJI_CaiDaXiao_Return=3031,
    

    --GateServer转发到业务服务器 开始
    GateServer_To_BusinessServer=10000,

    --业务服务器转发到GateServer 开始
    BussinessServer_To_GateServer=20000,
}


local GameMessageRevert={}

for key,value in pairs(GameMessage) do
    GameMessageRevert[value]=key
end

function GameMessage:Print(varMsgId)
    if varMsgId>GameMessage.BussinessServer_To_GateServer then
        varMsgId=varMsgId-GameMessage.BussinessServer_To_GateServer
    elseif varMsgId>GameMessage.GateServer_To_BusinessServer then
        varMsgId=varMsgId-GameMessage.GateServer_To_BusinessServer
    end

    local str=GameMessageRevert[varMsgId]
    if str==nil then
        print("no such GameMessage:" .. varMsgId)
    else
        print(GameMessageRevert[varMsgId])
    end
end



GameType=
{
    Game1=1,
    Game2=2,
    Game3=3,
    Game4=4,
    ShuiGuoJi=5,
}

ShuiGuoType=
{
    juzi=1,
    lindang=2,
    bar=3,
    xingxing=4,
    pingguo=5,
    lizi=6,
    xigua=7,
    qiqi=8,
    goodluck=9,
}

ShuiGuoDaXiaoType=
{
    da=1,
    xiao=2,
}


ShuiGuoZhuanPanPoints=
{
    {ShuiGuoType.juzi,1},
    {ShuiGuoType.lindang,1},
    {ShuiGuoType.bar,1},
    {ShuiGuoType.bar,2},
    {ShuiGuoType.pingguo,1},
    {ShuiGuoType.pingguo,2},
    {ShuiGuoType.lizi,1},
    {ShuiGuoType.xigua,1},
    {ShuiGuoType.xigua,2},
    {ShuiGuoType.goodluck,1},
    {ShuiGuoType.pingguo,1},
    {ShuiGuoType.juzi,2},
    {ShuiGuoType.juzi,1},
    {ShuiGuoType.lindang,1},
    {ShuiGuoType.qiqi,2},
    {ShuiGuoType.qiqi,1},
    {ShuiGuoType.pingguo,1},
    {ShuiGuoType.lizi,2},
    {ShuiGuoType.lizi,1},
    {ShuiGuoType.xingxing,1},
    {ShuiGuoType.xingxing,2},
    {ShuiGuoType.goodluck,1},
    {ShuiGuoType.pingguo,1},
    {ShuiGuoType.lindang,2},
}

return GameMessage