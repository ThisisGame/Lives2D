#pragma once


#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<fstream>


#include "CCImage.h"
#include "Helper.h"


using namespace std;

class CCEngine
{
public:
	CCEngine();
	~CCEngine();

	static void DrawBegin();

	static void DrawEnd();

};