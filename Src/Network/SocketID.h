#pragma once

#include"RakNetTypes.h"

class SocketID
{
public:
	SocketID();
	~SocketID();

public:
	RakNet::SystemAddress mSystemAddress;

public:
	const char* ToString();

	bool Equals(RakNet::SystemAddress& varSystemAddress);
};