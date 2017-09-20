#include "NetworkClient.h"

NetworkClient* NetworkClient::m_pSingleton = nullptr;

NetworkClient::NetworkClient()
{
}


NetworkClient* NetworkClient::GetSingleton()
{
	if (m_pSingleton == nullptr)
	{
		m_pSingleton = new NetworkClient();
	}

	return m_pSingleton;
}

void NetworkClient::SendMessage(int varMsgID, BinaryPacker * var_pBinaryPacker)
{
	int a = var_pBinaryPacker->PopInt();
	float f = var_pBinaryPacker->PopFloat();
}


NetworkClient::~NetworkClient()
{
}
