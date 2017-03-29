#include "CCOGL.h"

int main(int argc,char* argv[])
{
	if(!CCOGL::NativeInit(argc,argv,640,480))
	{
		exit(1);
	}
	return 0;
}
