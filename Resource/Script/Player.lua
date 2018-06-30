local Player={}

function Player:Bind(varLuaComponent)
	varLuaComponent:Bind("Awake",Wrap(self.Awake,self))
	varLuaComponent:Bind("OnCollisionEnter",Wrap(self.OnCollisionEnter,self))
end

function Player:Awake()
	print("Player:Awake")
end

function Player:OnCollisionEnter(varTransA,varTransB)
	print("Player:OnCollisionEnter")
end

return Player