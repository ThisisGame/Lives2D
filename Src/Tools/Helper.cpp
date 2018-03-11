#include "Helper.h"
#include"ConvertUTF/ConvertUTF.h"

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
void Helper::LOG(const char* format,...)
{
	char buff[1024];
	va_list paramList;
	va_start(paramList, format);
	vsprintf(buff, format, paramList);
	va_end(paramList);
	LOGI("\n%s \n", buff);
}

std::string Helper::ReadTxt(const char* varFilePath)
{
	ifstream infile;
	infile.open(varFilePath);   //将文件流对象与文件连接起来 
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
	//LOG("ReadLine %s", varFilePath.c_str());
	ifstream infile;
	infile.open(varFilePath.c_str());   //将文件流对象与文件连接起来 
	if (infile.is_open()==false)
	{
		LOG("ReadLine %s Error", varFilePath.c_str());
	}

	std::vector<std::string> tmpResult;
	string s;
	while (getline(infile, s))
	{
		//LOG("getline %s", s.c_str());

		size_t pos = s.find('\n');
		if (pos!=string::npos)
		{
			//LOG("%s erase n %d", s.c_str(), pos - 1);
			s.erase(pos, 1);
		}
		
		pos = s.find('\r');
		if (pos != string::npos)
		{
			//LOG("%s erase r %d", s.c_str(),pos - 1);
			s.erase(pos, 1);
		}
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

typedef unsigned int    UTF32;  /* at least 32 bits */
typedef unsigned short  UTF16;  /* at least 16 bits */
typedef unsigned char   UTF8;   /* typically 8 bits */

template <typename T>
struct ConvertTrait {
	typedef T ArgType;
};
template <>
struct ConvertTrait<char> {
	typedef UTF8 ArgType;
};
template <>
struct ConvertTrait<char16_t> {
	typedef UTF16 ArgType;
};
template <>
struct ConvertTrait<char32_t> {
	typedef UTF32 ArgType;
};

template <typename From, typename To, typename FromTrait = ConvertTrait<From>, typename ToTrait = ConvertTrait<To>>
bool utfConvert(
	const std::basic_string<From>& from, std::basic_string<To>& to,
	ConversionResult(*cvtfunc)(const typename FromTrait::ArgType**, const typename FromTrait::ArgType*,
		typename ToTrait::ArgType**, typename ToTrait::ArgType*,
		ConversionFlags)
)
{
	static_assert(sizeof(From) == sizeof(typename FromTrait::ArgType), "Error size mismatched");
	static_assert(sizeof(To) == sizeof(typename ToTrait::ArgType), "Error size mismatched");

	if (from.empty())
	{
		to.clear();
		return true;
	}

	// See: http://unicode.org/faq/utf_bom.html#gen6
	static const int most_bytes_per_character = 4;

	const size_t maxNumberOfChars = from.length(); // all UTFs at most one element represents one character.
	const size_t numberOfOut = maxNumberOfChars * most_bytes_per_character / sizeof(To);

	std::basic_string<To> working(numberOfOut, 0);

	auto inbeg = reinterpret_cast<const typename FromTrait::ArgType*>(&from[0]);
	auto inend = inbeg + from.length();


	auto outbeg = reinterpret_cast<typename ToTrait::ArgType*>(&working[0]);
	auto outend = outbeg + working.length();
	auto r = cvtfunc(&inbeg, inend, &outbeg, outend, strictConversion);
	if (r != conversionOK)
		return false;

	working.resize(reinterpret_cast<To*>(outbeg) - &working[0]);
	to = std::move(working);

	return true;
};

bool Helper::UTF8ToUTF32(const std::string& utf8, std::u32string& outUtf32)
{
	return utfConvert(utf8, outUtf32, ConvertUTF8toUTF32);
}

const char * Helper::StrCat(const char * varStr1, const char * varStr2)
{
	char tmpTarget[128];
	memset(tmpTarget, 0, 128);
	strcat(tmpTarget, varStr1);
	strcat(tmpTarget, varStr2);
	return tmpTarget;
}

Helper::~Helper(void)
{
}
