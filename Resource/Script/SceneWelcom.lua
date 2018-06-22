local ResourcesManager=require("ResourcesManager")

local SceneWelcom=class()

function SceneWelcom:ctor()
	print("SceneWelcom:ctor")
	self.mUIRoot=nil
	self.mGround=nil
	self.mPlayer=nil
	
	print(ResourcesManager:DataPath())
end

--��ʼ��
function SceneWelcom:Init()
	print("SceneWelcom:Init")
	
	
	
	local tmpGoCamera=GameObject:new("sceneCamera")
	tmpGoCamera.mTransform:SetLocalPosition(Vector3(0,0.5,10))
	tmpGoCamera.mTransform:SetLocalRotation(Vector3(0,0,0))
	self.mCamera=tmpGoCamera:AddComponent("Camera")
	
	local tmpGoPhysicsWorld=GameObject:new("PhysicsWorld")
	local tmpPhysicsWorld=tmpGoPhysicsWorld:AddComponent("PhysicsWorld")
	
	local tmpSkinMeshParserGround=SkinMeshParser:new()
	self.mGround=tmpSkinMeshParserGround:CreateScene(ResourcesManager:DataPath() .. "/Resource/Anim/ground/ground.xml");
	self.mGround.mTransform:SetLocalPosition(Vector3(0,-2,0))
	local tmpRigidbody= self.mGround:AddComponent("Rigidbody")
	tmpRigidbody:SetCollisionShape(1,0.0,10,0.1,10)
	
	local tmpSkinMeshParserPlayer=SkinMeshParser:new()
	self.mPlayer=tmpSkinMeshParserPlayer:CreateScene(ResourcesManager:DataPath() .. "/Resource/Anim/9010006/9010006.xml");
	self.mPlayer.mTransform:SetLocalPosition(Vector3(0,2,0))
	local tmpRigidbodyPlayer= self.mPlayer:AddComponent("Rigidbody")
	tmpRigidbodyPlayer:SetCollisionShape(1,1.0,1,2,1)
	
	local audioSource1 = AudioSource:new()
	audioSource1:LoadAudio(ResourcesManager:DataPath().. "/Resource/Audio/Login.mp3")
	audioSource1:Loop()
	audioSource1:Play()
end

--ˢ֡
function SceneWelcom:Update(varDeltaTime)
	--print("SceneWelcom:Update " .. varDeltaTime)
	if self.mUIRoot~=nil then
		self.mUIRoot:Update(varDeltaTime)
	end
	
	if self.mCamera~=nil then
		self.mCamera:Update()
	end
	
	if Input.touchCount>0 then
		print("touchCount:" .. Input.touchCount)
		
		local tmpRaycastHit=RaycastHit:new()
		if Raycast:ScreenPointToRay(Input.mousePosition,self.mCamera,tmpRaycastHit) then
			local tmpGo=tmpRaycastHit:GetHitGameObject()
			print("HitGameObject:" .. tmpGo.name)
		end
	end
end


function SceneWelcom:Draw()
	if self.mUIRoot~=nil then
		self.mUIRoot:Draw()
	end
	
	
	
	if self.mGround~=nil then
		self.mGround:Update()
	end
	
	if self.mPlayer~=nil then
		self.mPlayer:Update()
	end
	
end

return SceneWelcom