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

#pragma once
#include<iostream>
#include<strstream>
#include<sstream>
#include<string>
#include"Math/Math.h"

class Convert
{
public:
	Convert();
	~Convert();

	static std::string IntToString(const int value);

	static std::string BoolToString(const bool value);

	static std::string FloatToString(const float value);

	static int StringToInt(const std::string& value);

	static bool StringToBool(const std::string& value);

	static float StringToFloat(const std::string& value);

	static Vector3 StringToVector3(const char* value);
};

