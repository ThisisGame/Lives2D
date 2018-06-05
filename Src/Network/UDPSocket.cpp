#include "UDPSocket.h"

UDPSocket::UDPSocket():mSocketType(SocketType::None)
{
	
}


bool UDPSocket::Connect(char * varAddress, unsigned short varPort)
{
	mRakPeerInterface = RakNet::RakPeerInterface::GetInstance();

	mSocketDescriptor.port = 0;
	StartupResult b = mRakPeerInterface->Startup(1, &mSocketDescriptor, 1);
	RakAssert(b == RAKNET_STARTED);

	bool bConnect = ((mRakPeerInterface->Connect(varAddress, (unsigned short)varPort, 0, 0, 0)) == RakNet::CONNECTION_ATTEMPT_STARTED);
	if (bConnect == false)
	{
			printf("UDPSocket.cpp UDPSocket::Connect Connect %s:%u Failed\n",varAddress,varPort);
			return false;
	}

	mSocketType = SocketType::Client;

	mServerSocketID = new SocketID();
	RakNet::SystemAddress tmpSystemAddressServer(varAddress, varPort);
	mServerSocketID->mSystemAddress = tmpSystemAddressServer;

	printf("UDPSocket.cpp UDPSocket::Connect Connect %s:%u Success\n", varAddress, varPort);
	return true;
}

bool UDPSocket::Listen(char * varAddress, unsigned short varPort)
{
	mRakPeerInterface = RakNet::RakPeerInterface::GetInstance();


	mSocketDescriptor.port = (unsigned short)varPort;
	bool b = mRakPeerInterface->Startup((unsigned short)600, &mSocketDescriptor, 1) == RakNet::RAKNET_STARTED;
	RakAssert(b);
	mRakPeerInterface->SetMaximumIncomingConnections(600);

	mSocketType = SocketType::Server;

	printf("UDPSocket.cpp UDPSocket::Listen Listen %s:%u Success\n", varAddress, varPort);

	return true;
}

void UDPSocket::SetReceiveNewIncomingConnection(const char* varLuaFunctionName)
{
	mReceiveNewIncomingConnectionListener = varLuaFunctionName;
}

void UDPSocket::SetReceiveConnectAccepted(const char * varLuaFunctionName)
{
	mReceiveConnectAcceptedListener = varLuaFunctionName;
}

void UDPSocket::SetReceiveNewPackListener(const char * varLuaFunctionName)
{
	mReceiveNewPackListener = varLuaFunctionName;
}


void UDPSocket::SetReceiveConnectionLost(const char * varLuaFunctionName)
{
	mReceiveConnectionLostListener = varLuaFunctionName;
}

