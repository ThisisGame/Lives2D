#include "UIParser.h"
#include"PlayerPrefs/TinyXml/tinyxml.h"
#include"Component/GameObject.h"
#include<fstream>
#include"Tools/Helper.h"

UIParser::UIParser()
{
}


UIParser::~UIParser()
{
}

void UIParser::CreateUI(const char * varFilePath)
{
	//文件不存在，先创建
	std::ifstream tmpXmlFile(varFilePath);
	if (!tmpXmlFile)
	{
		Helper::LOG("UIParser::CreateUI %s not exist",varFilePath);
		return;
	}

	//创建一个XML文档对象;
	TiXmlDocument* tmpTiXmlDocument = new TiXmlDocument(varFilePath);
	tmpTiXmlDocument->LoadFile(TIXML_ENCODING_UTF8);

	//获得根元素 PlayerPrefs;
	TiXmlElement *tmpTiXmlElementRoot = tmpTiXmlDocument->RootElement();
	if (tmpTiXmlElementRoot == NULL)
	{
		Helper::LOG("UIParser::CreateUI RootElement NULL");
		return;
	}

	//创建根节点
	GameObject* tmpGameObjectRoot = new GameObject(tmpTiXmlElementRoot->Value());

	RecursiveNode(tmpTiXmlElementRoot, tmpGameObjectRoot);

	
}

void UIParser::RecursiveNode(TiXmlElement * varTiXmlElementRoot, GameObject * varGameObjectRoot)
{
	//遍历 KeyValuePair;
	TiXmlNode *tmpTiXmlNode = NULL;

	for (tmpTiXmlNode = varTiXmlElementRoot->FirstChildElement(); tmpTiXmlNode != NULL; tmpTiXmlNode = tmpTiXmlNode->NextSiblingElement())
	{
		TiXmlElement
	}
}
