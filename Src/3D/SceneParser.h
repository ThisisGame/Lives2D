#pragma once

class TiXmlElement;
class GameObject;
class SceneParser
{
public:
	SceneParser();
	~SceneParser();

	GameObject* CreateScene(const char* varFilePath);

private:
	void RecursiveNode(TiXmlElement* varTiXmlElementRoot, GameObject* varGameObjectRoot);
};

