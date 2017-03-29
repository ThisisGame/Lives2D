#include "CCTimer.h"

#ifdef WIN32
#include<windows.h>
#endif



CCTimer::CCTimer(void)
{
}


unsigned int CCTimer::GetTime()
{
	unsigned int t;
#ifdef WIN32
	t=GetTickCount(); //¾«È·µ½ºÁÃë
#endif
	return t;
}

CCTimer::~CCTimer(void)
{
}
