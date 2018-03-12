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

	void SetVertexAttribPointer(const char* varProperty, int varSize, int varStride, void* varMemoryData);

	void SetFloat(const char* varProperty, float varValue);
	

	void SetTexture(const char* varProperty, const char* varTexturePath);

	


private:
	Shader* mShader;

	Texture2D* mTexture2D;

	//��Ҫ�ü�ֵ�Դ洢���Ժ�ֵ
	std::vector<ShaderProperty*> mVectorShaderProperty;
};
