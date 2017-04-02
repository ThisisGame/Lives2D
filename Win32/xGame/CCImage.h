#pragma once

#include"shader\GLProgram_Texture.h"
#include"Texture2D\Texture2D.h"

class CCImage
{
public:
	CCImage(void);
	~CCImage(void);

public:
	void  Init(const char* varFilePath); //º”‘ÿÕº∆¨£¨…˙≥…Texture;

	void Draw(float varX,float varY);

private:
	GLProgram_Texture m_GLProgram;
	Texture2D* mTexture2D;
};

