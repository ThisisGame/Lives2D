#include "Image.h"

#include<glm\glm.hpp>
#include<glm\gtc\matrix_transform.hpp>
#include<glm\gtx\transform2.hpp>
#include<glm\gtx\euler_angles.hpp>
#include"Tools\Application.h"


Image::Image(void):UIDrawRect(),mPosX(0),mPosY(0),mScaleX(1),mScaleY(1)
{
	mTexture2D = new Texture2D();
}




Image::~Image(void)
{
}

void Image::Init(const char * varFilePath)
{
	m_GLProgram.Initialize();
	mTexture2D->LoadTexture(varFilePath);
}

void Image::SetPosition(float varPosX, float varPosY)
{
	mPosX = varPosX;
	mPosY = varPosY;
}

void Image::SetScale(float varScaleX, float varScaleY)
{
	mScaleX = varScaleX;
	mScaleY = varScaleY;
}

void Image::Draw()
{
	//关联绑定这个纹理ID;
	glBindTexture(GL_TEXTURE_2D, mTexture2D->m_textureId);

	glm::mat4 trans = glm::translate(glm::vec3(mPosX, mPosY, 0));
	glm::mat4 rotation = glm::eulerAngleYXZ(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f));
	glm::mat4 scale = glm::scale(glm::vec3(mScaleX, mScaleY, 1.0f));

	//一定要先trans，然后再其它;先缩放，然后再移动，那么移动的位置也被缩放了。先移动再缩放就不会放大移动的位置;
	glm::mat4 model = trans*scale*rotation;

	//View
	glm::mat4 view = glm::lookAt(glm::vec3(0, 0, 10), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));


	//正交摄像机
	glm::mat4 proj = glm::ortho(-(float)Application::DesignWidth/2, (float)Application::DesignWidth /2, -(float)Application::DesignHeight/2, (float)Application::DesignHeight /2, 0.0f, 100.0f);


	glm::mat4 mvp = proj*view*model;

	m_GLProgram.begin();
	{
		float tmpRectRight = (float)mTexture2D->mTextureWidth / 2;
		float tmpRectLeft = -tmpRectRight;
		float tmpRectTop = (float)mTexture2D->mTextureHeight / 2;
		float tmpRectBottom = -tmpRectTop;

		glm::vec3 pos[] =
		{
			glm::vec3(tmpRectLeft, tmpRectBottom, 1.0f),
			glm::vec3(tmpRectRight, tmpRectBottom, 1.0f),
			glm::vec3(tmpRectRight, tmpRectTop, 1.0f),

			glm::vec3(tmpRectLeft, tmpRectBottom, 1.0f),
			glm::vec3(tmpRectRight, tmpRectTop, 1.0f),
			glm::vec3(tmpRectLeft, tmpRectTop, 1.0f),
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

		glUniformMatrix4fv(m_GLProgram.m_mvp, 1, false, &mvp[0][0]);

		glVertexAttribPointer(m_GLProgram.m_position, 3, GL_FLOAT, false, sizeof(glm::vec3), pos);
		glVertexAttribPointer(m_GLProgram.m_uv, 2, GL_FLOAT, false, sizeof(glm::vec2), uv);
		glVertexAttribPointer(m_GLProgram.m_color, 4, GL_FLOAT, false, sizeof(glm::vec4), color);


		glDrawArrays(GL_TRIANGLES, 0, 6);
	};
	m_GLProgram.end();
}
