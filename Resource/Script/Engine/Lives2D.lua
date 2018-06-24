print("Lives2D")

require("Engine/FunctionWrap")
local GameMain=require("GameMain")

--初始化
function Init(varWidth,varHeight)
	print("Lives2D Init " .. varWidth .. varHeight)

	GameMain:Init()
end

--刷帧
function Update(varDeltaTime)
	--print("Update " .. varDeltaTime)
	GameMain:Update(varDeltaTime)
end

--绘制
function Draw()
	--print("Draw")
	GameMain:Draw()
end

--键盘鼠标
function OnKey(varkeyCode)
	--print("OnKey " .. varkeyCode)
	
	KeyTouch:OnKey(varkeyCode)
	
	
end

--屏幕触摸点击
function OnTouch(varX,varY)

	Input.touchCount=1

	--print("OnTouch " .. varX .." " .. varY)
	KeyTouch:OnTouch(varX, varY)
	
	Input.mousePosition.mX=varX;
	Input.mousePosition.mY=varY;
	
	--print("Input.mousePosition:" .. Input.mousePosition.mX .. Input.mousePosition.mY)
	
end


--释放点击
function OnTouchRelease(varX,varY)
	--print("OnTouchRelease " .. varX .." " .. varY)

	Input.touchCount=0
	
	KeyTouch:OnTouchRelease(varX, varY)
	
	
end

function OnDestroy()
	print("OnDestroy")
end