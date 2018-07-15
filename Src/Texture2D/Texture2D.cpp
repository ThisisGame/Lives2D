#include "Texture2D.h"
#include"./Tools/Helper.h"
#include"stb_image.h"

Texture2D::Texture2D():m_textureId(-1),m_imageFilePath("")
{
	
}

void Texture2D::LoadTexture(const char* varFilePath)
{
	//Helper::LOG("Texture2D::LoadTexture %s", varFilePath);

	m_imageFilePath = std::string(varFilePath);

	stbi_set_flip_vertically_on_load(true);
	int tmpComponents;
	unsigned char* data = stbi_load(varFilePath, &mTextureWidth, &mTextureHeight, &tmpComponents, 0);
	if (data)
	{
		GLenum format;
		if (tmpComponents == 1)
			format = GL_ALPHA;
		else if (tmpComponents == 3)
			format = GL_RGB;
		else if (tmpComponents == 4)
			format = GL_RGBA;

		//1、产生一个纹理ID;
		glGenTextures(1, &m_textureId);

		//2、关联绑定这个纹理ID;
		glBindTexture(GL_TEXTURE_2D, m_textureId);

		//3、指定放大，缩小滤波方式，线性滤波，即放大缩小的插值方式;
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		// set texture filtering parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		//将图片rgb数据上传到OpenGL,在这一步才把数据从内存Copy到显存;
		glTexImage2D(GL_TEXTURE_2D, 0, format, mTextureWidth, mTextureHeight, 0, format, GL_UNSIGNED_BYTE, data);
	}
	else
	{
		Helper::LOG("Failed to load texture %s",varFilePath);
	}

	stbi_image_free(data);
}


Texture2D::~Texture2D()
{
}
