#pragma once

class TiXmlElement;
class GameObject;
class SkinMeshParser
{
public:
	SkinMeshParser();
	~SkinMeshParser();

	GameObject* CreateScene(const char* varFilePath);

private:
	void RecursiveNode(TiXmlElement* varTiXmlElementRoot, GameObject* varGameObjectRoot);
};

