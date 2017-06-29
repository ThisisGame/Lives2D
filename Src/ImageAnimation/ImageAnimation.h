#pragma once

#include"GUI\UIDrawRect.h"

#include<vector>
#include"Image\Image.h"

#include"ImageAnimationClip.h"

class ImageAnimation:public UIDrawRect
{
private:
	std::vector<ImageAnimationClip*> mVectorImageAnimationClip;

	ImageAnimationClip* mCurrentPlayClip;

	bool mPlay;

public:
	ImageAnimation(std::string varConfigPath,float varSpeed);
	~ImageAnimation();

	void Update(float varDeltaTime) override final;

	void Draw() override final;

	void Play(std::string varClipName);
};

