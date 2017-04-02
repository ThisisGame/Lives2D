#pragma once

#include "ODSocket.h"
#include<list>
#include<map>
#include"NetworkReceiver.h"
#include<string>
#include<iostream>


class NetWorkDispatch
{
public:
	static NetWorkDispatch* SharedInstance()
	{
		if (mInstance == nullptr)
		{
			mInstance = new NetWorkDispatch();
		}
		return mInstance;
	}

	//连接服务器
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

	void RegisterNetworkReceiver(GameMessage varGameMessage, NetworkReceiver* varNetworkReceiver)
	{
		std::list<NetworkReceiver*> tmpList = mNetWorkReceiverMap[varGameMessage];
		tmpList.push_back(varNetworkReceiver);
	}

	void UnRegisterNetworkReceiver(GameMessage varGameMessage, NetworkReceiver* varNetworkReceiver)
	{
		std::map<GameMessage, std::list<NetworkReceiver*>>::iterator tmpIter = mNetWorkReceiverMap.find(varGameMessage);
		if (tmpIter != mNetWorkReceiverMap.end())
		{
			std::list<NetworkReceiver*> tmpList = tmpIter->second;
			for (std::list<NetworkReceiver*>::iterator tmpIterNetworkReceiver=tmpList.begin();tmpIterNetworkReceiver!=tmpList.end();)
			{
				if ((*tmpIterNetworkReceiver) == varNetworkReceiver)
				{
					tmpIterNetworkReceiver = tmpList.erase(tmpIterNetworkReceiver);
				}
				else
				{
					tmpIterNetworkReceiver++;
				}
			}
		}
	}

	void Update()
	{
		mutexReceive.lock();
		if (listReceive.size() > 0)
		{
			char* data = listReceive.front();
			listReceive.pop_front();

			//事件分发,取前面2个字节为GameMessage
			GameMessage tmpGameMessage = GameMessage::None;
			memcpy(&tmpGameMessage, data, 2);

			std::map<GameMessage, std::list<NetworkReceiver*>>::iterator tmpIter = mNetWorkReceiverMap.find(tmpGameMessage);
			if (tmpIter != mNetWorkReceiverMap.end())
			{
				std::list<NetworkReceiver*> tmpList = tmpIter->second;
				for (std::list<NetworkReceiver*>::iterator tmpIterNetworkReceiver = tmpList.begin(); tmpIterNetworkReceiver != tmpList.end();)
				{
					(*tmpIterNetworkReceiver)->OnNetworkReceive(tmpGameMessage, data);
				}
			}
		}
		mutexReceive.unlock();
	}


	void Send(GameMessage varGameMessage, char* varData)
	{
		mutexSend.lock();

		char* tmpFullData = (char*)malloc(2 + sizeof(varData));
		memcpy(tmpFullData, &varGameMessage, 2);
		memcpy(tmpFullData + 2, varData, sizeof(varData));

		listSend.push_back(tmpFullData);

		mutexSend.unlock();
	}
private:
	void ReceiveThreadFunc()
	{
		while (true)
		{
			//延时代码 good
			//this_thread::sleep_for(chrono::seconds(3));
			//this_thread::yield();

			char *data = (char*)malloc(1024);
			int tmpRet = mODSocket.Recv(data, 1024);
			if (tmpRet >= 0)
			{
				mutexReceive.lock();
				char *datareal = (char*)malloc(tmpRet);
				memcpy(datareal, data, tmpRet);
				listReceive.push_back(datareal);
				delete(data);
				data = nullptr;
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
			mutexSend.lock();
			if (listSend.size() > 0)
			{
				char* data = listSend.front();
				listSend.pop_front();

				mODSocket.Send(data, sizeof(data));
			}
			mutexSend.unlock();
		}
	}

private:
	NetWorkDispatch() {};
	static NetWorkDispatch* mInstance;

	ODSocket mODSocket;

	std::mutex mutexSend;
	std::mutex mutexReceive;

	std::list<char*> listSend;
	std::list<char*> listReceive;

	std::map<GameMessage, std::list<NetworkReceiver*>> mNetWorkReceiverMap;
};

