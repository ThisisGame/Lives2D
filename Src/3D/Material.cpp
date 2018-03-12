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

            ShaderProperty* tmpShaderProperty=nullptr;
            if (strcmp(tmpShaderPropertyValueType, ShaderPropertyValueType::TYPE_FLOAT) == 0)
			{
                tmpShaderProperty = new ShaderPropertyFloat();
                ShaderPropertyFloat* tmpShaderPropertyFloat=(ShaderPropertyFloat*)tmpShaderProperty;
				tmpShaderPropertyFloat->mValue = Convert::StringToFloat(tmpShaderPropertyValue);
			}
            else if (strcmp(tmpShaderPropertyValueType, ShaderPropertyValueType::TYPE_INT) == 0)
            {
                tmpShaderProperty=new ShaderPropertyInt();
                ShaderPropertyInt* tmpShaderPropertyInt=(ShaderPropertyInt*)tmpShaderProperty;
                tmpShaderPropertyInt->mValue=Convert::StringToInt(tmpShaderPropertyValue);
            }
            else if (strcmp(tmpShaderPropertyValueType, ShaderPropertyValueType::TYPE_TEXTURE) == 0)
            {
                tmpShaderProperty=new ShaderPropertyTexture();
                ShaderPropertyTexture* tmpShaderPropertyTexture=(ShaderPropertyTexture*)tmpShaderProperty;
                
                tmpShaderPropertyTexture->mActiveTextureIndex=Convert::StringToInt(tmpTiXmlElement->Attribute("ActiveTextureIndex"));
                
                const char* tmpTexturePath=tmpTiXmlElement->Attribute("TexturePath");
                tmpShaderPropertyTexture->mTexturePath=tmpTexturePath;
                
                Texture2D* tmpTexture2D=new Texture2D();
                tmpTexture2D->LoadTexture(Application::GetFullPath(tmpTexturePath));
                tmpShaderPropertyTexture->mTextureID=tmpTexture2D->m_textureId;
            }
            tmpShaderProperty->mName = tmpShaderPropertyName;
            tmpShaderProperty->mValueType = tmpShaderPropertyValueType;
            mVectorShaderProperty.push_back(tmpShaderProperty);
		}
	}

}


void Material::SetVertexAttribPointer(const char * varProperty, int varSize, int varStride, void * varMemoryData)
{
	bool tmpFind = false;
	for (size_t tmpIndex = 0; tmpIndex<mVectorShaderProperty.size(); tmpIndex++)
	{
		if (strcmp(mVectorShaderProperty[tmpIndex]->mName, varProperty) == 0)
		{
			ShaderPropertyVertexAttribPointer* tmpShaderPropertyVertexAttribPointer = (ShaderPropertyVertexAttribPointer*)mVectorShaderProperty[tmpIndex];
			tmpShaderPropertyVertexAttribPointer->mSize = varSize;
			tmpShaderPropertyVertexAttribPointer->mStride = varStride;
			tmpShaderPropertyVertexAttribPointer->mMemoryData = varMemoryData;

			tmpFind = true;
			break;
		}
	}

	if (tmpFind == false)
	{
		ShaderPropertyVertexAttribPointer* tmpShaderPropertyVertexAttribPointer = new ShaderPropertyVertexAttribPointer();
		tmpShaderPropertyVertexAttribPointer->mName = varProperty;
		tmpShaderPropertyVertexAttribPointer->mSize = varSize;
		tmpShaderPropertyVertexAttribPointer->mStride = varStride;
		tmpShaderPropertyVertexAttribPointer->mMemoryData = varMemoryData;
	}
}

