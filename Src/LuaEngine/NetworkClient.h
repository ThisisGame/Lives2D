#pragma once

#include"BinaryPacker.h"

class NetworkClient
{
private:
	static NetworkClient* m_pSingleton;

private:
	NetworkClient();
	~NetworkClient();

public:
	static NetworkClient* GetSingleton();

	void SendMessage(int varMsgID, BinaryPacker* var_pBinaryPacker);
};

