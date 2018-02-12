#pragma once

class TiXmlDocument;
class GameObject;
class UIParser
{
public:
	UIParser();
	~UIParser();

	void CreateUI(const char* varFilePath);

	void RecursiveNode(TiXmlElement* varTiXmlElementRoot, GameObject* varGameObjectRoot);
};

