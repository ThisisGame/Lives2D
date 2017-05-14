#pragma once

#include"Image\Image.h"

//¼Ì³ÐKeyTouchListener£¬¼àÌý¼üÅÌÊó±êÊÂ¼þ
#include"KeyTouch\KeyTouchListener.h"
#include"KeyTouch\KeyTouch.h"

class DemoScene:KeyTouchListener
{
private:
	//»æÖÆÒ»¸öÍ¼Æ¬
	Image* mImage;

public:
	DemoScene():KeyTouchListener("DemoScene"),mImage(NULL)
	{

	}

	~DemoScene()
	{
		KeyTouch::UnRegisterKeyTouchListener(this);
	}

public:
	void Init()
	{
		//×¢²á¼üÅÌÊó±êÆÁÄ»¼àÌý
		KeyTouch::RegisterKeyTouchListener(this);

		//Í¼Æ¬³õÊ¼»¯
		mImage = new Image();
		mImage->Init("../../Resources/images/logo.png");
	}

	void Update(float varDeltaTime)
	{
		//Scale Test
		mImage->SetScale(1.0f + varDeltaTime, 1.0f + varDeltaTime);
	}

	void Draw()
	{
		//»æÖÆÒ»¸öÍ¼Æ¬
		mImage->Draw();
	}

private:
	virtual void OnKey(KeyCode varkeyCode)
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
			break;
		case Esc:
			break;
		default:
			break;
		}
	}

	virtual void OnTouch(float varX, float varY)
	{

	}
};