void Material::SetFloat(const char* varProperty, float varValue)
{
    bool tmpFind=false;
    for (size_t tmpIndex=0; tmpIndex<mVectorShaderProperty.size(); tmpIndex++)
    {
        if(strcmp( mVectorShaderProperty[tmpIndex]->mName,varProperty)==0)
        {
            ShaderPropertyFloat* tmpShaderPropertyFloat=(ShaderPropertyFloat*) mVectorShaderProperty[tmpIndex];
            tmpShaderPropertyFloat->mValue=varValue;
            
            tmpFind=true;
            break;
        }
    }
    
    if(tmpFind==false)
    {
        ShaderPropertyFloat* tmpShaderPropertyFloat=new ShaderPropertyFloat();
        tmpShaderPropertyFloat->mName=varProperty;
        tmpShaderPropertyFloat->mValue=varValue;
    }
}

void Material::SetTexture(const char* varProperty, const char* varTexturePath)
{
    bool tmpFind=false;
    for (size_t tmpIndex=0; tmpIndex<mVectorShaderProperty.size(); tmpIndex++)
    {
        if(strcmp( mVectorShaderProperty[tmpIndex]->mName,varProperty)==0)
        {
            ShaderPropertyTexture* tmpShaderPropertyTexture=(ShaderPropertyTexture*) mVectorShaderProperty[tmpIndex];
            
            //build texture
            Texture2D* tmpTexture2D=new Texture2D();
            tmpTexture2D->LoadTexture(Application::GetFullPath(varTexturePath));
            tmpShaderPropertyTexture->mTextureID=tmpTexture2D->m_textureId;
            
            
            tmpFind=true;
            
            break;
        }
    }
    
    if(tmpFind==false)
    {
        ShaderPropertyTexture* tmpShaderPropertyTexture=new ShaderPropertyTexture();
        tmpShaderPropertyTexture->mName=varProperty;
        
        //get which GL_TEXTURE can bind
        int tmpActiveTextureIndex=0;
        for (size_t tmpIndex=0; tmpIndex<mVectorShaderProperty.size(); tmpIndex++)
        {
            if(strcmp( mVectorShaderProperty[tmpIndex]->mValueType,ShaderPropertyValueType::TYPE_TEXTURE)==0)
            {
                tmpActiveTextureIndex++;
            }
        }
        
        tmpShaderPropertyTexture->mActiveTextureIndex=tmpActiveTextureIndex;
        tmpShaderPropertyTexture->mTexturePath=varTexturePath;
        
        //build texture
        Texture2D* tmpTexture2D=new Texture2D();
        tmpTexture2D->LoadTexture(Application::GetFullPath(varTexturePath));
        tmpShaderPropertyTexture->mTextureID=tmpTexture2D->m_textureId;
        
        mVectorShaderProperty.push_back(tmpShaderPropertyTexture);
    }
}


void Material::Render()
{
	mShader->begin();

    //…Ë÷√ Shader Ù–‘
	for (size_t tmpShaderPropertyIndex = 0; tmpShaderPropertyIndex < mVectorShaderProperty.size(); tmpShaderPropertyIndex++)
	{
		ShaderProperty* tmpShaderProperty = mVectorShaderProperty[tmpShaderPropertyIndex];
		if (tmpShaderProperty->mValueType == ShaderPropertyValueType::TYPE_FLOAT)
		{

		}
		else if (tmpShaderProperty->mValueType == ShaderPropertyValueType::TYPE_INT)
		{

		}
		else if (tmpShaderProperty->mValueType == ShaderPropertyValueType::TYPE_TEXTURE)
		{

		}
		else if (tmpShaderProperty->mValueType == ShaderPropertyValueType::TYPE_VERTEXATTRIBPOINT)
		{
			ShaderPropertyVertexAttribPointer* tmpShaderPropertyVertexAttribPointer = (ShaderPropertyVertexAttribPointer*)tmpShaderProperty;
			glVertexAttribPointer(tmpShaderProperty->mID, tmpShaderPropertyVertexAttribPointer->mSize, GL_FLOAT, false, tmpShaderPropertyVertexAttribPointer->mStride, tmpShaderPropertyVertexAttribPointer->mMemoryData);
		}
	}


	mShader->end();
}



