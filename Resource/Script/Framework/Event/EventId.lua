--把要接受的EventId 填到下面

EventId=
{
    SevenLogin_RequestRewardData=10006,   --请求七天登录奖励数据;
    SevenLogin_ReturnRewardData=10007,   --请求七天登录奖励数据;
    SevenLogin_RequestInof=10008, --请求七天登录数据;
    SevenLogin_ReturnInof=10009, --请求七天登录数据;
    SevenLogin_RequestGetReward=10010, --请求领取奖励
    SevenLogin_ReturnGetReward=10011, --请求领取奖励
    SevenLogin_Show_Request=10017, --请求7天登录展示信息
    SevenLogin_Show_Return=10019,  --返回7天登录展示信息

    Login_RequestVerifyVersion=75,         --客户端验证版本号 请求
    Login_ReturnVerifyVersion=76,          --客户端验证版本号 返回

    LoveGifts_Window_Request=10150,    --爱心礼包界面信息
    LoveGifts_Window_Return=10151,
    LoveGifts_Info_Request=10152,      --爱心礼包个人信息
    LoveGifts_Info_Return=10153,
    LoveGifts_Get_Request=10154,      --领取爱心礼包奖励
    LoveGifts_Get_Return=10155,

    SystemSet_Change_Notify=568,--系统设置改变

    -- C#的值 < 9999

    Open_UI_Role_Panel = 10000,

    ReseTimeData_Notify = 10365, --过点刷新

    MysticalStore_UI_Request = 10366, --神秘商店请求界面信息
    MysticalStore_UI_Return = 10367,
    MysticalStore_Buy_Request = 10368, --神秘商店请求购买物品
    MysticalStore_Buy_Return = 10369,
    MysticalStore_Refresh_Request = 10370, --神秘商店请求刷新
    MysticalStore_Refresh_Return = 10371, --刷新返回和通知
    MysticalStore_Point_Request = 10372, --神秘商店兑换物品
    MysticalStore_Point_Return = 10373,
    MysticalStore_Start_Notify = 10374, --通知活动开启
    MysticalStore_End_Notify = 10375, --通知活动结束
    MysticalStore_Login_Request = 10376, --登录请求活动是否开启
    MysticalStore_Login_Return  = 10377,
}

return EventId