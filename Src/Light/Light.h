#pragma once

#include<glm\glm.hpp>


class Light
{
public:
	Light();
	~Light();

	///设置颜色
	void SetColor(int r,int g,int b,int a);


	///设置位置
	void SetPosition(float x, float y, float z);


private:
	int r;
	int g;
	int b;
	int a;

	float x;
	float y;
	float z;
};

