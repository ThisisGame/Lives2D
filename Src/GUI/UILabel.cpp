#include"UILabel.h"
#include"Tools\Application.h"
#include<string>
#include<glm\glm.hpp>
#include<glm\gtc\matrix_transform.hpp>
#include<glm\gtx\transform2.hpp>
#include<glm\gtx\euler_angles.hpp>
#include"FontManager.h"

UILabel::UILabel():mPosX(0), mPosY(0), mScaleX(1), mScaleY(1), mSpace(2),mAlignCenter(true)
{

}

UILabel::~UILabel()
{
}

void UILabel::Init(const char* varText)
{
	mFont= FontManager::GetSingleton()->BuildFont("/Resources/Font/msyh.ttf");

	m_GLProgram_Font.Initialize();

	//首次调用，生成一个GLTexture，然后绑定使用;
	//glGenTextures(1, &m_fontTexture);
	m_fontTexture = mFont->m_fontTexture;

	mText = varText;
}

void UILabel::Draw()
{
	glBindTexture(GL_TEXTURE_2D, m_fontTexture);

	//指定放大缩小滤波，使用线性方式，即图片放大时插值方式;
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	//产生Texture2d;
	glTexImage2D(
		GL_TEXTURE_2D,
		0,
		GL_ALPHA,
		1024,
		1024,
		0,
		GL_ALPHA,
		GL_UNSIGNED_BYTE,
		0);

	glm::mat4 trans = glm::translate(glm::vec3(mPosX, mPosY, 0));
	glm::mat4 rotation = glm::eulerAngleYXZ(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f));
	glm::mat4 scale = glm::scale(glm::vec3(mScaleX, mScaleY, 1.0f));

	//一定要先trans，然后再其它;先缩放，然后再移动，那么移动的位置也被缩放了。先移动再缩放就不会放大移动的位置;
	glm::mat4 model = trans*scale*rotation;

	//View
	glm::mat4 view = glm::lookAt(glm::vec3(0, 0, 10), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));


	//正交摄像机
	glm::mat4 proj = glm::ortho(-(float)Application::DesignWidth / 2, (float)Application::DesignWidth / 2, -(float)Application::DesignHeight / 2, (float)Application::DesignHeight / 2, 0.0f, 100.0f);


	glm::mat4 mvp = proj*view*model;


	glBindTexture(GL_TEXTURE_2D, m_fontTexture);

	m_GLProgram_Font.begin();
	{
		glUniformMatrix4fv(m_GLProgram_Font.getMVPUniform(), 1, false, &mvp[0][0]);
		glUniform1i(m_GLProgram_Font.getTextureUniform(), 0);

		int length = strlen(mText.c_str());


		UIVertex* vert = mFont->GetUIVertex(0, 0, 0, RGBA_4_BYTE(0, 0, 0,255), mText.c_str(),mSpace,m_fontTexture,mAlignCenter);

		glVertexAttribPointer(m_GLProgram_Font.getPositionAttribute(), 3, GL_FLOAT, GL_FALSE, sizeof(UIVertex), vert);
		glVertexAttribPointer(m_GLProgram_Font.getUVAttribute(), 3, GL_FLOAT, GL_FALSE, sizeof(UIVertex), &vert[0].u);
		glVertexAttribPointer(m_GLProgram_Font.getColorAttribute(), 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(UIVertex), &vert[0].color);
		glDrawArrays(GL_TRIANGLES, 0, length * 6);
	}

	m_GLProgram_Font.end();
}

void UILabel::SetPosition(float varPosX, float varPosY)
{
	mPosX = varPosX;
	mPosY = varPosY;
}

void UILabel::SetScale(float varScaleX, float varScaleY)
{
}

void UILabel::SetSpace(int varSpace)
{
	mSpace = varSpace;
}

void UILabel::SetAlignCenter(bool varAlignCenter)
{
	mAlignCenter = varAlignCenter;
}
