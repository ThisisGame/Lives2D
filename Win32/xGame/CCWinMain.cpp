#include "CCOGL.h"
#include "ODSocket.h"
#include"NetWorkDispatch.h"

int main(int argc,char* argv[])
{
	//if(!CCOGL::NativeInit(argc,argv,640,480))
	//{
	//	exit(1);
	//}
	bool tmpRet= NetWorkDispatch::SharedInstance().Connect("127.0.0.1", 1234);
	if (tmpRet)
	{
		NetWorkDispatch::SharedInstance().Send(GameMessage::None, "login");
	}

	while (true)
	{
		NetWorkDispatch::SharedInstance().Update();
		Sleep(10);
	}

	return 0;
}


