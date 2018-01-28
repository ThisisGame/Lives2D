#pragma once

#include"GLProgram/GLProgram_Texture.h"
#include"GLProgram/GLProgram_Texture_ReceiveLightEffect.h"
#include"Texture2D/Texture2D.h"
#include"GUI/UIDrawRect.h"


class UIImage:public UIDrawRect
{
	DECLEAR_DYNCRT_ACTION(UIImage)
public:
	UIImage(void);
	~UIImage(void);

public:
	void  Init(const char* varFilePath); //加载图片，生成Texture;

	//是否接受灯光影响,在Init之前调用，根据这个参数选择不同的Shader来创建UIImage
	void Init(const char* varFilePath, bool varReceiveLightEffect);

	//绘制
	void Draw() override;


	//设置位置
	void SetPosition(float varPosX, float varPosY);


	//设置缩放
	void SetScale(float varScaleX, float varScaleY);

private:
	GLProgram_Texture* mGLProgram;
	Texture2D* mTexture2D;


	bool mReceiveLightEffect;///是否接受灯光影响
public:
	float mPosX;
	float mPosY;
	float mScaleX;
	float mScaleY;
};

