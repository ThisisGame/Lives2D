#pragma once
#include "Renderer.h"
#include<vector>
#include<map>
#include"glm/glm.hpp"

class SkinMeshRenderer :
	public Renderer
{
	DECLEAR_DYNCRT_ACTION(SkinMeshRenderer)

public:
	SkinMeshRenderer();
	~SkinMeshRenderer();

	void InitWithXml(TiXmlElement* varTiXmlElement) override;

private:
	void LoadAnim(const char* varAnimPath);

public:
	void Update() override;


private:
	std::vector<std::string> mVectorBoneName;

	std::vector<glm::mat4x4> mVectorBoneMatrixInvert;

	std::map<int, vector<glm::mat4x4>> mMapBoneMatrix;

	std::vector<std::map<unsigned short, float>> mVectorWeight;
};

