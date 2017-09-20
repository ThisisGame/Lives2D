#include "NetworkDispatch.h"

NetworkDispatch* NetworkDispatch::m_pSingleton=nullptr;

NetworkDispatch::NetworkDispatch()
{
}

NetworkDispatch* NetworkDispatch::GetSingleton()
{
	if (m_pSingleton == nullptr)
	{
		m_pSingleton = new	 NetworkDispatch();
	}

	return m_pSingleton;
}

void NetworkDispatch::DispatchNetworkMsg()
{

}


NetworkDispatch::~NetworkDispatch()
{
}
