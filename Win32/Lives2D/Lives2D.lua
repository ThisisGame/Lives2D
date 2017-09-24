
print("Lives2D")

local mUIButton

--初始化
function Init(varWidth,varHeight)
	print("Init " .. varWidth .. varHeight)

	AudioCardInit()

	local audioSource1 = AudioSource:new()
	audioSource1:LoadAudio("../../Resources/Audio/m_sound600.wav")
	audioSource1:Loop()
	audioSource1:Play()

	mUIButton = UIButton:new("../../Resources/GUI/pop_button0.png", "../../Resources/GUI/pop_button1.png", 0, 200, 86, 48)
	mUIButton:SetOnClickListener(function(varTime)
		print(varTime)
	end,111)
end

function UIButtonClick()
	print("click button")
end

--刷帧
function Update(varDeltaTime)
	--print("Update " .. varDeltaTime)
	mUIButton:Update(varDeltaTime)
end

--绘制
function Draw()
	--print("Draw")
	mUIButton:Draw()
end

--键盘鼠标
function OnKey(varkeyCode)
	print("OnKey " .. varkeyCode)
	
end

--屏幕触摸点击
function OnTouch(varX,varY)

	print("OnTouch " .. varX .." " .. varY)

end


--释放点击
function OnTouchRelease(varX,varY)
	print("OnTouchRelease " .. varX .." " .. varY)
end

function OnDestroy()
	print("OnDestroy")
	AudioCardExit()
end