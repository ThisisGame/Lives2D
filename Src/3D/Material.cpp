#include "Material.h"
#include"Tools/Application.h"
#include"PlayerPrefs/Convert.h"
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtx/transform2.hpp>
#include<glm/gtx/euler_angles.hpp>
#include"Component/Transform.h"

IMPLEMENT_DYNCRT_ACTION(Material)
Material::Material()
{
	
}


Material::~Material()
{
}

void Material::InitWithXml(TiXmlElement * varTiXmlElement)
{
	const char* tmpShaderName = varTiXmlElement->Attribute("Shader");
	mShader = new Shader();

	const char* tmpVertexShaderPath = Application::GetFullPathWithExtension(tmpShaderName,".vert");
	const char* tmpFragShaderPath = Application::GetFullPathWithExtension(tmpShaderName,".frag");
	bool tmpRet=mShader->CreateProgram(Helper::ReadTxt(tmpVertexShaderPath).c_str(), Helper::ReadTxt(tmpFragShaderPath).c_str());
	if (tmpRet == false)
	{
		Helper::LOG("Material::InitWithXml CreateProgram %s Failed",tmpShaderName);
		return;
	}

	TiXmlNode *tmpTiXmlNode = NULL;

	for (tmpTiXmlNode = varTiXmlElement->FirstChildElement(); tmpTiXmlNode != NULL; tmpTiXmlNode = tmpTiXmlNode->NextSiblingElement())
	{
		TiXmlElement* tmpTiXmlElement = tmpTiXmlNode->ToElement();
		const char* tmpNodeName = tmpTiXmlElement->Value();
		if (strcmp(tmpNodeName, "ShaderProperty") == 0)
		{
			const char* tmpShaderPropertyName= tmpTiXmlElement->Attribute("Name");
			const char* tmpShaderPropertyValueType = tmpTiXmlElement->Attribute("ValueType");
			

            ShaderProperty* tmpShaderProperty=nullptr;
            if (strcmp(tmpShaderPropertyValueType, ShaderPropertyValueType::TYPE_FLOAT) == 0)
			{
                tmpShaderProperty = new ShaderPropertyFloat();
                ShaderPropertyFloat* tmpShaderPropertyFloat=(ShaderPropertyFloat*)tmpShaderProperty;

				const char* tmpShaderPropertyValue = tmpTiXmlElement->Attribute("Value");
				tmpShaderPropertyFloat->mValue = Convert::StringToFloat(tmpShaderPropertyValue);
			}
            else if (strcmp(tmpShaderPropertyValueType, ShaderPropertyValueType::TYPE_INT) == 0)
            {
                tmpShaderProperty=new ShaderPropertyInt();
                ShaderPropertyInt* tmpShaderPropertyInt=(ShaderPropertyInt*)tmpShaderProperty;

				const char* tmpShaderPropertyValue = tmpTiXmlElement->Attribute("Value");
                tmpShaderPropertyInt->mValue=Convert::StringToInt(tmpShaderPropertyValue);
            }
            else if (strcmp(tmpShaderPropertyValueType, ShaderPropertyValueType::TYPE_TEXTURE) == 0)
            {
                tmpShaderProperty=new ShaderPropertyTexture();
                ShaderPropertyTexture* tmpShaderPropertyTexture=(ShaderPropertyTexture*)tmpShaderProperty;

				tmpShaderPropertyTexture->mID= glGetUniformLocation(mShader->mProgram, tmpShaderPropertyName);
                
                tmpShaderPropertyTexture->mActiveTextureIndex=Convert::StringToInt(tmpTiXmlElement->Attribute("ActiveTextureIndex"));
                
                const char* tmpTexturePath=tmpTiXmlElement->Attribute("TexturePath");
                tmpShaderPropertyTexture->mTexturePath=tmpTexturePath;
                
                Texture2D* tmpTexture2D=new Texture2D();
                tmpTexture2D->LoadTexture(Application::GetFullPath(tmpTexturePath));
                tmpShaderPropertyTexture->mTextureID=tmpTexture2D->m_textureId;
            }
			else if (strcmp(tmpShaderPropertyValueType, ShaderPropertyValueType::TYPE_UNIFORM_MATRIX4FV) == 0)
			{
				tmpShaderProperty = new ShaderPropertyUniformMatrix4fv();
				ShaderPropertyUniformMatrix4fv* tmpShaderPropertyUniformMatrix4fv = (ShaderPropertyUniformMatrix4fv*)tmpShaderProperty;

				tmpShaderPropertyUniformMatrix4fv->mID= glGetUniformLocation(mShader->mProgram, tmpShaderPropertyName);
			}
			else if (strcmp(tmpShaderPropertyValueType, ShaderPropertyValueType::TYPE_VERTEXATTRIBPOINT) == 0)
			{
				tmpShaderProperty = new ShaderPropertyVertexAttribPointer();
				ShaderPropertyVertexAttribPointer* tmpShaderPropertyVertexAttribPointer = (ShaderPropertyVertexAttribPointer*)tmpShaderProperty;

				tmpShaderPropertyVertexAttribPointer->mID = glGetAttribLocation(mShader->mProgram, tmpShaderPropertyName);
			}
            tmpShaderProperty->mName = tmpShaderPropertyName;
            tmpShaderProperty->mValueType = tmpShaderPropertyValueType;
            mVectorShaderProperty.push_back(tmpShaderProperty);
		}
	}

}

