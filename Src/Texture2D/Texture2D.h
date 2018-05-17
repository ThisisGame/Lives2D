#pragma once


#if IOS
#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>
#elif ANDROID
#include<egl\egl.h>
#include<gles2\gl2.h>
#else
#include<glad/glad.h>
#endif
#include<string>
#include"FreeImage.h"

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

