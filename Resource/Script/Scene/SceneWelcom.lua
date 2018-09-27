require("Core/Core")
require("Public/Public")

local class=require("Engine/class")

local SceneWelcom=class()


function SceneWelcom:ctor()
	print("SceneWelcom:ctor")
	
	print(ResourcesManager:DataPath())
end


function SceneWelcom:begin()

end

function SceneWelcom:Init()
	print("SceneWelcom:Init")
	
end


function SceneWelcom:Update(varDeltaTime)

end


function SceneWelcom:FixedUpdate()
	--print("SceneWelcom:FixedUpdate")

end

function SceneWelcom:Draw()

end

function SceneWelcom:close()

end