#pragma once
class CCVector3
{
public:
	CCVector3(void);
	~CCVector3(void);

	CCVector3(float x,float y,float z);

	//获取数据
	float* GetData();

public:
	float m_Data[3];
};

