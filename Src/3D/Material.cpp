#include "Material.h"
#include"Tools/Application.h"


Material::Material()
{
	
}


Material::~Material()
{
}

void Material::InitWithXml(TiXmlElement * varTiXmlElement)
{
	const char* tmpShaderName = varTiXmlElement->Attribute("Shader");
	const char* tmpTextureFilePath = varTiXmlElement->Attribute("Texture");

	mGLProgram_Texture = new GLProgram_Texture();
	mGLProgram_Texture->Initialize();
	mTexture2D->LoadTexture(Application::GetFullPath(tmpTextureFilePath));
}


void Material::Render()
{
	mGLProgram_Texture->begin();



	mGLProgram_Texture->end();
}