void Material::SetUniformMatrix4fv(const char * varProperty, int varSize, GLfloat* varMemoryData)
{
	bool tmpFind = false;
	for (size_t tmpIndex = 0; tmpIndex<mVectorShaderProperty.size(); tmpIndex++)
	{
		if (strcmp(mVectorShaderProperty[tmpIndex]->mName, varProperty) == 0)
		{
			ShaderPropertyUniformMatrix4fv* tmpShaderPropertyUniformMatrix4fv = (ShaderPropertyUniformMatrix4fv*)mVectorShaderProperty[tmpIndex];
			tmpShaderPropertyUniformMatrix4fv->mSize = varSize;
			tmpShaderPropertyUniformMatrix4fv->mMemoryData = varMemoryData;
			tmpFind = true;
			break;
		}
	}

	if (tmpFind == false)
	{
		ShaderPropertyUniformMatrix4fv* tmpShaderPropertyUniformMatrix4fv = new ShaderPropertyUniformMatrix4fv();
		tmpShaderPropertyUniformMatrix4fv->mName = varProperty;
		tmpShaderPropertyUniformMatrix4fv->mSize = varSize;
		tmpShaderPropertyUniformMatrix4fv->mMemoryData = varMemoryData;
		mVectorShaderProperty.push_back(tmpShaderPropertyUniformMatrix4fv);
	}
}

