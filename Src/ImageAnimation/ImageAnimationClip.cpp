#include "ImageAnimationClip.h"



std::string ImageAnimationClip::GetClipName()
{
	return mClipName;
}

ImageAnimationClip::ImageAnimationClip(std::string varClipName, std::vector<std::string> varVectorFrameImagePath, int varKeyFrameCount, float varSpeed)
	:mPlay(false), mPlayTime(0), mKeyFrameCount(varKeyFrameCount), mIndex(0), mSpeed(varSpeed),mClipName(varClipName)
{
	for (auto val : varVectorFrameImagePath)
	{
		Image* tmpImage = new Image();
		tmpImage->Init(val.c_str());


		mVectorImageData.push_back(tmpImage);

		//Helper::LOG("%s push_back  %s", mClipName.c_str(), val.c_str());
	}
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

void ImageAnimationClip::Stop()
{
	mPlay = false;
}

void ImageAnimationClip::SetPosition(float varPosX, float varPosY)
{
	mPosX = varPosX;
	mPosY = varPosY;

	for (auto val : mVectorImageData)
	{
		val->SetPosition(varPosX, varPosY);
	}
}

void ImageAnimationClip::SetScale(float varScaleX, float varScaleY)
{
	mScaleX = varScaleX;
	mScaleY = varScaleY;

	for (auto val : mVectorImageData)
	{
		val->SetScale(varScaleX, varScaleY);
	}
}
