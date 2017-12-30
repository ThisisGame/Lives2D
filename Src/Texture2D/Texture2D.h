#pragma once
#include"FreeImage.h"

#if IOS
#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>
#else
#include<gles2/gl2.h>

#endif
#include<string>

class Texture2D
{
public:
	Texture2D();
	~Texture2D();

public:
	std::string m_imageFilePath;//文件路径;
	GLuint m_textureId;

	int mTextureWidth;
	int mTextureHeight;

public:
	void  LoadTexture(const char* varFilePath); //加载图片，生成Texture;
};

