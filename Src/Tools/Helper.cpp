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
void Helper::LOG(const char* str)
{
	LOGI("\n%s \n",str);
}

std::string Helper::ReadTxt(std::string& varFilePath)
{
	ifstream infile;
	infile.open(varFilePath.data());   //将文件流对象与文件连接起来 
	assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行 

	std::string tmpAllContent;
	string s;
	while (getline(infile, s))
	{
		tmpAllContent.append(s);
	}
	infile.close();             //关闭文件输入流 
	return tmpAllContent;
}

std::vector<std::string> Helper::ReadLine(std::string& varFilePath)
{
	ifstream infile;
	infile.open(varFilePath.data());   //将文件流对象与文件连接起来 
	assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行 

	std::vector<std::string> tmpResult;
	string s;
	while (getline(infile, s))
	{
		tmpResult.push_back(s);
	}
	infile.close();             //关闭文件输入流 
	return tmpResult;
}

std::vector<std::string> Helper::Split(std::string& varStr, std::string& varPattern)
{
	std::string::size_type pos;
	std::vector<std::string> result;
	varStr += varPattern;//扩展字符串以方便操作  
	size_t size = varStr.size();

	for (int i = 0; i<size; i++)
	{
		pos = varStr.find(varPattern, i);
		if (pos<size)
		{
			std::string s = varStr.substr(i, pos - i);
			result.push_back(s);
			i = pos + varPattern.size() - 1;
		}
	}
	return result;
}




unsigned int Helper::GetTime()
{
	unsigned int tmpTime;
#ifdef WIN32
	tmpTime = GetTickCount();//精确到毫秒
#endif
	return tmpTime;
}

std::string Helper::GetDirPath(std::string varFilePath)
{
	int tmpLastPatternIndex = varFilePath.find_last_of('/');
	std::string tmpDirPath = varFilePath.substr(0, tmpLastPatternIndex + 1);
	return tmpDirPath;
}

Helper::~Helper(void)
{
}
