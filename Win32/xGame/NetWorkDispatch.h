#pragma once

#include "ODSocket.h"
#include<list>
#include"NetworkReceiver.h"






class NetWorkDispatch
{
public:
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
		mODSocket = ODSocket();
		mODSocket.Init();
		bool tmpRet = mODSocket.Connect(varIp.c_str(), varPort);
		if (tmpRet)
		{
			std::thread tmpRecvThread = std::thread(&NetWorkDispatch::ReceiveThreadFunc);
			tmpRecvThread.detach();

			std::thread tmpSendThread = std::thread(&NetWorkDispatch::SendThreadFunc);
			tmpSendThread.detach();
		}
		return tmpRet;
	}

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

	void Receive()
	{

	}

	void Send(GameMessage varGameMessage, char* varData)
	{
		mutexSend.lock();

		listSend.push_back(varData);

		mutexSend.unlock();
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


