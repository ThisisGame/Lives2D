/*
http://blog.csdn.net/huutu/article/details/50448473
Original code by _Captain (http://dev.thisisgame.com.cn)

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any
damages arising from the use of this software.

Permission is granted to anyone to use this software for any
purpose, including commercial applications, and to alter it and
redistribute it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must
not claim that you wrote the original software. If you use this
software in a product, an acknowledgment in the product documentation
would be appreciated but is not required.

2. Altered source versions must be plainly marked as such, and
must not be misrepresented as being the original software.

3. This notice may not be removed or altered from any source
distribution.
*/

#include "Convert.h"


Convert::Convert()
{
}


Convert::~Convert()
{
}


std::string Convert::IntToString(const int value)
{
	std::strstream ss;
	std::string str;
	ss << value;
	ss >> str;
	return str;
}

std::string Convert::BoolToString(const bool value)
{
	return value ? "true":"false";
}

std::string Convert::FloatToString(const float value)
{
	std::ostringstream oss;
	
	oss << value;
	std::string str(oss.str());
	return str;
}

int Convert::StringToInt(const std::string& value)
{
	if (value == "")
	{
		return 0;
	}
	int num;
	std::stringstream ss;
	ss << value;
	ss >> num;

	return num;
}

bool Convert::StringToBool(const std::string& value)
{
	return value == "true" ? true : false;
}

float Convert::StringToFloat(const std::string& value)
{
	if (value == "")
	{
		return 0.0;
	}
	float f;
	std::stringstream ss;
	ss << value;
	ss >> f;
	return f;
}

Vector3 Convert::StringToVector3(const char * value)
{
	Vector3 tmpVector3;

	char* tmpOneNum = NULL;
	int  tmpOneNumIndex = 0;

	int tmpVector3ParamIndex = 0;

	int tmpSize = strlen(value);
	for (size_t i = 0; i < tmpSize; i++)
	{
		if (value[i] == '(' || value[i] == ',')
		{
			if (tmpOneNum != NULL)
			{
				tmpOneNum[tmpOneNumIndex++] = '\0';

				if (tmpVector3ParamIndex == 0)
				{
					tmpVector3.mX = StringToFloat(tmpOneNum);
				}
				else if (tmpVector3ParamIndex == 1)
				{
					tmpVector3.mY = StringToFloat(tmpOneNum);
				}
				tmpVector3ParamIndex++;
			}

			tmpOneNum = new char[10];
			tmpOneNumIndex = 0;

			memset(tmpOneNum, 0, 10);
			continue;
		}

		if (value[i] == ')')
		{
			tmpOneNum[tmpOneNumIndex++] = '\0';

			tmpVector3.mZ = StringToFloat(tmpOneNum);
		}
		else
		{
			tmpOneNum[tmpOneNumIndex++] = value[i];
		}
	}
	return tmpVector3;
}
