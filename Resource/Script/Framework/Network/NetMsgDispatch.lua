--**************************
-- 文件名:NetMsgDispatcher.lua
-- 文件描述:NetMsgDispatcher
-- 创建日期:2015/11/15
-- Author:Create by 陈鹏
--**************************


NetMsgDispatch=
{
	m_NetMsgCallbackTable={},
}



--注册返回的
function NetMsgDispatch:RegisterNetMsgCallback(msgindex,this,callback)
	-- body
	if(self.m_NetMsgCallbackTable[msgindex]==nil) then
	
		--msgindex对应的table，里面放handler
		local callbackTable={}
		
		--把 callbackTable 添加到 m_NetMsgCallbackTable
		table.insert(self.m_NetMsgCallbackTable,msgindex,callbackTable)
	end
	
	local callbackTable = self.m_NetMsgCallbackTable[msgindex]
	
	table.insert(callbackTable,{m_this=this;m_callback=callback})

	NetworkConnectBridge.RegisterMessageID(msgindex)
end



--反注册返回
function NetMsgDispatch:UnRegisterNetMsgCallback(msgindex,callback)
	if self.m_NetMsgCallbackTable[msgindex]~=nil then
		local callbackTable = self.m_NetMsgCallbackTable[msgindex]
		for index=1,table.maxn(callbackTable),1 do
			if callbackTable[index].m_callback==callback then
				callbackTable[index]=nil
				table.remove(callbackTable,index)
				break
			end
		end
	else
		Debug.LogError(tostring(msgindex) .. "has not Register!!donot UnRegister!")
	end
end

--分发
function NetMsgDispatch:DispatchMsg(cmdIndex,varMsg)
	--Debug.Log("NetMsgDispatcher:DispatchMsg cmdIndex:" .. cmdIndex)

	-- body
	for key,value in pairs(self.m_NetMsgCallbackTable) do
		if(key == cmdIndex) then
			for callbackkey,callbackvalue in pairs(value) do
				callbackvalue.m_callback(callbackvalue.m_this,varMsg)     --回调;
			end
		end
	end
end


return NetMsgDispatch