void Material::SetVertexAttribPointer(const char * varProperty, int varSize, int varStride, void * varMemoryData)
{
	bool tmpFind = false;

	ShaderPropertyVertexAttribPointer* tmpShaderPropertyVertexAttribPointer = nullptr;

	GLint tmpID= glGetAttribLocation(mShader->mProgram, varProperty);

	for (size_t tmpIndex = 0; tmpIndex<mVectorShaderProperty.size(); tmpIndex++)
	{
		if (strcmp(mVectorShaderProperty[tmpIndex]->mName, varProperty) == 0)
		{
			tmpShaderPropertyVertexAttribPointer = (ShaderPropertyVertexAttribPointer*)mVectorShaderProperty[tmpIndex];
			tmpFind = true;
			break;
		}
	}

	if (tmpFind == false)
	{
		tmpShaderPropertyVertexAttribPointer = new ShaderPropertyVertexAttribPointer();
		tmpShaderPropertyVertexAttribPointer->mName = varProperty;
		mVectorShaderProperty.push_back(tmpShaderPropertyVertexAttribPointer);
	}

	tmpShaderPropertyVertexAttribPointer->mSize = varSize;
	tmpShaderPropertyVertexAttribPointer->mStride = varStride;
	tmpShaderPropertyVertexAttribPointer->mMemoryData = varMemoryData;
	tmpShaderPropertyVertexAttribPointer->mID = tmpID;
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
		mVectorShaderProperty.push_back(tmpShaderPropertyFloat);
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
	glm::mat4 trans = glm::translate(glm::vec3(mTransform->GetPosition().mX, mTransform->GetPosition().mY, mTransform->GetPosition().mZ));
	glm::mat4 rotation = glm::eulerAngleYXZ(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f));
	glm::mat4 scale = glm::scale(glm::vec3(100.0f, 100.0f, 100.0f));
	glm::mat4 model = trans*scale*rotation;

	glm::mat4 view = glm::lookAt(glm::vec3(0, 0, 10), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	//正交摄像机
	glm::mat4 proj = glm::ortho(-(float)Application::DesignWidth / 2, (float)Application::DesignWidth / 2, -(float)Application::DesignHeight / 2, (float)Application::DesignHeight / 2, 0.0f, 100.0f);


	glm::mat4 mvp = proj*view*model;

	SetUniformMatrix4fv("m_mvp", 1, &mvp[0][0]);

	mShader->begin();


    //设置 Shader属性
	for (size_t tmpShaderPropertyIndex = 0; tmpShaderPropertyIndex < mVectorShaderProperty.size(); tmpShaderPropertyIndex++)
	{
		ShaderProperty* tmpShaderProperty = mVectorShaderProperty[tmpShaderPropertyIndex];
		if (strcmp(tmpShaderProperty->mValueType,ShaderPropertyValueType::TYPE_FLOAT)==0)
		{

		}
		else if (strcmp(tmpShaderProperty->mValueType,ShaderPropertyValueType::TYPE_INT)==0)
		{

		}
		else if (strcmp(tmpShaderProperty->mValueType,ShaderPropertyValueType::TYPE_UNIFORM_MATRIX4FV)==0)
		{
			ShaderPropertyUniformMatrix4fv* tmpShaderPropertyUniformMatrix4fv = (ShaderPropertyUniformMatrix4fv*)tmpShaderProperty;
			glUniformMatrix4fv(tmpShaderProperty->mID, tmpShaderPropertyUniformMatrix4fv->mSize, false, tmpShaderPropertyUniformMatrix4fv->mMemoryData);
		}
		else if (strcmp(tmpShaderProperty->mValueType , ShaderPropertyValueType::TYPE_TEXTURE)==0)
		{
			ShaderPropertyTexture* tmpShaderPropertyTexture = (ShaderPropertyTexture*)tmpShaderProperty;
			glUniform1i(tmpShaderPropertyTexture->mID, tmpShaderPropertyTexture->mActiveTextureIndex);
			glActiveTexture(GL_TEXTURE0 + tmpShaderPropertyTexture->mActiveTextureIndex);
			glBindTexture(GL_TEXTURE_2D, tmpShaderPropertyTexture->mTextureID);
		}
		else if (strcmp(tmpShaderProperty->mValueType ,ShaderPropertyValueType::TYPE_VERTEXATTRIBPOINT)==0)
		{
			ShaderPropertyVertexAttribPointer* tmpShaderPropertyVertexAttribPointer = (ShaderPropertyVertexAttribPointer*)tmpShaderProperty;

			glEnableVertexAttribArray(tmpShaderPropertyVertexAttribPointer->mID);
			glVertexAttribPointer(tmpShaderProperty->mID, tmpShaderPropertyVertexAttribPointer->mSize, GL_FLOAT, false, tmpShaderPropertyVertexAttribPointer->mStride, tmpShaderPropertyVertexAttribPointer->mMemoryData);
		}
	}

	glDrawArrays(GL_TRIANGLES, 0, 6);


	for (size_t tmpShaderPropertyIndex = 0; tmpShaderPropertyIndex < mVectorShaderProperty.size(); tmpShaderPropertyIndex++)
	{
		ShaderProperty* tmpShaderProperty = mVectorShaderProperty[tmpShaderPropertyIndex];
		if (strcmp(tmpShaderProperty->mValueType ,ShaderPropertyValueType::TYPE_VERTEXATTRIBPOINT)==0)
		{
			ShaderPropertyVertexAttribPointer* tmpShaderPropertyVertexAttribPointer = (ShaderPropertyVertexAttribPointer*)tmpShaderProperty;

			glDisableVertexAttribArray(tmpShaderPropertyVertexAttribPointer->mID);
		}
	}

	mShader->end();
}





