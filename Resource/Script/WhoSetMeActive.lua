local WhoSetMeActive={}

function WhoSetMeActive:Awake()
	print("WhoSetMeActive:Awake")
end


function WhoSetMeActive:OnEnable()

print("WhoSetMeActive:OnEnable")
end

function WhoSetMeActive:Start()
print("WhoSetMeActive:Start")

end

function WhoSetMeActive:Update()
print("WhoSetMeActive:Update")

end

function WhoSetMeActive:OnDisable()

print("WhoSetMeActive:OnDisable")
end

function WhoSetMeActive:OnDestroy()
print("WhoSetMeActive:OnDestroy")

end


return WhoSetMeActive