#include "UIImage.h"

#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtx/transform2.hpp>
#include<glm/gtx/euler_angles.hpp>
#include"Tools/Application.h"
#include"Component/Transform.h"

IMPLEMENT_DYNCRT_ACTION(UIImage)
UIImage::UIImage(void):UIDrawRect(),mPosX(0),mPosY(0),mScaleX(1),mScaleY(1),mReceiveLightEffect(false)
{
	mTexture2D = new Texture2D();
}




UIImage::~UIImage(void)
{
}

void UIImage::InitWithXml(TiXmlElement * varTiXmlElement)
{
	const char* tmpFilePath = varTiXmlElement->Attribute("Image");

	Init(Application::GetFullPath(tmpFilePath));
}

void UIImage::Init(const char * varFilePath)
{
	if (mReceiveLightEffect)
	{
		mGLProgram = new GLProgram_Texture_ReceiveLightEffect();
	}
	else
	{
		mGLProgram = new GLProgram_Texture();
	}
	mGLProgram->Initialize();
	mTexture2D->LoadTexture(varFilePath);
}

void UIImage::Init(const char * varFilePath, bool varReceiveLightEffect)
{
	mReceiveLightEffect = varReceiveLightEffect;

	Init(varFilePath);
}

void UIImage::SetPosition(float varPosX, float varPosY)
{
	mPosX = varPosX;
	mPosY = varPosY;
}

void UIImage::SetScale(float varScaleX, float varScaleY)
{
	mScaleX = varScaleX;
	mScaleY = varScaleY;
}



void UIImage::Draw()
{
	//关联绑定这个纹理ID;
	glBindTexture(GL_TEXTURE_2D, mTexture2D->m_textureId);
	
	//glm::mat4 trans = glm::translate(glm::vec3(mPosX, mPosY, 0));
	glm::mat4 trans = glm::translate(glm::vec3(mTransform->GetPosition().mX, mTransform->GetPosition().mY, 0));
	glm::mat4 rotation = glm::eulerAngleYXZ(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f));
	glm::mat4 scale = glm::scale(glm::vec3(mScaleX, mScaleY, 1.0f));

	//一定要先trans，然后再其它;先缩放，然后再移动，那么移动的位置也被缩放了。先移动再缩放就不会放大移动的位置;
	glm::mat4 model = trans*scale*rotation;

	//View
	glm::mat4 view = glm::lookAt(glm::vec3(0, 0, 10), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));


	//正交摄像机
	glm::mat4 proj = glm::ortho(-(float)Application::DesignWidth/2, (float)Application::DesignWidth /2, -(float)Application::DesignHeight/2, (float)Application::DesignHeight /2, 0.0f, 100.0f);


	glm::mat4 mvp = proj*view*model;


	mGLProgram->begin();
	{
		float tmpRectRight = (float)mTexture2D->mTextureWidth / 2;
		float tmpRectLeft = -tmpRectRight;
		float tmpRectTop = (float)mTexture2D->mTextureHeight / 2;
		float tmpRectBottom = -tmpRectTop;

		glm::vec3 pos[] =
		{
			glm::vec3(tmpRectLeft, tmpRectBottom, 0.0f),
			glm::vec3(tmpRectRight, tmpRectBottom, 0.0f),
			glm::vec3(tmpRectRight, tmpRectTop, 0.0f),

			glm::vec3(tmpRectLeft, tmpRectBottom, 0.0f),
			glm::vec3(tmpRectRight, tmpRectTop, 0.0f),
			glm::vec3(tmpRectLeft, tmpRectTop, 0.0f),
		};

		glm::vec2 uv[] =
		{
			//front
			glm::vec2(0, 0),
			glm::vec2(1, 0),
			glm::vec2(1, 1),

			glm::vec2(0, 0),
			glm::vec2(1, 1),
			glm::vec2(0, 1),
		};

		glm::vec4 color[] =
		{
			glm::vec4(1, 1, 1, 1),
			glm::vec4(1, 1, 1, 1),
			glm::vec4(1, 1, 1,1),

			glm::vec4(1, 1, 1, 1),
			glm::vec4(1, 1, 1, 1),
			glm::vec4(1, 1, 1, 1),
		};
        
		glUniformMatrix4fv(mGLProgram->m_mvp, 1, false, &mvp[0][0]);

		glVertexAttribPointer(mGLProgram->m_position, 3, GL_FLOAT, false, sizeof(glm::vec3), pos);
		glVertexAttribPointer(mGLProgram->m_uv, 2, GL_FLOAT, false, sizeof(glm::vec2), uv);
		glVertexAttribPointer(mGLProgram->m_color, 4, GL_FLOAT, false, sizeof(glm::vec4), color);

		if (mReceiveLightEffect)
		{
			glUniform3f(((GLProgram_Texture_ReceiveLightEffect*)mGLProgram)->m_position_Light, 0, 0,240.0);
			glUniform4f(((GLProgram_Texture_ReceiveLightEffect*)mGLProgram)->m_color_Light, 0.5, 0.0, 0.0, 1.0);

			glUniformMatrix4fv(((GLProgram_Texture_ReceiveLightEffect*)mGLProgram)->m_model_matrix,1,false,&model[0][0]);
		}

		glDrawArrays(GL_TRIANGLES, 0, 6);
	};
	mGLProgram->end();
}
