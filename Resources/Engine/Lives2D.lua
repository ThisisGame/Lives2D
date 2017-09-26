
print("Lives2D")

local mUIRoot

--初始化
function Init(varWidth,varHeight)
	print("Init " .. varWidth .. varHeight)

	AudioCardInit()

	local audioSource1 = AudioSource:new()
	audioSource1:LoadAudio("../../Resources/Audio/m_sound600.wav")
	audioSource1:Loop()
	audioSource1:Play()

	local audioSource2 = AudioSource:new()
	audioSource2:LoadAudio("../../Resources/Audio/click.wav")
	
	mUIRoot=UIRoot:new()

	
	local	mImage_Bg =  Image:new()
	mImage_Bg:Init("../../Resources/GUI/bbg_temple_circle.jpg");
	mImage_Bg:SetPosition(0, 0);
	mImage_Bg:SetDepth(0);
	mUIRoot:AddChild(mImage_Bg);

	local mUIButton = UIButton:new("../../Resources/GUI/pop_button0.png", "../../Resources/GUI/pop_button1.png", 0, 200, 86, 48)
	mUIButton:SetOnClickListener(function(varTime)
		--print(varTime)

		audioSource2:Play()
	end,111)
	mUIButton:SetDepth(2);
	mUIRoot:AddChild(mUIButton);

	local mImageAnimation_Angel =  ImageAnimation:new("../../Resources/ImageAnimations/Angel/Animations.txt",1.0/5)

	mImageAnimation_Angel:SetPosition(0, 200)
	mImageAnimation_Angel:SetScale(0.6, 0.6)
	mImageAnimation_Angel:Play("Idle")
	mImageAnimation_Angel:SetDepth(1);
	mUIRoot:AddChild(mImageAnimation_Angel)

end

function UIButtonClick()
	print("click button")
end

--刷帧
function Update(varDeltaTime)
	--print("Update " .. varDeltaTime)
	mUIRoot:Update(varDeltaTime)
end

--绘制
function Draw()
	--print("Draw")
	mUIRoot:Draw()
end

--键盘鼠标
function OnKey(varkeyCode)
	print("OnKey " .. varkeyCode)
	
	KeyTouch:OnKey(varkeyCode)
end

--屏幕触摸点击
function OnTouch(varX,varY)

	print("OnTouch " .. varX .." " .. varY)
	KeyTouch:OnTouch(varX, varY)
end


--释放点击
function OnTouchRelease(varX,varY)
	print("OnTouchRelease " .. varX .." " .. varY)

	KeyTouch:OnTouchRelease(varX, varY)
end

function OnDestroy()
	print("OnDestroy")
	AudioCardExit()
end