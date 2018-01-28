#pragma once

#include"GUI/UIDrawRect.h"

#include<vector>
#include"GUI/UIImage.h"

#include"ImageAnimationClip.h"

class ImageAnimation:public UIDrawRect
{
private:
	std::vector<ImageAnimationClip*> mVectorImageAnimationClip;

	ImageAnimationClip* mCurrentPlayClip;

	bool mPlay;

	float mPosX;
	float mPosY;
	float mScaleX;
	float mScaleY;

public:
	ImageAnimation(std::string varConfigPath,float varSpeed);
	~ImageAnimation();

	void Update(float varDeltaTime) override final;

	void Draw() override final;

	void Play(std::string varClipName);

	//设置位置
	void SetPosition(float varPosX, float varPosY);

	//设置缩放
	void SetScale(float varScaleX, float varScaleY);
};

