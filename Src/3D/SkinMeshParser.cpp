#include "SkinMeshParser.h"
#include"PlayerPrefs/TinyXml/tinyxml.h"
#include"Component/GameObject.h"
#include<fstream>
#include"Tools/Helper.h"

SkinMeshParser::SkinMeshParser()
{
}


GameObject*	 SkinMeshParser::Create(const char * varFilePath)
{
	//文件不存在，先创建
	std::ifstream tmpXmlFile(varFilePath);
	if (!tmpXmlFile)
	{
		Helper::LOG("SkinMeshParser::CreateScene %s not exist", varFilePath);
		return nullptr;
	}

	//创建一个XML文档对象;
	TiXmlDocument* tmpTiXmlDocument = new TiXmlDocument(varFilePath);
	tmpTiXmlDocument->LoadFile(TIXML_ENCODING_UTF8);

	//获得根元素 PlayerPrefs;
	TiXmlElement *tmpTiXmlElementRoot = tmpTiXmlDocument->RootElement();
	if (tmpTiXmlElementRoot == NULL)
	{
		Helper::LOG("SkinMeshParser::CreateScene RootElement NULL");
		return nullptr;
	}

	//创建根节点
	GameObject* tmpGameObjectRoot = new GameObject(tmpTiXmlElementRoot->Attribute("Name"));

	RecursiveNode(tmpTiXmlElementRoot, tmpGameObjectRoot);

	return tmpGameObjectRoot;
}

void SkinMeshParser::RecursiveNode(TiXmlElement * varTiXmlElementRoot, GameObject * varGameObjectRoot)
{
	varGameObjectRoot->InitWithXml(varTiXmlElementRoot);

	//遍历 KeyValuePair;
	TiXmlNode *tmpTiXmlNode = NULL;

	for (tmpTiXmlNode = varTiXmlElementRoot->FirstChildElement(); tmpTiXmlNode != NULL; tmpTiXmlNode = tmpTiXmlNode->NextSiblingElement())
	{
		TiXmlElement* tmpTiXmlElement = tmpTiXmlNode->ToElement();
		const char* tmpNodeName = tmpTiXmlElement->Value();
		if (strcmp(tmpNodeName, "Component") == 0)
		{
			const char* tmpComponentType = tmpTiXmlElement->Attribute("Type");
			Component* tmpComponent = varGameObjectRoot->AddComponent(tmpComponentType);
			tmpComponent->InitWithXml(tmpTiXmlElement);
		}
		else if (strcmp(tmpNodeName, "GameObject") == 0)
		{
			const char* tmpGameObjectName = tmpTiXmlElement->Attribute("Name");
			GameObject* tmpGo = new GameObject(tmpGameObjectName);

			varGameObjectRoot->AddChild(tmpGo);
			RecursiveNode(tmpTiXmlElement, tmpGo);
		}
	}
}

SkinMeshParser::~SkinMeshParser()
{
}


