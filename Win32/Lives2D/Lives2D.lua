
print("Lives2D")


--初始化
function Init()
	print("Init")
end

--刷帧
function Update(varDeltaTime)
	print("Update " .. varDeltaTime)
end

--绘制
function Draw()
	print("Draw")
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
end