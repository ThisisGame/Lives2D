local FunctionWrap=
{
    mFunctionIndex=0,
    mFunctionWrap={}
}


function FunctionWrap:Wrap(varFunction)
    local functionWraped="FunctionWrap_" .. self.mFunctionIndex
    self.mFunctionWrap[functionWraped]=varFunction
    self.mFunctionIndex=self.mFunctionIndex+1

    return functionWraped
end

function FunctionWrap:RunWrap(varFunctionID,...)
    for key,value in pairs(self.mFunctionWrap) do
        if key==varFunctionID then
            value(...)
        end
    end
end


function Wrap(varFunction)
    return FunctionWrap:Wrap(varFunction)
end

function RunWrap(varFunctionID,...)
    FunctionWrap:RunWrap(varFunctionID,...)
end

function SendMsgToServer(varTCPSocket,varMsgTable)
    local tmpJsonStr=cjson.encode(varMsgTable)
    varTCPSocket:Send(tmpJsonStr)
end

function SendMsgToClient(varTCPSocket,varClientSocketId,varMsgTable)
    local tmpJsonStr=cjson.encode(varMsgTable)
    varTCPSocket:Send(varClientSocketId,tmpJsonStr)
end


function ConcatString(varSplit,...)
    local strs={}

    for i,v in ipairs(arg) do
        table.insert(strs,v)
    end

    local result=table.concat(strs,varSplit)

    return result
end

return FunctionWrap