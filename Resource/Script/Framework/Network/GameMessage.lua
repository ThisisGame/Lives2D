--把要接受的GameMessage 填到下面

GameMessage=
{
    GM_VERIFY_VERSION=210,          --客户端验证版本号
    GM_VERSION_RETURN=211,          --版本号验证结果

    --/******************************************支付模块开始*********************************************/
    GM_CREATE_PAYMENT_REQUEST = 14700,          --客户端请求打开支付界面 即生成支付请求
    GM_CREATE_PAYMENT_RETURN = 14701,
    GM_APPSTORE_VERIFY_ORDER_REQUEST = 14702,               --客户端请求验证订单 Appstore用
    GM_APPSTORE_VERIFY_ORDER_RETURN = 14703,                --回复客户端finish包
    GM_GET_CHAREG_DATA_REQUEST = 14704,         --请求充值界面数据
    GM_GET_CHAREG_DATA_RETURN = 14705,
    GM_GOOGLEPLAY_VERIFY_ORDER_REQUEST = 14706, --客户端请求验证订单 google支付用(GooglePlay)
    GM_GOOGLEPLAY_VERIFY_ORDER_RETURN = 14707,              --回复客户端finish包
    GM_RECHARGE_OVER_RETURN = 14708,            --通知客户端  订单完成

    SM_CHECK_PAYMENT_REQUEST = 14709,           --向Http服务器请求检查漏单
    SM_CREATE_PAYMENT_REQUEST = 14710,          --向Http服务器请求创建一条支付信息
    SM_CREATE_PAYMENT_RETURN = 14711,
    SM_GET_PAYMENT_REQUEST = 14712,             --向Http服务器请求是否有未完成的支付订单
    SM_APPSTORE_VERIFY_ORDER_REQUEST = 14713,               --向Http服务器发包
    SM_APPSTORE_VERIFY_ORDER_RETURN = 14714,                --http服务器回包
    SM_CHAREG_DATA_DB_REQUEST = 14715,          --向数据库请求玩家数据
    SM_CHAREG_DATA_DB_RETURN = 14716,
    SM_GOOGLEPLAY_VERIFY_ORDER_REQUEST = 14716,             --向Http服务器发包
    SM_GOOGLEPLAY_VERIFY_ORDER_RETURN = 14717,              --http服务器回包
    SM_SEND_PAYMENT_REQUEST = 14718,    --发放订单
    SM_SEND_PAYMENT_RETURN = 14719,
    SM_FINISH_PAYMENT_REQUEST = 14720,          --向http服务器请求修改订单为完成状态
    SM_FINISH_PAYMENT_RETURN = 14721,
    SM_CREATE_ORDER_REQUEST = 14722,            --请求创建订单  - 新（Dean）

    SM_GET_WEEKCARD_FROM_DB = 14723,                        --逻辑服务器向db请求玩家周卡相关数据
    SM_GET_WEEKCARD_FROM_DB_RETURN = 14724,                 --数据服务器返回玩家周卡相关数据
    SM_GET_RECHARGE_FROM_DB = 14725,                        --逻辑服务器向db请求玩家充值数据
    SM_GET_RECHARGE_FROM_DB_RETURN = 14726,                 --数据服务器返回玩家充值数据
    GM_WEEKCARD_REQUEST = 14727,                            --请求周卡数据
    GM_WEEKCARD_RETURN = 14728,
    GM_WEEKCARD_CLICK_REQUEST = 14729,                      --请求领取周卡奖励
    GM_WEEKCARD_CLICK_RETURN = 14730,
    GM_RECHARGE_OPEN_REQUEST = 14731,                       --客户端请求打开充值界面
    GM_RECHARGE_OPEN_RETURN = 14732,                        --回客户端玩家充值信息
    GM_RECHARGE_REQUEST = 14733,                            --请求充值
    GM_RECHARGE_RETURN = 14734,                             --告知客户端充值结果
    GM_RECHARGE_FIRSTRECHARGE_REQUEST = 14735,              --显示首充信息
    GM_RECHARGE_FIRSTRECHARGE_RETURN = 14736,
    GM_RECHARGE_FIRSTRECHARGECLICK_REQUEST = 14737,         --请求领取首冲奖励
    GM_RECHARGE_FIRSTRECHARGECLICK_RETURN = 14739,
    GM_RECHARGE_FIRSTRECHARGEREWARD_REQUEST = 14740,        --请求首充奖励信息
    GM_RECHARGE_FIRSTRECHARGEREWARD_RETURN = 14741,
    GM_RECHARGE_FIRSTRECHARGEINFO_REQUEST = 14742,          --请求首冲信息
    GM_RECHARGE_FIRSTRECHARGEINFO_RETURN = 14743,

    GM_RECHARGE_LOVEREWARD_REQUEST = 14744,                 --请求爱心礼包信息
    GM_RECHARGE_LOVEREWARD_RETURN = 14745,
    GM_RECHARGE_LOVEREWARDINFO_REQUEST = 14746,             --请求爱心礼包个人信息
    GM_RECHARGE_LOVEREWARDINFO_RETURN = 14747,
    GM_RECHARGE_LOVEREWARDCLICK_REQUEST = 14748,            --请求领取爱心礼包
    GM_RECHARGE_LOVEREWARDCLICK_RETURN = 14749,

    SM_GET_FRISTRECHARGEEACH_FROM_DB = 14750,                       --逻辑服务器向db请求玩家购买商品信息
    SM_GET_FRISTRECHARGEEACH_FROM_DB_RETURN = 14751,

    GM_RECHARGE_CLEARCHARGE_NOTIFY = 14752,                 --通知客户端 首冲状态改变
    DB_RECHARGE_TRUNCATEEACH_REQUEST = 14753,           --清空首冲记录
    DB_PLAYER_CONFIGSYSTEMTIME_REQUEST = 14754,         --配置系统时间
    DB_PLAYER_CONFIGSYSTEMTIME_RETURN = 14755,

    GM_RECHARGELIST_INFO_REQUEST = 14756,               --请求充值排行榜界面基础信息
    GM_RECHARGELIST_INFO_RETURN = 14757,
    GM_RECHARGELIST_DETAIL_REQUEST = 14758,             --请求充值排行细节信息
    GM_RECHARGELIST_DETAIL_RETURN = 14759,
    GM_RECHARGELIST_OPEN_RETURN = 14760,                --通知有新的充值排行活动开启
    GM_RECHARGELIST_CLOSE_RETURN = 14761,               --通知有新的充值排行活动关闭

    GM_CENTER_RECHARGELIST_INFO_REQUEST = 14762,        --请求跨服充值排行榜界面基础信息
    GM_CENTER_RECHARGELIST_INFO_RETURN = 14763,
    GM_CENTER_RECHARGELIST_DETAIL_REQUEST = 14764,      --请求跨服充值排行细节信息
    GM_CENTER_RECHARGELIST_DETAIL_RETURN = 14765,
    GM_CENTER_RECHARGELIST_OPEN_RETURN = 14766,         --通知有新的跨服充值排行活动开启
    GM_CENTER_RECHARGELIST_CLOSE_RETURN = 14767,        --通知有新的跨服充值排行活动关闭

    SM_CENTER_RECHARGELIST_ADD_REQUEST = 14768,		-- 通知中心服务器 玩家充值
    --/******************************************支付模块结束**********************************************/

    GM_SEVENDAY_LOGIN_REWARD_REQUEST=14802,                   --请求7天登录奖励数据
    GM_SEVENDAY_LOGIN_REWARD_RETURN=14803,                    --回客户端7天登录奖励数据
    GM_SEVENDAY_LOGIN_REQUEST=14804,                          --客户端请求7天登录数据
    GM_SEVENDAY_LOGIN_RETURN=14805,                           --回客户端7天登录数据
    GM_SEVENDAY_LOGIN_CLICK_REQUEST=14806,                    --客户端请求领取7天登录奖励
    GM_SEVENDAY_LOGIN_CLICK_RETURN=14807,                     --请求领取7天登录奖励返回
    GM_SEVENDAY_LOGIN_SHOW_REQUEST=14808,                     --请求7天登录展示信息
    GM_SEVENDAY_LOGIN_SHOW_RETURN=14809,					  --请求7天登录展示信息返回

    GM_PLAYER_OTHER_REQUEST=24500,	                    --查看其它玩家基本信息（无显示信息）  4坐骑
    GM_PLAYER_OTHER_PLAYER_RETURN=24501,                --人物信息
    GM_PLAYER_OTHER_PROPERTY_RETURN=24502,	            --属性信息
    GM_PLAYER_OTHER_SKILL_RETURN=24503,                 --技能信息
    GM_PLAYER_OTHER_PET_RETURN=24504,                   --伙伴信息
    GM_PLAYER_OTHER_TITLE_RETURN=24505,                 --称号信息
    GM_PLAYER_OTHER_SUITEQUIP_RETURN=24506,             --套装信息
    GM_PLAYER_OTHER_RIDE_RETURN = 24507,
    GM_PLAYER_OTHER_WING_RETURN = 24508,
    GM_PLAYER_OTHER_FOOT_RETURN = 24509,		        -- 足迹
    GM_PLAYER_OTHER_TRUMP_RETURN = 24510,		        -- 玄兵
    GM_PLAYER_OTHER_XIANQI_RETURN = 24511,		        -- 仙器
    GM_PLAYER_OTHER_ARTIFACT_RETURN = 24512,	        -- 法宝
    GM_PLAYER_OTHER_GODWEAPON_RETURN = 24513,	        -- 神兵
    GM_PLAYER_OTHER_FIELD_RETURN = 24514,		        -- 领域
    GM_PLAYER_OTHER_MUSTDONE_RETURN = 24515,	        -- 道铠
    GM_PLAYER_OTHER_RUNE_RETURN = 24516,		        -- 符文
    GM_PLAYER_OTHER_NOTIFY=24509,                       --通知客户端 玩家数据获取中


    GM_FRIENDADD_REQUEST = 15110,               --请求添加好友

    --/****************************神秘商店***************************/
    SM_MYSTICALSTORE_POINT_REQUEST = 18200,		--向DB请求积分信息
    SM_MYSTICALSTORE_POINT_RETURN = 18201,

    GM_MYSTICALSTORE_UI_REQUEST = 18220,		-- 请求界面信息
    GM_MYSTICALSTORE_UI_RETURN = 18221,					-- 界面信息通知
    GM_MYSTICALSTORE_BUY_REQUEST = 18222,				-- 单场奖励发送结果
    GM_MYSTICALSTORE_BUY_RETURN = 18223,
    GM_MYSTICALSTORE_REFRESH_REQUEST = 18224,			-- 刷新购买界面
    GM_MYSTICALSTORE_REFRESH_RETURN = 18225,			-- 界面刷新通知
    GM_MYSTICALSTORE_POINT_REQUEST = 18226,				-- 积分兑换
    GM_MYSTICALSTORE_POINT_RETURN = 18227,
    GM_MYSTICALSTORE_LONGIN_REQUEST = 18228,			-- 当前活动请求
    GM_MYSTICALSTORE_LONGIN_RETURN =18229,

    GM_MYSTICALSTORE_START_NOTIFY = 18280,-- 通知有活动开始
    GM_MYSTICALSTORE_END_NOTIFY = 18281,		-- 通知有活动结束
    --/***************************神秘商店结束**************************/
}

return GameMessage