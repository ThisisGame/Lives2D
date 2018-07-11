

local FunctionWrap=
{
    mFunctionIndex=0,
    mFunctionWrap={},
	mFunctionTableWrap={}
}


function FunctionWrap:Wrap(varFunction,varTable)
    local functionWraped="FunctionWrap_" .. self.mFunctionIndex
    self.mFunctionWrap[functionWraped]=varFunction
	self.mFunctionTableWrap[functionWraped]=varTable
    self.mFunctionIndex=self.mFunctionIndex+1

    return functionWraped
end

function FunctionWrap:RunWrap(varFunctionID,...)
    for key,value in pairs(self.mFunctionWrap) do
        if key==varFunctionID then
			if self.mFunctionTableWrap[varFunctionID]~=nil then
				value(self.mFunctionTableWrap[varFunctionID],...)
			else
				print("Function Null Self")
			end
        end
    end
end


function Wrap(varFunction,varTable)
    return FunctionWrap:Wrap(varFunction,varTable)
end

function RunWrap(varFunctionID,...)
    FunctionWrap:RunWrap(varFunctionID,...)
end


return FunctionWrap