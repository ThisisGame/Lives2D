DelayTaskManager=
{
	DelayTaskTable={},
	DelayTaskIndex=0,
}


function DelayTaskManager:AddDelayTask(varDelayTime,varCallback)
    self.DelayTaskIndex=self.DelayTaskIndex+1
    
    table.insert(self.DelayTaskTable,self.DelayTaskIndex,{Callback=varCallback,TimeExpire=os.time()+varDelayTime})
    
    return self.DelayTaskIndex
end

function DelayTaskManager:AddRepeatTask(varDelayTime,varCallback)
    self.DelayTaskIndex=self.DelayTaskIndex+1
    
    table.insert(self.DelayTaskTable,self.DelayTaskIndex,{Callback=varCallback,TimeExpire=os.time()+varDelayTime,RepeatDeltaTime=varDelayTime})
    
    return self.DelayTaskIndex
end

function DelayTaskManager:RemoveTask(varTaskIndex)
    for key,value in pairs(self.DelayTaskTable) do
        if key==varTaskIndex then
            self.DelayTaskTable[varTaskIndex]=nil
            break
        end
    end 
end

function DelayTaskManager:Update()
    for key,value in pairs(self.DelayTaskTable) do
	--print(key)
        if value~=nil then
            
            local tmpTimeExpire=value["TimeExpire"]

            --print(os.time() .. " tmpTimeExpire:" .. tmpTimeExpire)

            if(os.time() >= tmpTimeExpire) then
                value["Callback"]()


                if value["RepeatDeltaTime"]==nil then 
                    self.DelayTaskTable[key]=nil
                else
                    value["TimeExpire"]=os.time()+value["RepeatDeltaTime"]
                end
            end
        end
    end
end

return DelayTaskManager
