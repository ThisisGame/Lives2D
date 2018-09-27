--**************************
-- 文件名:EventDispatcher.lua
-- 文件描述:EventDispatcher
-- 创建日期:2015/11/15
-- Author:Create by 陈鹏
--**************************

EventDispatch=
{
	m_EventCallbackTable={}
}



--注册返回的
function EventDispatch:RegisterEventCallback(eventid,this,callback)

	if callback==nil then
		Debug.LogError("UnRegisterEventCallback Error,3 Param Need")
	end

	-- body
	if(self.m_EventCallbackTable[eventid]==nil) then
	
		--msgindex对应的table，里面放handler
		local callbackTable={}
		
		--把 callbackTable 添加到 m_EventCallbackTable
		table.insert(self.m_EventCallbackTable,eventid,callbackTable)
	end
	
	local callbackTable = self.m_EventCallbackTable[eventid]
	
	table.insert(callbackTable,{m_this=this;m_callback=callback})

	--在C#中注册
	EventDispatchBridge.RegisterEventID(eventid)
end



--反注册返回
function EventDispatch:UnRegisterEventCallback(eventid,callback,error)
	if error~=nil then
		Debug.LogError("UnRegisterEventCallback Error,Only 2 Param Accept")
	end
	if callback==nil then
		Debug.LogError("UnRegisterEventCallback Error,2 Param Need")
	end
	if self.m_EventCallbackTable[eventid]~=nil then
		local callbackTable = self.m_EventCallbackTable[eventid]
		for index=1,table.maxn(callbackTable),1 do
			if callbackTable[index].m_callback==callback then
				callbackTable[index]=nil
				table.remove(callbackTable,index)
				break
			end
		end
	else
		UnityEngine.Debug.LogError(tostring(eventid) .. "has not Register!!donot UnRegister!")
	end
end

--分发
function EventDispatch:DispatchEvent(eventid,...)
	--UnityEngine.Debug.Log("EventDispatcher:DispatchEvent eventid:" .. eventid)

	-- body
	for key,value in pairs(self.m_EventCallbackTable) do
		if(key == eventid) then
			for callbackkey,callbackvalue in pairs(value) do
				callbackvalue.m_callback(callbackvalue.m_this,...)     --回调;
			end
		end
	end
end


return EventDispatch