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

#include"PlayerPrefs.h"
#include"Convert.h"
#include<iostream>
#include<fstream>

std::map<std::string, PlayerPrefs::KeyValuePair*> PlayerPrefs::sm_keyValuePairMap;
TiXmlDocument* PlayerPrefs::sm_xmlDocument;

void PlayerPrefs::Read(const char* filename)
{
	std::string fullpath = filename;

	//文件不存在，先创建
	std::ifstream tmpXmlFile(fullpath);
	if (!tmpXmlFile)
	{
		std::ofstream tmpXmlFile;
		tmpXmlFile.open(fullpath, std::ios::out);

		tmpXmlFile.close();
	}

	//创建一个XML文档对象;
	sm_xmlDocument = new TiXmlDocument(fullpath.c_str());
	sm_xmlDocument->LoadFile(TIXML_ENCODING_UTF8);


	//获得根元素 PlayerPrefs;
	TiXmlElement *rootElement = sm_xmlDocument->RootElement();
	if (rootElement == NULL)
	{
		TiXmlDeclaration * tmpDec = new TiXmlDeclaration("1.0", "UTF-8", "yes");
		sm_xmlDocument->LinkEndChild(tmpDec);

		TiXmlElement* tmpElement = new TiXmlElement("PlayerPrefs");
		sm_xmlDocument->LinkEndChild(tmpElement);
		sm_xmlDocument->SaveFile();

		rootElement = sm_xmlDocument->RootElement();
	}
	//遍历 KeyValuePair;
	TiXmlNode *pNode = NULL;

	for (pNode = rootElement->FirstChildElement(); pNode != NULL; pNode = pNode->NextSiblingElement())
	{
		TiXmlElement *keyElement = pNode->FirstChildElement();
		TiXmlElement *valueTypeElement = keyElement->NextSiblingElement();
		TiXmlElement *valueElement = valueTypeElement->NextSiblingElement();

		std::string key = keyElement->FirstChild()->Value();
		std::string valueType = valueTypeElement->FirstChild()->Value();
		std::string value = valueElement->FirstChild()->Value();

		KeyValuePair *pKeyValuePair = new KeyValuePair();
		pKeyValuePair->m_key = key;
		pKeyValuePair->m_valueType = valueType;
		pKeyValuePair->m_value = value;

		//查找是否存在相同的Key;
		if (sm_keyValuePairMap.find(key) != sm_keyValuePairMap.end())
		{
			std::cout << "The Same Key has in PlayerPrefs!!!!" << std::endl;
			continue;
		}
		sm_keyValuePairMap.insert(std::pair<std::string, KeyValuePair*>(key, pKeyValuePair));
	}
}

void PlayerPrefs::SetValue(const char* key, const char* valueType, const char* value)
{
	if (sm_keyValuePairMap.find(key) != sm_keyValuePairMap.end())
	{
		//获得根元素 PlayerPrefs;
		TiXmlElement *rootElement = sm_xmlDocument->RootElement();

		//遍历 KeyValuePair;
		TiXmlNode *pNode = NULL;

		for (pNode = rootElement->FirstChildElement(); pNode != NULL; pNode = pNode->NextSiblingElement())
		{
			TiXmlElement *keyElement = pNode->FirstChildElement();

			std::string oldkey = keyElement->FirstChild()->Value();
			if (oldkey == key)
			{
				TiXmlElement *valueTypeElement = keyElement->NextSiblingElement();
				TiXmlElement *valueElement = valueTypeElement->NextSiblingElement();
				
				TiXmlNode *keyContent = keyElement->FirstChild();
				TiXmlNode *valueTypeContent = valueTypeElement->FirstChild();
				TiXmlNode *valueContent = valueElement->FirstChild();

				keyContent->SetValue(key);
				valueTypeContent->SetValue(valueType);
				valueContent->SetValue(value);

				sm_xmlDocument->SaveFile();

				KeyValuePair *pKeyValuePair = sm_keyValuePairMap[key];
				pKeyValuePair->m_key = key;
				pKeyValuePair->m_valueType = valueType;
				pKeyValuePair->m_value = value;

				break;
			}
		}
	}
	else
	{
		KeyValuePair *pKeyValuePair = new KeyValuePair();
		pKeyValuePair->m_key = key;
		pKeyValuePair->m_valueType = valueType;
		pKeyValuePair->m_value = value;
		sm_keyValuePairMap.insert(std::pair<std::string, KeyValuePair*>(key, pKeyValuePair));

		//写入XML;
		//获得根元素 PlayerPrefs;
		TiXmlElement *rootElement = sm_xmlDocument->RootElement();

		//创建一个 KeyValuePair元素 并 链接;
		TiXmlElement* keyValuePairElement = new TiXmlElement("KeyValuePair");
		rootElement->LinkEndChild(keyValuePairElement);

		//创建 Key, ValueType, Value元素 并链接;
		TiXmlElement *keyElement = new TiXmlElement("Key");
		TiXmlElement *valueTypeElement = new TiXmlElement("ValueType");
		TiXmlElement *valueElement = new TiXmlElement("Value");

		keyValuePairElement->LinkEndChild(keyElement);
		keyValuePairElement->LinkEndChild(valueTypeElement);
		keyValuePairElement->LinkEndChild(valueElement);

		//创建 Key, ValueType, Value元素 的 内容 并链接;
		TiXmlText *keyContent = new TiXmlText(key);
		TiXmlText *valueTypeContent = new TiXmlText(valueType);
		TiXmlText *valueContent = new TiXmlText(value);

		keyElement->LinkEndChild(keyContent);
		valueTypeElement->LinkEndChild(valueTypeContent);
		valueElement->LinkEndChild(valueContent);

		sm_xmlDocument->SaveFile();
	}
}

