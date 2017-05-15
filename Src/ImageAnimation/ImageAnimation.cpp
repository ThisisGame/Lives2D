//…Ë÷√Œ™24÷°≤•∑≈

#include "ImageAnimation.h"

#include"Tools\Helper.h"


ImageAnimation::ImageAnimation(std::string varConfigPath,int varKeyFrameCount,float varSpeed):mPlay(false), mPlayTime(0), mKeyFrameCount(varKeyFrameCount), mSpeed(varSpeed)
{
	std::string tmpConfig = Helper::ReadTxt(varConfigPath);



	//for (size_t i = 0; i <mKeyFrameCount; i++)
	//{
	//	Image* tmpImage = new Image();
	//	tmpImage->Init(varImageData[i].c_str());

	//	mVectorImageData.push_back(tmpImage);
	//}
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
