#include "ImageAnimationClip.h"



ImageAnimationClip::ImageAnimationClip(std::vector<Image*> varClipData, int varKeyFrameCount, float varSpeed)
	:mVectorImageData(varClipData),mPlay(false), mPlayTime(0), mKeyFrameCount(varKeyFrameCount), mIndex(0), mSpeed(varSpeed)
{

}


ImageAnimationClip::~ImageAnimationClip()
{
}



void ImageAnimationClip::Update(float varDeltaTime)
{
	if (mPlay)
	{
		mPlayTime += varDeltaTime;

		mIndex = mPlayTime / mSpeed;

		mIndex = mIndex% mKeyFrameCount;
	}
}

void ImageAnimationClip::Draw()
{
	if (mPlay)
	{
		mVectorImageData[mIndex]->Draw();
	}
}

void ImageAnimationClip::Play()
{
	mPlay = true;
}