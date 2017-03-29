#pragma once
#include "CCTexture.h"
#include "CCEngine.h"

class CCImage
{
public:
	CCImage(void);
	~CCImage(void);

public:

	//…Ë÷√Õº∆¨¬∑æ∂
	void SetImageFile(const string filename);


	void DrawImage(float x,float y,float w,float h);

	void DrawImage(float x,float y,float w,float h,int z);

private:

	string m_imageFileName;

	GLuint m_textureId;
};

