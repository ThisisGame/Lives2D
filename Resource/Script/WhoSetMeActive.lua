local WhoSetMeActive=
{
	mID=0
}

function WhoSetMeActive:Bind(varLuaComponent)
	print("WhoSetMeActive:Bind " .. tostring(self.mID))
	varLuaComponent:BindAwake(Wrap(self.Awake,self))
	varLuaComponent:BindOnEnable(Wrap(self.OnEnable,self))
	varLuaComponent:BindStart(Wrap(self.Start,self))
	varLuaComponent:BindUpdate(Wrap(self.Update,self))
	varLuaComponent:BindOnDisable(Wrap(self.OnDisable,self))
	varLuaComponent:BindOnDestroy(Wrap(self.OnDestroy,self))
end

function WhoSetMeActive:Awake()
	print("WhoSetMeActive:Awake " .. tostring(self.mID))
end


function WhoSetMeActive:OnEnable()

print("WhoSetMeActive:OnEnable " .. tostring(self.mID))
end

function WhoSetMeActive:Start()
print("WhoSetMeActive:Start " .. tostring(self.mID))

end

function WhoSetMeActive:Update()
print("WhoSetMeActive:Update " .. tostring(self.mID))

end

function WhoSetMeActive:OnDisable()

print("WhoSetMeActive:OnDisable " .. tostring(self.mID))
end

function WhoSetMeActive:OnDestroy()
print("WhoSetMeActive:OnDestroy " .. tostring(self.mID))

end


return WhoSetMeActive