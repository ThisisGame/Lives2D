#include"SocketID.h"

SocketID::SocketID():mSystemAddress(RakNet::UNASSIGNED_SYSTEM_ADDRESS)
{
}

SocketID::~SocketID()
{
}

const char * SocketID::ToString()
{
	return mSystemAddress.ToString();
}

bool SocketID::Equals(RakNet::SystemAddress& varSystemAddress)
{
	if (this->mSystemAddress == varSystemAddress)
	{
		return true;
	}
	return false;
}
