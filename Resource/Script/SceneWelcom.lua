local ResourcesManager=require("ResourcesManager")

local SceneWelcom=class()

function SceneWelcom:ctor()
	print("SceneWelcom:ctor")
	self.mUIRoot=nil
	self.mGround=nil
	self.mPlayer=nil
	self.mWomenBody=nil
	self.TvGirl_CruX_Gloves_7778=nil
	self.TvGirl_DisclosedII_33798=nil
	self.TvGirl_finalhair_65512=nil
	self.TvGirl_G3_Pantyhose_5176=nil
	self.TvGirl_Genesis3Female=nil
	self.Sphere_0=nil
	self.Sphere_1=nil
	self.Box001_0=nil
	self.Box001_1=nil
	self.Box001_2=nil
	self.Box001_3=nil
	self.Box001_4=nil
	self.Box001_5=nil
	self.Box001_6=nil
	self.Box001_7=nil
	self.Box001_8=nil
	self.Box001_9=nil
	self.Box001_10=nil
	self.Box001_11=nil
	self.Box001_12=nil
	self.Box001_13=nil
	self.Box001_14=nil
	self.Box001_15=nil
	self.Box001_16=nil
	self.Box001_17=nil
	self.Box001_18=nil
	self.Box001_19=nil
	self.Box001_20=nil
	self.Box001_21=nil
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
	self.mGround.mTransform:SetLocalPosition(Vector3(0,-5,-10))
	local tmpRigidbody= self.mGround:AddComponent("Rigidbody")
	tmpRigidbody:SetCollisionShape(1,0.0,10,0.5,10)
	
	local tmpSkinMeshParserPlayer=SkinMeshParser:new()
	self.mPlayer=tmpSkinMeshParserPlayer:CreateScene(ResourcesManager:DataPath() .. "/Resource/Anim/9010006/9010006.xml");
	self.mPlayer.mTransform:SetLocalPosition(Vector3(0,0,0))
	local tmpRigidbodyPlayer= self.mPlayer:AddComponent("Rigidbody")
	tmpRigidbodyPlayer:SetCollisionShape(1,.0,1,2,0)
	
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
	
	if self.mWomenHair~=nil then
		self.mWomenHair:Update()
	end
	
	if self.mWomenBody~=nil then
		self.mWomenBody:Update()
	end
	
	if self.mGround~=nil then
		self.mGround:Update()
	end
	
	if self.mPlayer~=nil then
		self.mPlayer:Update()
	end
	
	if self.Sphere_0~=nil then
		self.Sphere_0:Update()
	end
	
	if self.Sphere_1~=nil then
		self.Sphere_1:Update()
	end
	
	if self.Box001_0~=nil then
		self.Box001_0:Update()
	end
	
	if self.Box001_1~=nil then
		self.Box001_1:Update()
	end
	
	if self.Box001_2~=nil then
		self.Box001_2:Update()
	end
	
	if self.Box001_3~=nil then
		self.Box001_3:Update()
	end
	if self.Box001_4~=nil then
		self.Box001_4:Update()
	end
	if self.Box001_5~=nil then
		self.Box001_5:Update()
	end
	if self.Box001_6~=nil then
		self.Box001_6:Update()
	end
	if self.Box001_7~=nil then
		self.Box001_7:Update()
	end
	if self.Box001_8~=nil then
		self.Box001_8:Update()
	end
	if self.Box001_9~=nil then
		self.Box001_9:Update()
	end
	if self.Box001_10~=nil then
		self.Box001_10:Update()
	end
	if self.Box001_11~=nil then
		self.Box001_11:Update()
	end
	if self.Box001_12~=nil then
		self.Box001_12:Update()
	end
	if self.Box001_13~=nil then
		self.Box001_13:Update()
	end
	if self.Box001_14~=nil then
		self.Box001_14:Update()
	end
	if self.Box001_15~=nil then
		self.Box001_15:Update()
	end
	if self.Box001_16~=nil then
		self.Box001_16:Update()
	end
	if self.Box001_17~=nil then
		self.Box001_17:Update()
	end
	if self.Box001_18~=nil then
		self.Box001_18:Update()
	end
	if self.Box001_19~=nil then
		self.Box001_19:Update()
	end
	if self.Box001_20~=nil then
		self.Box001_20:Update()
	end
	if self.Box001_21~=nil then
		self.Box001_21:Update()
	end

	if self.TvGirl_CruX_Gloves_7778~=nil then
		self.TvGirl_CruX_Gloves_7778:Update()
	end
	
	if self.TvGirl_DisclosedII_33798~=nil then
		self.TvGirl_DisclosedII_33798:Update()
	end
	
	if self.TvGirl_finalhair_65512~=nil then
		self.TvGirl_finalhair_65512:Update()
	end
	
	if self.TvGirl_G3_Pantyhose_5176~=nil then
		self.TvGirl_G3_Pantyhose_5176:Update()
	end
	
	if self.TvGirl_Genesis3Female~=nil then
		self.TvGirl_Genesis3Female:Update()
	end
end

return SceneWelcom