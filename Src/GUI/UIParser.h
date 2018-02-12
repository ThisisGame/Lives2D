#pragma once

class TiXmlElement;
class GameObject;
class UIRoot;
class UIParser
{
public:
	UIParser();
	~UIParser();

	UIRoot* CreateUI(const char* varFilePath);

private:
	void RecursiveNode(TiXmlElement* varTiXmlElementRoot, GameObject* varGameObjectRoot);

private:
	UIRoot* mUIRoot;
};

