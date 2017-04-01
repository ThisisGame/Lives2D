#pragma once

#include "ODSocket.h"
#include<list>
#include"NetworkReceiver.h"


class NetWorkDispatch
{
public:
	NetWorkDispatch() {};

	NetWorkDispatch(NetWorkDispatch&)
	{

	}

public:
	static NetWorkDispatch SharedInstance()
	{
		return mInstance;
	}

	bool Connect(std::string varIp, unsigned short varPort)
	{
		mODSocket.Init();
		mODSocket.Create(AF_INET, SOCK_STREAM, 0);
		bool tmpRet = mODSocket.Connect(varIp.c_str(), varPort);
		if (tmpRet)
		{
			std::thread tmpRecvThread = std::thread(&NetWorkDispatch::ReceiveThreadFunc,this);
			tmpRecvThread.detach();

			std::thread tmpSendThread = std::thread(&NetWorkDispatch::SendThreadFunc,this);
			tmpSendThread.detach();
		}
		return tmpRet;
	}

	void RegisterNetworkReceiver(GameMessage varGameMessage, NetworkReceiver& varNetworkReceiver)
	{
		std::list<NetworkReceiver> tmpList = mNetWorkReceiverMap[varGameMessage];
		tmpList.push_back(varNetworkReceiver);
	}

	void UnRegisterNetworkReceiver(GameMessage varGameMessage, NetworkReceiver& varNetworkReceiver)
	{
		std::map<GameMessage, std::list<NetworkReceiver>>::iterator tmpIter = mNetWorkReceiverMap.find(varGameMessage);
		if (tmpIter != mNetWorkReceiverMap.end())
		{
			std::list<NetworkReceiver> tmpList = tmpIter->second;
			for (std::list<NetworkReceiver>::iterator tmpIterNetworkReceiver=tmpList.begin();tmpIterNetworkReceiver!=tmpList.end();)
			{
				//if (tmpIterNetworkReceiver == varNetworkReceiver)
				//{

				//}
			}
		}
	}

	void Update()
	{
		if (listReceive.size() > 0)
		{
			mutexReceive.lock();
			char* data = listReceive.front();
			mutexReceive.unlock();
		}
	}


	void Send(GameMessage varGameMessage, char* varData)
	{
		mutexSend.lock();

		listSend.push_back(varData);

		mutexSend.unlock();
	}
private:
	void ReceiveThreadFunc()
	{
		while (true)
		{
			char data[1024] = "";
			int tmpRet = mODSocket.Recv(data, 1024);
			if (tmpRet >= 0)
			{
				mutexReceive.lock();
				listReceive.push_back(data);
				mutexReceive.unlock();
			}
			else
			{
				break;
			}

		}
		mODSocket.Close();
	}

	void SendThreadFunc()
	{
		while (true)
		{
			if (listSend.size() > 0)
			{
				mutexSend.lock();
				char* data = listSend.front();
				mutexSend.unlock();
			}
		}
	}

private:
	static NetWorkDispatch mInstance;


	ODSocket mODSocket;

	std::mutex mutexSend;
	std::mutex mutexReceive;

	std::list<char*> listSend;
	std::list<char*> listReceive;

	std::map<GameMessage, std::list<NetworkReceiver>> mNetWorkReceiverMap;
};
NetWorkDispatch NetWorkDispatch::mInstance;