void UDPSocket::Update()
{
	if (mSocketType == SocketType::None)
	{
		return;
	}

	{
		Packet *pPacket = mRakPeerInterface->Receive();
		while (pPacket)
		{
			switch (pPacket->data[0])
			{
			case ID_CONNECTION_REQUEST_ACCEPTED:
			{
				if (mSocketType == SocketType::Client)
				{
					printf("ID_CONNECTION_REQUEST_ACCEPTED\n");
					mRakPeerInterface->GetConnectionList(0, &mNumberOfSystems);

					printf("Connections = %i\n", mNumberOfSystems);

					RakNet::SystemAddress systemAddress = pPacket->systemAddress;
					if (systemAddress != RakNet::UNASSIGNED_SYSTEM_ADDRESS)
					{
						SocketID* pSocketID = nullptr;
						if (mSocketType == SocketType::Client)
						{
							pSocketID = mServerSocketID;
						}


						std::function<void(lua_State*)> tmpFunction = [&](lua_State* pLuaState)
						{
							tolua_pushstring(pLuaState, mReceiveConnectAcceptedListener);
							tolua_pushusertype(pLuaState, pSocketID, "SocketID");
						};
						LuaEngine::GetSingleton()->CallLuaFunction("RunWrap", 2, tmpFunction);

					}
				}
			}
			break;
			case ID_CONNECTION_LOST:
			{
				printf("ID_CONNECTION_LOST\n");

				mRakPeerInterface->GetConnectionList(0, &mNumberOfSystems);

				printf("Connections = %i\n", mNumberOfSystems);

				RakNet::SystemAddress systemAddress = pPacket->systemAddress;
				if (systemAddress != RakNet::UNASSIGNED_SYSTEM_ADDRESS)
				{
					SocketID* pSocketID = nullptr;
					if (mSocketType == SocketType::Client)
					{
						pSocketID = mServerSocketID;
					}
					else if (mSocketType == SocketType::Server)
					{
						for (size_t i = 0; i < mVectorClientSocketIDs.size(); i++)
						{
							if (mVectorClientSocketIDs[i]->Equals(systemAddress))
							{
								pSocketID = mVectorClientSocketIDs[i];
								break;
							}
						}
					}

					std::function<void(lua_State*)> tmpFunction = [&](lua_State* pLuaState)
					{
						tolua_pushstring(pLuaState, mReceiveConnectionLostListener);
						tolua_pushusertype(pLuaState, pSocketID, "SocketID");
					};
					LuaEngine::GetSingleton()->CallLuaFunction("RunWrap", 2, tmpFunction);

				}
			}


			break;
			case ID_DISCONNECTION_NOTIFICATION:
			{
				printf("ID_DISCONNECTION_NOTIFICATION\n");

				mRakPeerInterface->GetConnectionList(0, &mNumberOfSystems);

				printf("Connections = %i\n", mNumberOfSystems);
			}
				


				break;
			case ID_NEW_INCOMING_CONNECTION:
			{
				if (mSocketType == SocketType::Server)
				{
					printf("ID_NEW_INCOMING_CONNECTION\n");

					mRakPeerInterface->GetConnectionList(0, &mNumberOfSystems);

					printf("Connections = %i\n", mNumberOfSystems);

					//接收客户端连接
					RakNet::SystemAddress systemAddress = pPacket->systemAddress;
					if (systemAddress != RakNet::UNASSIGNED_SYSTEM_ADDRESS)
					{
						SocketID* pSocketID = new SocketID();
						pSocketID->mSystemAddress = systemAddress;

						mVectorClientSocketIDs.push_back(pSocketID);

						std::function<void(lua_State*)> tmpFunction = [&](lua_State* pLuaState)
						{
							tolua_pushstring(pLuaState, mReceiveNewIncomingConnectionListener);
							tolua_pushusertype(pLuaState, pSocketID, "SocketID");
						};
						LuaEngine::GetSingleton()->CallLuaFunction("RunWrap", 2, tmpFunction);
					}
				}
				
			}
				
				
				break;
			case ID_GAMEMSG:
			{
				//printf("ID_GAMEMSG\n");

				SocketID* pSocketID = nullptr;
				if (mSocketType == SocketType::Client)
				{
					pSocketID = mServerSocketID;
				}
				else if (mSocketType == SocketType::Server)
				{
					for (size_t i = 0; i < mVectorClientSocketIDs.size(); i++)
					{
						if (mVectorClientSocketIDs[i]->Equals(pPacket->systemAddress))
						{
							pSocketID = mVectorClientSocketIDs[i];
							break;
						}
					}
				}

				RakNet::BitStream bitStream(pPacket->data, pPacket->length, false);

				bitStream.IgnoreBytes(sizeof(RakNet::MessageID));

				RakString tmpRakString;
				bitStream.Read(tmpRakString);
				
				//printf(tmpRakString.C_String());


				std::function<void(lua_State*)> tmpFunction = [&](lua_State* pLuaState)
				{
					tolua_pushstring(pLuaState, mReceiveNewPackListener);
					tolua_pushusertype(pLuaState, pSocketID, "SocketID");
					tolua_pushstring(pLuaState, tmpRakString.C_String());
				};
				LuaEngine::GetSingleton()->CallLuaFunction("RunWrap", 3, tmpFunction);
			}
				
				break;
			}
			mRakPeerInterface->DeallocatePacket(pPacket);
			pPacket = mRakPeerInterface->Receive();
		}
	}
}

void UDPSocket::Send(const char* varJson)
{
	if (mSocketType !=SocketType::Client)
	{
		return;
	}

	BitStream bitStream;
	bitStream.Write((RakNet::MessageID)ID_GAMEMSG);

	RakString tmpRakString(varJson);
	bitStream.Write(tmpRakString);


	mRakPeerInterface->Send(&bitStream, PacketPriority::HIGH_PRIORITY, PacketReliability::RELIABLE_ORDERED, 0, RakNet::UNASSIGNED_SYSTEM_ADDRESS, true);
}

void UDPSocket::Send(SocketID* var_pSocketID , const char* varJson)
{
	if (mSocketType != SocketType::Server)
	{
		return;
	}

	if (var_pSocketID == nullptr)
	{
		printf("UDPSocket.cpp UDPSocket::Send var_pSocketID == nullptr");
		return;
	}

	BitStream bitStream;
	bitStream.Write((RakNet::MessageID)ID_GAMEMSG);

	RakString tmpRakString(varJson);
	bitStream.Write(tmpRakString);

	mRakPeerInterface->Send(&bitStream, PacketPriority::HIGH_PRIORITY, PacketReliability::RELIABLE_ORDERED, 0, var_pSocketID->mSystemAddress, false);
}

void UDPSocket::CloseConnection(SocketID * var_pSocketID)
{
	RakNet::RakPeerInterface::DestroyInstance(mRakPeerInterface);
}

void UDPSocket::Stop()
{
	if (mRakPeerInterface)
	{
		RakNet::RakPeerInterface::DestroyInstance(mRakPeerInterface);
	}
}


UDPSocket::~UDPSocket()
{
	Stop();
}
