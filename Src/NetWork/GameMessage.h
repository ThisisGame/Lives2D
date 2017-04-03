#pragma once
enum GameMessage
{
	//前排占位
	None=0,

	//请求 心跳包
	GM_HeartBeat_Request=1,

	//返回心跳包
	GM_HeartBeat_Return=2
};