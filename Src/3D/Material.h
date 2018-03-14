#pragma once
#include "Component/Component.h"

#include"GLProgram/Shader.h"

#include"Texture2D/Texture2D.h"

#include<vector>


class Material :
	public Component
{
	DECLEAR_DYNCRT_ACTION(Material)

public:
	Material();
	~Material();

	void InitWithXml(TiXmlElement* varTiXmlElement) override;

	void Render();

	void SetUniformMatrix4fv(const char* varProperty, int varSize, GLfloat* varMemoryData);

	void SetVertexAttribPointer(const char* varProperty, int varSize, int varStride, void* varMemoryData);

	void SetFloat(const char* varProperty, float varValue);
	

	void SetTexture(const char* varProperty, const char* varTexturePath);

	void SetVertexIndices(int varSize,unsigned short* varVertexIndices);

private:
	Shader* mShader;

	//需要用键值对存储属性和值
	std::vector<ShaderProperty*> mVectorShaderProperty;

	int mVertexIndicesSize;
	GLushort* mVertexIndices;
};

