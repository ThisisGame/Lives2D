//…Ë÷√Œ™24÷°≤•∑≈

#include "ImageAnimation.h"

#include"Tools\Helper.h"


ImageAnimation::ImageAnimation(std::string varConfigPath,int varKeyFrameCount,float varSpeed):mPlay(false), mPlayTime(0), mKeyFrameCount(varKeyFrameCount), mSpeed(varSpeed)
{
	std::vector<std::string> tmpSplits = Helper::ReadLine(varConfigPath);

	string tmpPattern;
	for (auto val : tmpSplits)
	{
		tmpPattern = ":";
		std::vector<std::string> tmpAnimationClipString = Helper::Split(val, tmpPattern);

		string tmpAnimationClipName = tmpAnimationClipString[0];

		tmpPattern = ",";
		std::vector<std::string> tmpAnimationClipData = Helper::Split(tmpAnimationClipString[1], tmpPattern);

	}
}

ImageAnimation::~ImageAnimation()
{
}

void ImageAnimation::Update(float varDeltaTime)
{
	if (mPlay)
	{
		mPlayTime += varDeltaTime;

		mIndex = mPlayTime / mSpeed;

		mIndex = mIndex% mVectorImageData.size();
	}
}

void ImageAnimation::Draw()
{
	if (mPlay)
	{
		mVectorImageData[mIndex]->Draw();
	}
}

void ImageAnimation::Play()
{
	mPlay = true;
}
