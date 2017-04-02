#pragma once

#include "GameMessage.h"

class NetworkReceiver
{
public:
	/// <summary>
	/// 注册网络监听
	/// </summary>
	virtual void RegisterNetworkReceiver()=0;


	/// <summary>
	/// 取消网络监听
	/// </summary>
	virtual void UnRegisterNetworkReceiver()=0;


	//收到网络消息;
	virtual void OnNetworkReceive(GameMessage varGameMessage, char* varData)=0;
};
