#pragma once

class TiXmlElement;
class GameObject;
class SkinMeshParser
{
public:
	SkinMeshParser();
	~SkinMeshParser();

	GameObject* Create(const char* varFilePath);

private:
	void RecursiveNode(TiXmlElement* varTiXmlElementRoot, GameObject* varGameObjectRoot);
};

