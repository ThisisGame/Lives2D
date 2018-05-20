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
	print(ResourcesManager:DataPath())
end

--��ʼ��
function SceneWelcom:Init()
	print("SceneWelcom:Init")
	
	
	
	local tmpGoCamera=GameObject:new("sceneCamera")
	tmpGoCamera.mTransform:SetLocalPosition(Vector3(0,0.5,10))
	tmpGoCamera.mTransform:SetLocalRotation(Vector3(0,0,0))
	self.mCamera=tmpGoCamera:AddComponent("Camera")
	
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
	
	local tmpSkinMeshParserPlayer=SkinMeshParser:new()
	self.TvGirl_Genesis3Female=tmpSkinMeshParserPlayer:CreateScene(ResourcesManager:DataPath() .. "/Resource/Anim/TvGirl/TvGirl_Genesis3Female.Shape.xml");
	self.TvGirl_Genesis3Female.mTransform:SetLocalPosition(Vector3(0,0,8))
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