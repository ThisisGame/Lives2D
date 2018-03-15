#pragma once

#include<iostream>
#include<string>
using namespace std;

#include"TextureType.h"

//#pragma pack(1)
class Texture 
{
public:
	int id;
	TextureType texturetype;
	char path[1024];
};