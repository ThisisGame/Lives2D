#include "Material.h"
#include"Tools/Application.h"
#include"PlayerPrefs/Convert.h"

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

	mShader = new Shader();




	const char* tmpVertexShaderPath = Application::GetFullPathWithExtension(tmpShaderName,".vert");
	const char* tmpFragShaderPath = Application::GetFullPathWithExtension(tmpShaderName,".frag");
	bool tmpRet=mShader->CreateProgram(Helper::ReadTxt(tmpVertexShaderPath).c_str(), Helper::ReadTxt(tmpFragShaderPath).c_str());
	if (tmpRet == false)
	{
		Helper::LOG("Material::InitWithXml CreateProgram %s Failed",tmpShaderName);
		return;
	}
	mTexture2D->LoadTexture(Application::GetFullPath(tmpTextureFilePath));


	//从子节点解析Shader属性
	//遍历 KeyValuePair;
	TiXmlNode *tmpTiXmlNode = NULL;

	for (tmpTiXmlNode = varTiXmlElement->FirstChildElement(); tmpTiXmlNode != NULL; tmpTiXmlNode = tmpTiXmlNode->NextSiblingElement())
	{
		TiXmlElement* tmpTiXmlElement = tmpTiXmlNode->ToElement();
		const char* tmpNodeName = tmpTiXmlElement->Value();
		if (strcmp(tmpNodeName, "ShaderProperty") == 0)
		{
			const char* tmpShaderPropertyName= tmpTiXmlElement->Attribute("Name");
			const char* tmpShaderPropertyValueType = tmpTiXmlElement->Attribute("ValueType");
			const char* tmpShaderPropertyValue = tmpTiXmlElement->Attribute("Value");

			if (strcmp(tmpShaderPropertyValueType, "float") == 0)
			{
				ShaderPropertyFloat* tmpShaderProperty = new ShaderPropertyFloat();
				tmpShaderProperty->mName = tmpShaderPropertyName;
				tmpShaderProperty->mValueType = tmpShaderPropertyValueType;
				tmpShaderProperty->mValue = Convert::StringToFloat(tmpShaderPropertyValue);

				mVectorShaderProperty.push_back(tmpShaderProperty);
			}
		}
	}

}


void Material::Render()
{
	mGLProgram_Texture->begin();



	mGLProgram_Texture->end();
}



