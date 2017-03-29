#include "Helper.h"

Helper::Helper(void)
{
}

//检查GL错误
void Helper::CheckGLError(const char* op)
{
	for(GLint error=glGetError();error;error=glGetError())
	{
		LOGE("after %s() glError (0x%x) \n",op,error);
	}
}

///输出GL变量的值
void Helper::PrintGLString(const char* name,GLenum s)
{
	const char *v=(const char *)glGetString(s);
	LOGI("GL %s = %s\n",name,v); //LOGI格式化字符串然后打LOG
}


//输出LOG
void Helper::CCLOG(const char* str)
{
	LOGI("\n%s \n",str);
}

Helper::~Helper(void)
{
}
