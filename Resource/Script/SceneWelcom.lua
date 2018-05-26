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
	tmpGoCamera.mTransform:SetLocalPosition(Vector3(0,0.5,30))
	tmpGoCamera.mTransform:SetLocalRotation(Vector3(0,0,0))
	self.mCamera=tmpGoCamera:AddComponent("Camera")
	
	local tmpSphere=SkinMeshParser:new()
	self.Sphere_0=tmpSphere:CreateScene(ResourcesManager:DataPath() .. "/Resource/Anim/65535/65535_Sphere001_0.xml");
	self.Sphere_0.mTransform:SetLocalPosition(Vector3(0,0,0))
	
	local tmpSphere=SkinMeshParser:new()
	self.Sphere_1=tmpSphere:CreateScene(ResourcesManager:DataPath() .. "/Resource/Anim/65535/65535_Sphere001_1.xml");
	self.Sphere_1.mTransform:SetLocalPosition(Vector3(0,0,0))
	
	local tmpBox001=SkinMeshParser:new()
	self.Box001_0=tmpBox001:CreateScene(ResourcesManager:DataPath() .. "/Resource/Anim/65535/65535_Box001_0.xml");
	self.Box001_0.mTransform:SetLocalPosition(Vector3(0,0,0))
	
	local tmpBox001_1=SkinMeshParser:new()
	self.Box001_1=tmpBox001_1:CreateScene(ResourcesManager:DataPath() .. "/Resource/Anim/65535/65535_Box001_1.xml");
	self.Box001_1.mTransform:SetLocalPosition(Vector3(0,0,0))
	
	local tmpBox001_2=SkinMeshParser:new()
	self.Box001_2=tmpBox001_2:CreateScene(ResourcesManager:DataPath() .. "/Resource/Anim/65535/65535_Box001_2.xml");
	self.Box001_2.mTransform:SetLocalPosition(Vector3(0,0,0))
	
	local tmpBox001=SkinMeshParser:new()
	self.Box001_3=tmpBox001:CreateScene(ResourcesManager:DataPath() .. "/Resource/Anim/65535/65535_Box001_3.xml");
	self.Box001_3.mTransform:SetLocalPosition(Vector3(0,0,0))
	
	local tmpBox001=SkinMeshParser:new()
	self.Box001_4=tmpBox001:CreateScene(ResourcesManager:DataPath() .. "/Resource/Anim/65535/65535_Box001_4.xml");
	self.Box001_4.mTransform:SetLocalPosition(Vector3(0,0,0))
	
	local tmpBox001=SkinMeshParser:new()
	self.Box001_5=tmpBox001:CreateScene(ResourcesManager:DataPath() .. "/Resource/Anim/65535/65535_Box001_5.xml");
	self.Box001_5.mTransform:SetLocalPosition(Vector3(0,0,0))
	
	local tmpBox001=SkinMeshParser:new()
	self.Box001_6=tmpBox001:CreateScene(ResourcesManager:DataPath() .. "/Resource/Anim/65535/65535_Box001_6.xml");
	self.Box001_6.mTransform:SetLocalPosition(Vector3(0,0,0))
	
	local tmpBox001=SkinMeshParser:new()
	self.Box001_7=tmpBox001:CreateScene(ResourcesManager:DataPath() .. "/Resource/Anim/65535/65535_Box001_7.xml");
	self.Box001_7.mTransform:SetLocalPosition(Vector3(0,0,0))
	
	local tmpBox001=SkinMeshParser:new()
	self.Box001_8=tmpBox001:CreateScene(ResourcesManager:DataPath() .. "/Resource/Anim/65535/65535_Box001_8.xml");
	self.Box001_8.mTransform:SetLocalPosition(Vector3(0,0,0))
	
	local tmpBox001=SkinMeshParser:new()
	self.Box001_9=tmpBox001:CreateScene(ResourcesManager:DataPath() .. "/Resource/Anim/65535/65535_Box001_9.xml");
	self.Box001_9.mTransform:SetLocalPosition(Vector3(0,0,0))
	
	local tmpBox001=SkinMeshParser:new()
	self.Box001_10=tmpBox001:CreateScene(ResourcesManager:DataPath() .. "/Resource/Anim/65535/65535_Box001_10.xml");
	self.Box001_10.mTransform:SetLocalPosition(Vector3(0,0,0))
	
	local tmpBox001=SkinMeshParser:new()
	self.Box001_11=tmpBox001:CreateScene(ResourcesManager:DataPath() .. "/Resource/Anim/65535/65535_Box001_11.xml");
	self.Box001_11.mTransform:SetLocalPosition(Vector3(0,0,0))
	
	local tmpBox001=SkinMeshParser:new()
	self.Box001_12=tmpBox001:CreateScene(ResourcesManager:DataPath() .. "/Resource/Anim/65535/65535_Box001_12.xml");
	self.Box001_12.mTransform:SetLocalPosition(Vector3(0,0,0))
	
	local tmpBox001=SkinMeshParser:new()
	self.Box001_13=tmpBox001:CreateScene(ResourcesManager:DataPath() .. "/Resource/Anim/65535/65535_Box001_13.xml");
	self.Box001_13.mTransform:SetLocalPosition(Vector3(0,0,0))
	
	local tmpBox001=SkinMeshParser:new()
	self.Box001_14=tmpBox001:CreateScene(ResourcesManager:DataPath() .. "/Resource/Anim/65535/65535_Box001_14.xml");
	self.Box001_14.mTransform:SetLocalPosition(Vector3(0,0,0))
	
	local tmpBox001=SkinMeshParser:new()
	self.Box001_15=tmpBox001:CreateScene(ResourcesManager:DataPath() .. "/Resource/Anim/65535/65535_Box001_15.xml");
	self.Box001_15.mTransform:SetLocalPosition(Vector3(0,0,0))
	
	local tmpBox001=SkinMeshParser:new()
	self.Box001_16=tmpBox001:CreateScene(ResourcesManager:DataPath() .. "/Resource/Anim/65535/65535_Box001_16.xml");
	self.Box001_16.mTransform:SetLocalPosition(Vector3(0,0,0))
	
	local tmpBox001=SkinMeshParser:new()
	self.Box001_17=tmpBox001:CreateScene(ResourcesManager:DataPath() .. "/Resource/Anim/65535/65535_Box001_17.xml");
	self.Box001_17.mTransform:SetLocalPosition(Vector3(0,0,0))
	
	local tmpBox001=SkinMeshParser:new()
	self.Box001_18=tmpBox001:CreateScene(ResourcesManager:DataPath() .. "/Resource/Anim/65535/65535_Box001_18.xml");
	self.Box001_18.mTransform:SetLocalPosition(Vector3(0,0,0))
	
	local tmpBox001=SkinMeshParser:new()
	self.Box001_19=tmpBox001:CreateScene(ResourcesManager:DataPath() .. "/Resource/Anim/65535/65535_Box001_19.xml");
	self.Box001_19.mTransform:SetLocalPosition(Vector3(0,0,0))
	
	local tmpBox001=SkinMeshParser:new()
	self.Box001_20=tmpBox001:CreateScene(ResourcesManager:DataPath() .. "/Resource/Anim/65535/65535_Box001_20.xml");
	self.Box001_20.mTransform:SetLocalPosition(Vector3(0,0,0))
	
	local tmpBox001=SkinMeshParser:new()
	self.Box001_21=tmpBox001:CreateScene(ResourcesManager:DataPath() .. "/Resource/Anim/65535/65535_Box001_21.xml");
	self.Box001_21.mTransform:SetLocalPosition(Vector3(0,0,0))
	
	-- local tmpSkinMeshParserPlayer=SkinMeshParser:new()
	-- self.TvGirl_CruX_Gloves_7778=tmpSkinMeshParserPlayer:CreateScene(ResourcesManager:DataPath() .. "/Resource/Anim/TvGirl/TvGirl_CruX Gloves_7778.Shape.xml");
	-- self.TvGirl_CruX_Gloves_7778.mTransform:SetLocalPosition(Vector3(0,0,8))
	
	-- local tmpSkinMeshParserPlayer=SkinMeshParser:new()
	-- self.TvGirl_DisclosedII_33798=tmpSkinMeshParserPlayer:CreateScene(ResourcesManager:DataPath() .. "/Resource/Anim/TvGirl/TvGirl_DisclosedII_33798.Shape.xml");
	-- self.TvGirl_DisclosedII_33798.mTransform:SetLocalPosition(Vector3(0,0,8))
	
	-- local tmpSkinMeshParserPlayer=SkinMeshParser:new()
	-- self.TvGirl_finalhair_65512=tmpSkinMeshParserPlayer:CreateScene(ResourcesManager:DataPath() .. "/Resource/Anim/TvGirl/TvGirl_finalhair_65512.Shape.xml");
	-- self.TvGirl_finalhair_65512.mTransform:SetLocalPosition(Vector3(0,0,8))
	
	-- local tmpSkinMeshParserPlayer=SkinMeshParser:new()
	-- self.TvGirl_G3_Pantyhose_5176=tmpSkinMeshParserPlayer:CreateScene(ResourcesManager:DataPath() .. "/Resource/Anim/TvGirl/TvGirl_G3 Pantyhose_5176.Shape.xml");
	-- self.TvGirl_G3_Pantyhose_5176.mTransform:SetLocalPosition(Vector3(0,0,8))
	
	-- local tmpSkinMeshParserPlayer=SkinMeshParser:new()
	-- self.TvGirl_Genesis3Female=tmpSkinMeshParserPlayer:CreateScene(ResourcesManager:DataPath() .. "/Resource/Anim/TvGirl/TvGirl_Genesis3Female.Shape.xml");
	-- self.TvGirl_Genesis3Female.mTransform:SetLocalPosition(Vector3(0,0,8))
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