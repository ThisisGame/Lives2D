#include "Light.h"



Light::Light()
{
}



Light::~Light()
{
}

void Light::SetColor(int r, int g, int b, int a)
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}



void Light::SetPosition(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}
