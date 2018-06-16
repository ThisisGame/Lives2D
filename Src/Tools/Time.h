#pragma once
#include"RakNetTime.h"
#include"GetTime.h"
#include<string>

class Time
{
public:
	Time();
	~Time();

public:
	static int GetTimeMS();

	static std::string GetTimeUS_Str();

public:
	static float deltaTime;//上一帧花费的时间
};

