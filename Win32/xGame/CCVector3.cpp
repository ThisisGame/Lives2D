#include "CCVector3.h"


CCVector3::CCVector3(void)
{
	m_Data[0]=0.0f;
	m_Data[1]=0.0f;
	m_Data[2]=0.0f;
}


CCVector3::CCVector3(float x,float y,float z)
{
	m_Data[0]=x;
	m_Data[1]=y;
	m_Data[2]=z;
}

//获取数据
float* CCVector3::GetData()
{
	return m_Data;
}


CCVector3::~CCVector3(void)
{
}