void PlayerPrefs::SetString(const char* key, const char* value)
{
	SetValue(key, "string", value);
}

void PlayerPrefs::SetInt(const char* key, const int value)
{
	SetValue(key, "int", Convert::IntToString(value).c_str());
}

void PlayerPrefs::SetBool(const char* key, const bool value)
{
	SetValue(key, "bool", Convert::BoolToString(value).c_str());
}

void PlayerPrefs::SetFloat(const char* key, const float value)
{
	SetValue(key, "float", Convert::FloatToString(value).c_str());
}

std::string PlayerPrefs::GetValue(const char* key,const char* valueType)
{
	if (sm_keyValuePairMap.find(key) != sm_keyValuePairMap.end())
	{
		KeyValuePair* pKeyValuePair = sm_keyValuePairMap[key];
		if (pKeyValuePair->m_valueType == valueType)
		{
			return pKeyValuePair->m_value;
		}

		std::cout << "GetValue Error With key=" << key << " valueType=" << valueType << std::endl;
		return "";
	}
	std::cout << "GetValue Error Without key=" << key << std::endl;
	return "";
}

std::string PlayerPrefs::GetString(const char* key)
{
	return GetValue(key, "string");
}

int PlayerPrefs::GetInt(const char* key)
{
	return Convert::StringToInt(GetValue(key, "int"));
}

bool PlayerPrefs::GetBool(const char* key)
{
	return Convert::StringToBool(GetValue(key, "bool"));
}

float PlayerPrefs::GetFloat(const char* key)
{
	return Convert::StringToFloat(GetValue(key, "float"));
}

void PlayerPrefs::DeleteKey(const char* key)
{
	if (sm_keyValuePairMap.find(key) != sm_keyValuePairMap.end())
	{
		//获得根元素 PlayerPrefs;
		TiXmlElement *rootElement = sm_xmlDocument->RootElement();

		//遍历 KeyValuePair;
		TiXmlNode *pNode = NULL;

		for (pNode = rootElement->FirstChildElement(); pNode != NULL; pNode = pNode->NextSiblingElement())
		{
			TiXmlElement *keyElement = pNode->FirstChildElement();

			std::string oldkey = keyElement->FirstChild()->Value();
			if (oldkey == key)
			{
				rootElement->RemoveChild(pNode);
				sm_xmlDocument->SaveFile();

				if (sm_keyValuePairMap.find(key) != sm_keyValuePairMap.end())
				{
					sm_keyValuePairMap.erase(key);
				}
				else
				{
					std::cout << "DeleteKey Error " << key << " not exist in sm_keyValuePairMap!!" << std::endl;
				}

				break;
			}
		}
	}
	else
	{
		std::cout << "DeleteKey Error " << key << " not exist!!" << std::endl;
	}
}

bool PlayerPrefs::HasKey(const char* key)
{
	return (sm_keyValuePairMap.find(key) != sm_keyValuePairMap.end());
}

void PlayerPrefs::DeleteAll()
{
	//获得根元素 PlayerPrefs;
	TiXmlElement *rootElement = sm_xmlDocument->RootElement();

	rootElement->Clear();

	sm_xmlDocument->SaveFile();

	sm_keyValuePairMap.clear();
}

void PlayerPrefs::Close()
{
	if (sm_xmlDocument != NULL)
	{
		delete(sm_xmlDocument);
		sm_xmlDocument = NULL;
	}
}