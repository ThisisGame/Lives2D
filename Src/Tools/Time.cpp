#include "Time.h"
#include<sstream>
#include<strstream>

float Time::deltaTime=0;

Time::Time()
{
}


Time::~Time()
{
}

int Time::GetTimeMS()
{
	int tmpTimeMS = RakNet::GetTimeMS();
	return tmpTimeMS;
}

std::string Time::GetTimeUS_Str()
{
	RakNet::TimeUS tmpTimeUS = RakNet::GetTimeUS();
	std::ostringstream oss;

	oss << tmpTimeUS;
	std::string str(oss.str());

	return str;
}
