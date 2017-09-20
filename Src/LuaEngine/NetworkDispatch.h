#pragma once
class NetworkDispatch
{
private:
	static NetworkDispatch* m_pSingleton;

private:
	NetworkDispatch();
	~NetworkDispatch();

public:
	static NetworkDispatch* GetSingleton();

	void DispatchNetworkMsg();
};



