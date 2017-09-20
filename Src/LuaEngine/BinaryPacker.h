#pragma once

#include<iostream>

class BinaryPacker
{

private:
	char* m_pBinaryCache;

	int m_iSize;

	int m_iIterPush;
	int m_iIterPop;

public:
	BinaryPacker()
	{
		
	}
	~BinaryPacker()
	{

	}



public:

	void Malloc(int varSize)
	{
		m_pBinaryCache = (char*)malloc(varSize);
		memset(m_pBinaryCache, 0, sizeof(m_pBinaryCache));

		m_iSize = varSize;

		m_iIterPush = 0;
		m_iIterPop = 0;
	}

	void PushInt(int varValue)
	{
		memcpy(m_pBinaryCache + m_iIterPush, &varValue, sizeof(int));

		m_iIterPush = m_iIterPush + sizeof(int);
	}

	void PushFloat(float varValue)
	{
		memcpy(m_pBinaryCache + m_iIterPush, &varValue, sizeof(float));

		m_iIterPush = m_iIterPush + sizeof(float);
	}


	char* GetBinaryCache()
	{
		return m_pBinaryCache;
	}

	int GetBinaryCacheSize()
	{
		return m_iSize;
	}


	void SetBinaryCache(char* varBinaryCache,int varSize)
	{
		m_pBinaryCache = varBinaryCache;
		m_iSize = varSize;
		m_iIterPop = 0;
	}

	int PopInt()
	{
		int tmpValue = 0;
		memcpy(&tmpValue, m_pBinaryCache + m_iIterPop, sizeof(int));
		m_iIterPop = m_iIterPop + sizeof(int);
		return tmpValue;
	}

	float PopFloat()
	{
		float tmpValue = 0;
		memcpy(&tmpValue, m_pBinaryCache + m_iIterPop, sizeof(float));
		m_iIterPop = m_iIterPop + sizeof(float);
		return tmpValue;
	}
};

