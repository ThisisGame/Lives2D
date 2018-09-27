WindowID=
{
    Login,
}


local LoginWindow=require("Window/LoginWindow")

WindowManager=
{
    mWindowDic={}
}

function WindowManager:Register()
    table.insert(self.mWindowDic,WindowID.Login,LoginWindow)
end

function WindowManager:OpenWindow(varWindowType)
    local tmpWindow=varWindowType.new()
    table.insert(self.mWindowDic,varWindowType,tmpWindow)
    tmpWindow:begin()
end

function WindowManager:CloseWindow(varWindowType)
    self.mWindowDic[varWindowType]:close()
    table.remove(self.mWindowDic,varWindowScript)
end

return WindowManager