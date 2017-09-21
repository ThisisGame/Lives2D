#pragma once

#include"GUI\UIRoot.h"

#include"Image\Image.h"
#include"ImageAnimation\ImageAnimation.h"

//继承KeyTouchListener，监听键盘鼠标事件
#include"KeyTouch\KeyTouchListener.h"
#include"KeyTouch\KeyTouch.h"

#include"GUI\UIButton.h"

#include"../Tools/Helper.h"

#include"./Audio/AudioSource.h"

class DemoScene:KeyTouchListener
{
private:
	//绘制一个帧动画
	ImageAnimation* mImageAnimation_Angel;

	//绘制一个按钮
	UIButton* mUIButton;

	//绘制一张图片
	Image* mImage_Hanhua;
	Image* mImage_Sweep;
	Image* mImage_Bg;

	//一个界面
	UIRoot* mUIRoot;

public:
	DemoScene():KeyTouchListener("DemoScene"), mImageAnimation_Angel(nullptr),mUIButton(nullptr), mImage_Hanhua(nullptr), mImage_Sweep(nullptr), mImage_Bg(nullptr), mUIRoot(nullptr)
	{

	}

	~DemoScene()
	{
		KeyTouch::UnRegisterKeyTouchListener(this);
	}

public:
	void Init()
	{
		//注册键盘鼠标屏幕监听
		KeyTouch::RegisterKeyTouchListener(this);

		//UIRoot
		mUIRoot = new UIRoot();

		mImage_Bg = new Image();
		mImage_Bg->Init("../../Resources/GUI/bbg_temple_circle.jpg");
		mImage_Bg->SetPosition(0, 0);
		mImage_Bg->SetDepth(9999);
		mUIRoot->AddChild(mImage_Bg);
		

		//帧动画初始化
		mImageAnimation_Angel = new ImageAnimation("../../Resources/ImageAnimations/Angel/Animations.txt",1.0f/5);

		mImageAnimation_Angel->SetPosition(0, 200);
		mImageAnimation_Angel->SetScale(0.6, 0.6);
		mImageAnimation_Angel->Play("Idle");

		mUIRoot->AddChild(mImageAnimation_Angel);


		////按钮初始化
		//mUIButton = new UIButton("../../Resources/GUI/pop_button0.png", "../../Resources/GUI/pop_button1.png", 0, 200, 86, 48, [=]()
		//{
		//	Helper::LOG("Click Button");
		//	mImageAnimation_Angel->Play("Talk");
		//});
		//mUIButton->SetDepth(-1); //Depth越小，位于上层
		//mUIRoot->AddChild(mUIButton);
		//

		////图片初始化
		//mImage_Sweep = new Image();
		//mImage_Sweep->Init("../../Resources/GUI/sweep.png");
		//mImage_Sweep->SetPosition(100, 70);
		//mUIRoot->AddChild(mImage_Sweep);

		//mImage_Hanhua = new Image();
		//mImage_Hanhua->Init("../../Resources/GUI/hanhua.png");
		//mImage_Hanhua->SetPosition(100, 100);
		//mUIRoot->AddChild(mImage_Hanhua);
		

		AudioSource* audioSource = new AudioSource();
		audioSource->LoadAudio("../../Resources/Audio/m_sound600.wav");
		audioSource->Loop();
		audioSource->Play();

		//AudioSource* audioSource1 = new AudioSource();
		//audioSource1->LoadAudio("../../Resources/Audio/file2.au");
		//audioSource1->Loop();
		//audioSource1->Play();
	}

	void Update(float varDeltaTime)
	{
		mUIRoot->Update(varDeltaTime);
	}

	void Draw()
	{
		
		mUIRoot->Draw();
	}

private:
	void OnKey(KeyCode varkeyCode) override
	{
		switch (varkeyCode)
		{
		case Right:
			mImageAnimation_Angel->Play("Walk");
			break;
		case Esc:
			break;
		default:
			break;
		}
	}

	void OnTouch(int varX, int varY) override
	{

	}

	void OnTouchRelease(int varX, int varY) override
	{

	}
};