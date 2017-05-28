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
	//绘制一个帧动画
	ImageAnimation* mImageAnimation;

	//绘制一个按钮
	UIButton* mUIButton;

public:
	DemoScene():KeyTouchListener("DemoScene"), mImageAnimation(NULL),mUIButton(NULL)
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

		//帧动画初始化
		mImageAnimation = new ImageAnimation("../../Resources/ImageAnimations/Swordman/Saber/Animations.txt",1.0f/4);

		mImageAnimation->Play("Idle");

		//按钮初始化
		mUIButton = new UIButton("../../Resources/GUI/pop_button0.png", "../../Resources/GUI/pop_button1.png", 0, 100, 86, 48, [=]()
		{
			Helper::LOG("Click Button");
			mImageAnimation->Play("Walk");
		});
	}

	void Update(float varDeltaTime)
	{
		mImageAnimation->Update(varDeltaTime);

		mUIButton->Update(varDeltaTime);
	}

	void Draw()
	{
		mImageAnimation->Draw();

		mUIButton->Draw();
	}

private:
	void OnKey(KeyCode varkeyCode) override
	{
		switch (varkeyCode)
		{
		case Right:
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