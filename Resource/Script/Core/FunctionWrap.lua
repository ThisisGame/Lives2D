local FunctionWrap=
{
    mFunctionIndex=0,
    mFunctionWrap={}
}


function FunctionWrap:Wrap(this,varFunction)
    local functionWraped="FunctionWrap_" .. self.mFunctionIndex
    self.mFunctionWrap[functionWraped]={this,varFunction}
    self.mFunctionIndex=self.mFunctionIndex+1

    return functionWraped
end

function FunctionWrap:RunWrap(varFunctionID,...)
    for key,value in pairs(self.mFunctionWrap) do
        if key==varFunctionID then
            value[1]:value[2](...)
        end
    end
end


function Wrap(this,varFunction)
    return FunctionWrap:Wrap(this,varFunction)
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