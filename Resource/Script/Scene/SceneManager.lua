require("Scene/SceneID")
local SceneWelcom=require("Scene/SceneWelcom")
local SceneLogin=require("Scene/SceneLogin")

SceneManager=
{
    mSceneIDCurrent=nil,
    mSceneCurrent=nil,
    mSceneDic={}
}

function SceneManager:Register()
    table.insert(mSceneDic,SceneID.Welcom,SceneWelcom)
    table.insert(mSceneDic,SceneID.Login,SceneLogin)
end

function SceneManager:GotoScene(varSceneID)
    if self.mSceneCurrent~=nil then
        self.mSceneCurrent:close()
    end

    self.mSceneCurrent=self.mSceneDic[varSceneID].new()
    
    if self.mSceneCurrent==nil then
        print("Donot find scene:" .. varSceneID)
        return
    end

    self.mSceneIDCurrent=varSceneID
    self.mSceneCurrent:begin()
end

return SceneManager