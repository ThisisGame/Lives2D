#pragma once

#include "RakPeerInterface.h"
#include "RakNetStatistics.h"
#include "MessageIdentifiers.h"
#include <stdio.h>
#include "Kbhit.h"
#include "GetTime.h"
#include "RakAssert.h"
#include "RakSleep.h"
#include "Gets.h"
#include"BitStream.h"

using namespace RakNet;

#ifdef _WIN32
#include "WindowsIncludes.h" // Sleep64
#else
#include <unistd.h> // usleep
#include <cstdio>
#include "Getche.h"
#endif

#include"../LuaEngine/LuaEngine.h"
#include "SocketID.h"
#include<vector>
#include<map>



class UDPSocket
{
private:
	RakPeerInterface *mRakPeerInterface;
	RakNet::SocketDescriptor mSocketDescriptor;
	unsigned short mNumberOfSystems;

	const char* mReceiveNewIncomingConnectionListener;
	const char* mReceiveNewPackListener;
	const char* mReceiveConnectAcceptedListener;
	const char* mReceiveConnectionLostListener;

	

	enum SocketType
	{
		None,
		Client,
		Server
	};
	SocketType mSocketType;

	SocketID* mServerSocketID;

	std::vector<SocketID*> mVectorClientSocketIDs;


public:
	UDPSocket();
	~UDPSocket();

public:

	bool Connect(char* varAddress,unsigned short varPort);

	bool Listen(char* varAddress, unsigned short varPort);

	void SetReceiveNewIncomingConnection(const char* varLuaFunctionName);

	void SetReceiveConnectAccepted(const char* varLuaFunctionName);

	void SetReceiveNewPackListener(const char* varLuaFunctionName);

	

	void SetReceiveConnectionLost(const char* varLuaFunctionName);

	void Update();

	void Send(const char* varJson);

	void Send(SocketID* var_pSocketID, const char* varJson);

	void CloseConnection(SocketID* var_pSocketID);///关闭一个链接

	void Stop();
};

