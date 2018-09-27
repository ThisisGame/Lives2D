print("GameMain Run")

local class=require("Engine/class")

require("ResourcesManager")

require("Scene/SceneManager")

require("Framework/DelayTaskManager")

require("Framework/Network/NetworkConnect")

require("Framework/WindowManager")

--设置每秒固定刷帧
fixedUpdateFrame=20

local GameMain=
{
	mSceneWelcom
}

--初始化
function GameMain:Init()
	Application.DesignWidth=540
	Application.DesignHeight=960
	

	SceneManager:Register()
end


--刷帧
function GameMain:Update(varDeltaTime)
	SceneManager:Update(varDeltaTime)

	DelayTaskManager:Update()
	NetworkConnect:Update()

	WindowManager:Update(varDeltaTime)
end

function GameMain:FixedUpdate()
	SceneManager:FixedUpdate()
end

--绘制
function GameMain:Draw()
	SceneManager:Draw()

	WindowManager:Draw()
end


return GameMain



