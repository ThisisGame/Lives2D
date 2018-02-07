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
#include<map>
#include<string>
#include"TinyXml/tinyxml.h"

class PlayerPrefs
{
public:

	static void Read(const char* filename);

	static void SetString(const char* key, const char* value);

	static void SetInt(const char* key, const int value);
	
	static void SetBool(const char* key, const bool value);

	static void SetFloat(const char* key, const float value);

	static std::string GetString(const char* key);

	static int GetInt(const char* key);

	static bool GetBool(const char* key);

	static float GetFloat(const char* key);

	static void DeleteKey(const char* key);

	static bool HasKey(const char* key);

	static void DeleteAll();

	static void Close();

private:
	static void SetValue(const char* key, const char* valuetype,const char* value);

	static std::string GetValue(const char* key, const char* valueType);

public:
	class KeyValuePair
	{
	public:
		std::string m_key;
		std::string m_valueType;
		std::string m_value;
	};

	
	static std::map<std::string, PlayerPrefs::KeyValuePair*> sm_keyValuePairMap;

	static TiXmlDocument* sm_xmlDocument;
};

