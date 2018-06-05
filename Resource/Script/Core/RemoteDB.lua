local RemoteDB=
{
    mSocketServer,
    mDBServerSocketID,
    mQueryCache={},
    mQueryIndex=100000000,
}

function RemoteDB:Set(varSocketServer,varDBServerSocketID)
    self.mSocketServer=varSocketServer
    self.mDBServerSocketID=varDBServerSocketID
end

function RemoteDB:Query(varQueryStr,varCallbackTable)
    SendMsgToClient(self.mSocketServer,self.mDBServerSocketID,{msgid=GameMessage.Query_To_DBServer_Request,queryIndex=self.mQueryIndex,queryStr=varQueryStr})

    self.mQueryCache[self.mQueryIndex]=varCallbackTable
    self.mQueryIndex=self.mQueryIndex+1
end

function RemoteDB:QueryReturn(varMsg)
    local tmpQueryIndex=varMsg["queryIndex"]
    local tmpCallbackTable=self.mQueryCache[tmpQueryIndex]
    if tmpCallbackTable~=nil then
        local tmpThis=tmpCallbackTable[mThis]
        local tmpCallback=tmpCallbackTable[mCallback]

        if tmpThis~=nil then
            if tmpCallback~=nil then
                tmpCallback(tmpThis,varMsg,tmpCallbackTable)
            end
        end
        table.remove(self.mQueryCache,tmpQueryIndex)
    end

end

return RemoteDB