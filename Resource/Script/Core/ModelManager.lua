--**************************
-- 文件名:ModelManager.lua
-- 文件描述:ModelManager 用来管理每个模块的Model，Model用来负责数据存储于网络交互
-- 创建日期:2015/11/15
-- Author:Create by 陈鹏
--**************************

local ModelManager=
{
    mModelTable={}
}


function ModelManager:RegisterModel(varModelID,varModel)
    self.mModelTable[varModelID]=varModel
    varModel:OnRegister()
end


function ModelManager:GetModel(varModelId)
    for key,value in pairs(self.mModelTable) do
        if key==varModelId then
            return value
        end
    end
end

function ModelManager:ClearModelData()
    for key,value in pairs(self.mModelTable) do
        if value ~= nil then
            value:OnClear()
        end
    end
end

return ModelManager