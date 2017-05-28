#pragma once

#include"Image\Image.h"
#include"ImageAnimation\ImageAnimation.h"

//继承KeyTouchListener，监听键盘鼠标事件
#include"KeyTouch\KeyTouchListener.h"
#include"KeyTouch\KeyTouch.h"

#include"GUI\UIButton.h"

#include"../Tools/Helper.h"

class DemoScene:KeyTouchListener
{
private:
	//绘制一个图片
	Image* mImage;

	//绘制一个帧动画
	ImageAnimation* mImageAnimation;

	//绘制一个按钮
	UIButton* mUIButton;

public:
	DemoScene():KeyTouchListener("DemoScene"),mImage(NULL), mImageAnimation(NULL)
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

		//图片初始化
		mImage = new Image();
		mImage->Init("../../Resources/images/logo.png");

		//帧动画初始化
		mImageAnimation = new ImageAnimation("../../Resources/ImageAnimations/Swordman/Saber/Animations.txt",1.0f/4);

		mImageAnimation->Play("Idle");

		//按钮初始化
		mUIButton = new UIButton("../../Resources/GUI/pop_button0.png", "../../Resources/GUI/pop_button1.png", 0, 0, 86, 48, []() 
		{
			Helper::LOG("Click Button");
		});
	}

	void Update(float varDeltaTime)
	{
		//Scale Test
		//mImage->SetScale(1.0f + varDeltaTime, 1.0f + varDeltaTime);

		mImageAnimation->Update(varDeltaTime);

		mUIButton->Update(varDeltaTime);
	}

	void Draw()
	{
		//绘制一个图片
		//mImage->Draw();

		//mImageAnimation->Draw();

		mUIButton->Draw();
	}

private:
	void OnKey(KeyCode varkeyCode) override
	{
		switch (varkeyCode)
		{
		case Up:
			mImage->SetPosition(mImage->mPosX, mImage->mPosY + 1);
			break;
		case Down:
			mImage->SetPosition(mImage->mPosX, mImage->mPosY - 1);
			break;
		case Left:
			mImage->SetPosition(mImage->mPosX-1, mImage->mPosY);
			break;
		case Right:
			mImage->SetPosition(mImage->mPosX + 1, mImage->mPosY);

			mImageAnimation->Play("Walk");
			break;
		case Esc:
			break;
		default:
			break;
		}
	}

	void OnTouch(float varX, float varY) override
	{

	}

	void OnTouchRelease(float varX, float varY) override
	{

	}
};