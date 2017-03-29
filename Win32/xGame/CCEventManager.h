#pragma once
#include"CCEngine.h"

enum EVENT_TYPE
{
	KEY_W_PRESS,
	KEY_A_PRESS,
	KEY_S_PRESS,
	KEY_D_PRESS,
	KEY_I_PRESS,
	KEY_O_PRESS,
	KEY_P_PRESS,
	KEY_J_PRESS,
	KEY_K_PRESS,
	KEY_L_PRESS,
	EVENT_KEY_PRESS_COUNT
};




template<typename T1>
class CCEventManager
{

	typedef void (T1::*Callback)(void);

private:
	CCEventManager(void)
	{
	}
	~CCEventManager(void)
	{

	}

public:

	static CCEventManager<T1>* SharedInstance()
	{
		if(m_Instance==NULL)
		{
			m_Instance=new CCEventManager<T1>();
		}
		return m_Instance;
	}

	//事件注册
	void RegisterEvent(EVENT_TYPE type,T1 *pobj, Callback callback)
	{
		//(pobj->*callback)();
		CALLBACK_VEC callbackVec;
		EVENT_CALLBACK_MAP::iterator iter=m_eventCallbackMap.find(type);
		if(iter==m_eventCallbackMap.end())
		{
			callbackVec.push_back(callback);
			m_eventCallbackMap.insert(std::make_pair(type,callbackVec));
		}
		else
		{
			(iter->second).push_back(callback);
		}
	}

	//发出事件
	void SendEvent(EVENT_TYPE type)
	{
		
	}



private:
	static CCEventManager<T1>* m_Instance;

	typedef vector<Callback> CALLBACK_VEC;
	CALLBACK_VEC m_callbackVec;

	typedef map<EVENT_TYPE,CALLBACK_VEC> EVENT_CALLBACK_MAP;
	EVENT_CALLBACK_MAP m_eventCallbackMap;
};

template<typename T1>
CCEventManager<T1>* CCEventManager<T1>::m_Instance=NULL;

