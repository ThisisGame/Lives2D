#pragma once

#include "GameMessage.h"

class NetworkReceiver
{
public:
	/// <summary>
	/// 注册网络监听
	/// </summary>
	void RegisterNetworkReceiver();


	/// <summary>
	/// 取消网络监听
	/// </summary>
	void UnRegisterNetworkReceiver();


	//收到网络消息;
	void OnNetworkReceive(GameMessage varGameMessage, char* varData);
};
