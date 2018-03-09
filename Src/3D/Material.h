#pragma once
#include "Component/Component.h"

#include"GLProgram/Shader.h"

#include"Texture2D/Texture2D.h"

#include<vector>


class Material :
	public Component
{
public:
	Material();
	~Material();

	void InitWithXml(TiXmlElement* varTiXmlElement) override;

	void Render();


	void SetFloat(const char* varProperty, float varValue);
	void SetFloat3(const char* varProperty, float varX, float varY, float varZ);
	void SetFloat4(const char* varProperty, float varX, float varY, float varZ,float varW);

	void SetTexture(const char* varProperty, GLuint varTexture);

	


private:
	Shader* mShader;

	Texture2D* mTexture2D;

	//需要用键值对存储属性和值
	std::vector<ShaderProperty*> mVectorShaderProperty;
};

