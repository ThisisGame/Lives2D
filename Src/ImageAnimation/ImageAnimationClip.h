//帧动画 片段 数据

#pragma once

#include<string>
#include<vector>
#include"Image\Image.h"

class ImageAnimationClip
{
private:
	std::string mClipName;

	std::vector<Image*> mVectorImageData;


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

public:
	std::string GetClipName();

public:
	ImageAnimationClip(std::string varClipName,std::vector<std::string> varVectorFrameImagePath,int varKeyFrameCount, float varSpeed);
	~ImageAnimationClip();


	void Update(float varDeltaTime);

	void Draw();

	void Play();

	void Stop();
};

