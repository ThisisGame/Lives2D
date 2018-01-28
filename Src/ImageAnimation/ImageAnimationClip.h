//帧动画 片段 数据

#pragma once

#include<string>
#include<vector>
#include"GUI/UIImage.h"

class ImageAnimationClip
{
private:
	std::string mClipName;

	std::vector<UIImage*> mVectorImageData;


	//是否在播放
	bool mPlay;

	//当前播放时间
	float mPlayTime;

	//总帧数
	int mKeyFrameCount;

	//当前帧
	int mIndex;

	//播放速度
	float mSpeed;

	float mPosX;
	float mPosY;
	float mScaleX;
	float mScaleY;

public:
	std::string GetClipName();

public:
	ImageAnimationClip(std::string varClipName,std::vector<std::string> varVectorFrameImagePath,int varKeyFrameCount, float varSpeed);
	~ImageAnimationClip();


	void Update(float varDeltaTime);

	void Draw();

	void Play();

	void Stop();

	//设置位置
	void SetPosition(float varPosX, float varPosY);

	//设置缩放
	void SetScale(float varScaleX, float varScaleY);
};

