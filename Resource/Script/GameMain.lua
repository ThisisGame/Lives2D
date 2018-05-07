print("GameMain Run")

local class=require("Engine/class")
local SceneWelcom=require("SceneWelcom")

local GameMain=
{
	mSceneWelcom
}

--初始化
function GameMain:Init()
	Application.DesignWidth=1136
	Application.DesignHeight=640

	self.mSceneWelcom=SceneWelcom.new()
	self.mSceneWelcom:Init()
end


--刷帧
function GameMain:Update(varDeltaTime)
	self.mSceneWelcom:Update(varDeltaTime)
end

--绘制
function GameMain:Draw()
	self.mSceneWelcom:Draw()
end


return GameMain



