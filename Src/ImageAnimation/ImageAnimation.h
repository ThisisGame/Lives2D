#pragma once

#include<vector>
#include"Image\Image.h"

#include"ImageAnimationClip.h"

class ImageAnimation
{
private:
	std::vector<ImageAnimationClip*> mVectorImageAnimationClip;

	ImageAnimationClip* mCurrentPlayClip;

	bool mPlay;

public:
	ImageAnimation(std::string varConfigPath,float varSpeed);
	~ImageAnimation();

	void Update(float varDeltaTime);

	void Draw();

	void Play(std::string varClipName);
};

