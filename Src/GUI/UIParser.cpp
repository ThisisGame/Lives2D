#include "UIParser.h"
#include"PlayerPrefs/TinyXml/tinyxml.h"
#include"Component/GameObject.h"
#include<fstream>
#include"Tools/Helper.h"
#include"GUI/UIRoot.h"

UIParser::UIParser():mUIRoot(nullptr)
{
}


UIParser::~UIParser()
{
}

UIRoot* UIParser::CreateUI(const char * varFilePath)
{
	//文件不存在，先创建
	std::ifstream tmpXmlFile(varFilePath);
	if (!tmpXmlFile)
	{
		Helper::LOG("UIParser::CreateUI %s not exist",varFilePath);
		return nullptr;
	}

	//创建一个XML文档对象;
	TiXmlDocument* tmpTiXmlDocument = new TiXmlDocument(varFilePath);
	tmpTiXmlDocument->LoadFile(TIXML_ENCODING_UTF8);

	//获得根元素 PlayerPrefs;
	TiXmlElement *tmpTiXmlElementRoot = tmpTiXmlDocument->RootElement();
	if (tmpTiXmlElementRoot == NULL)
	{
		Helper::LOG("UIParser::CreateUI RootElement NULL");
		return nullptr;
	}

	//创建根节点
	GameObject* tmpGameObjectRoot = new GameObject(tmpTiXmlElementRoot->Attribute("Name"));
	
	RecursiveNode(tmpTiXmlElementRoot, tmpGameObjectRoot);

	return mUIRoot;
}

void UIParser::RecursiveNode(TiXmlElement * varTiXmlElementRoot, GameObject * varGameObjectRoot)
{
	varGameObjectRoot->InitWithXml(varTiXmlElementRoot);

	//遍历 KeyValuePair;
	TiXmlNode *tmpTiXmlNode = NULL;

	for (tmpTiXmlNode = varTiXmlElementRoot->FirstChildElement(); tmpTiXmlNode != NULL; tmpTiXmlNode = tmpTiXmlNode->NextSiblingElement())
	{
		TiXmlElement* tmpTiXmlElement = tmpTiXmlNode->ToElement();
		const char* tmpNodeName = tmpTiXmlElement->Value();
		if (strcmp(tmpNodeName, "Component")==0)
		{
			const char* tmpComponentType= tmpTiXmlElement->Attribute("Type");
			Component* tmpComponent= varGameObjectRoot->AddComponent(tmpComponentType);
			tmpComponent->InitWithXml(tmpTiXmlElement);

			if (strcmp(tmpComponentType, "UIRoot") == 0)
			{
				mUIRoot = (UIRoot*)tmpComponent;
			}
			else
			{
				if (mUIRoot == nullptr)
				{
					Helper::LOG("UIParser::RecursiveNode mUIRoot is null,UIRoot must be first in xml");
				}
				else
				{
					mUIRoot->AddChild((UIRect*)tmpComponent);
				}
			}
		}
		else if (strcmp(tmpNodeName, "GameObject")==0)
		{
			const char* tmpGameObjectName = tmpTiXmlElement->Attribute("Name");
			GameObject* tmpGo = new GameObject(tmpGameObjectName);
			
			varGameObjectRoot->AddChild(tmpGo);
			RecursiveNode(tmpTiXmlElement, tmpGo);
		}
	}
}
