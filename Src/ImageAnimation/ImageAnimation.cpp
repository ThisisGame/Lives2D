//…Ë÷√Œ™24÷°≤•∑≈

#include "ImageAnimation.h"

#include"Tools\Helper.h"


ImageAnimation::ImageAnimation(std::string varConfigPath,float varSpeed):mPlay(false), mCurrentPlayClip(NULL)
{
	std::string tmpDirPath = Helper::GetDirPath(varConfigPath);

	std::vector<std::string> tmpSplits = Helper::ReadLine(varConfigPath);

	string tmpPattern;
	for (auto val : tmpSplits)
	{
		tmpPattern = ":";
		std::vector<std::string> tmpAnimationClipString = Helper::Split(val, tmpPattern);

		string tmpAnimationClipName = tmpAnimationClipString[0];

		tmpPattern = ",";
		std::vector<std::string> tmpAnimationClipData = Helper::Split(tmpAnimationClipString[1], tmpPattern);
		for (size_t i = 0; i < tmpAnimationClipData.size(); i++)
		{
			tmpAnimationClipData[i] = tmpDirPath + tmpAnimationClipData[i];
		}


		ImageAnimationClip* tmpImageAnimationClip = new ImageAnimationClip(tmpAnimationClipName,tmpAnimationClipData, (int)tmpAnimationClipData.size(), varSpeed);
		mVectorImageAnimationClip.push_back(tmpImageAnimationClip);
	}
}

ImageAnimation::~ImageAnimation()
{
}

void ImageAnimation::Update(float varDeltaTime)
{
	if (mPlay)
	{
		mCurrentPlayClip->Update(varDeltaTime);
	}
}

void ImageAnimation::Draw()
{
	if (mPlay)
	{
		mCurrentPlayClip->Draw();
	}
}

void ImageAnimation::Play(std::string varClipName)
{
	mPlay = true;

	for (auto val : mVectorImageAnimationClip)
	{
		if (strcmp(val->GetClipName().c_str(),varClipName.c_str())==0)
		{
			mCurrentPlayClip = val;

			mCurrentPlayClip->Play();
			break;
		}
	}
}
