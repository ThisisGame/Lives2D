#pragma once

#include<iostream>
#include"Helper.h"
#include"png.h"

class CCTexture
{
public:
	CCTexture(void);
	~CCTexture(void);

	///从Png文件创建Texture
	static GLuint CreateTextureFromPng(const char* filename);



private:
	GLuint m_TextureID;
	
};
