local ResourcesManager=require("ResourcesManager")

local SceneWelcom=class()

function SceneWelcom:ctor()
	print("SceneWelcom:ctor")
	self.mUIRoot=nil
	self.mGround=nil
	self.mPlayer=nil
	self.mWomenBody=nil
	print(ResourcesManager:DataPath())
end

--��ʼ��
function SceneWelcom:Init()
	print("SceneWelcom:Init")
	
	
	
	local tmpGoCamera=GameObject:new("sceneCamera")
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
	self.mPlayer.mTransform:SetLocalPosition(Vector3(0,-1,-10))
	local tmpRigidbodyPlayer= self.mPlayer:AddComponent("Rigidbody")
	tmpRigidbodyPlayer:SetCollisionShape(2,1.0,1,0,0)
	
	-- local tmpBox=GameObject:new("Box")
	-- tmpBox.mTransform:SetLocalPosition(Vector3(0,1000,0))
	-- local tmpRigidbody= tmpBox:AddComponent("Rigidbody")
	-- tmpRigidbody:SetCollisionShape(1,1.0,10,10,10)
	
	
	-- local tmpSkinMeshParserWomenBody=SkinMeshParser:new()
	-- self.mWomenBody=tmpSkinMeshParserWomenBody:CreateScene(ResourcesManager:DataPath() .. "/Resource/Anim/Women_3/Women_3.xml");
	
	--local tmpUIParser=UIParser:new()
	--self.mUIRoot=tmpUIParser:CreateUI(ResourcesManager:DataPath() .. "/Resource/UI/UI_Login/UI_Login.xml");
	
	-- local tmpGoUIRoot=GameObject:new("UIROOT")
	-- self.mUIRoot=tmpGoUIRoot:AddComponent("UIRoot")
	
	-- tmpGoUIRoot:AddLuaComponent("WhoSetMeActive.lua")
	
	
	-- local tmpGoImageBg=GameObject:new("mImage_Bg")
	
	-- local	mImage_Bg =tmpGoImageBg:AddComponent("UIImage")
	-- mImage_Bg:Init(ResourcesManager:DataPath() .. "/Resource/GUI/sweep.png",true);
	
	-- mImage_Bg.mTransform:SetLocalPosition(Vector3(0,0,0))
	-- mImage_Bg:SetDepth(0);
	-- self.mUIRoot:AddChild(mImage_Bg);
	
	
	-- local audioSource1 = AudioSource:new()
	-- audioSource1:LoadAudio(ResourcesManager:DataPath().. "/Resource/Audio/m_sound600.wav")
	-- audioSource1:Loop()
	-- audioSource1:Play()

	-- local audioSource2 = AudioSource:new()
	-- audioSource2:LoadAudio(ResourcesManager:DataPath() .. "/Resource/Audio/click.wav")
	
	-- self.mUIRoot=UIRoot:new()

	
	-- local	tmpGoImageCirle =  GameObject:new("ImageCirle")
	-- local	tmpImageCirle =tmpGoImageCirle:AddComponent("UIImage")
	-- tmpImageCirle:Init(ResourcesManager:DataPath() .. "/Resource/GUI/bbg_temple_circle.jpg");
	-- tmpImageCirle:SetPosition(0, 0);
	-- tmpImageCirle:SetDepth(0);
	-- self.mUIRoot:AddChild(tmpImageCirle);

	-- local tmpGoButton=GameObject:new("UIButton")
	-- local mUIButton=tmpGoButton:AddComponent("UIButton")
	-- mUIButton.mTransform:SetLocalPosition(Vector3(100,300,0))
	
	-- mUIButton:Init(ResourcesManager:DataPath() .. "/Resource/GUI/pop_button0.png", ResourcesManager:DataPath() .. "/Resource/GUI/pop_button1.png", 86, 48)
	-- mUIButton:SetOnClickListener(function(varTime)
		-- audioSource2:Play()
	-- end,111)
	-- mUIButton:SetDepth(2);
	-- self.mUIRoot:AddChild(mUIButton)

	-- local mImageAnimation_Angel =  ImageAnimation:new(ResourcesManager:DataPath() .. "/Resource/ImageAnimations/Angel/Animations.txt",1.0/5)
	-- mImageAnimation_Angel:SetPosition(0, 200)
	-- mImageAnimation_Angel:SetScale(0.6, 0.6)
	-- mImageAnimation_Angel:Play("Idle")
	-- mImageAnimation_Angel:SetDepth(1);
	-- self.mUIRoot:AddChild(mImageAnimation_Angel)
	
	-- local	label_name =  UILabel:new()
	-- label_name:Init("label_name");
	-- label_name:SetPosition(0, 0);
	-- label_name:SetDepth(3);
	-- label_name:SetSpace(2)
	-- label_name:SetAlignCenter(true)
	-- self.mUIRoot:AddChild(label_name);
	
	-- local	label_Age =  UILabel:new()
	-- label_Age:Init("label_Age");
	-- label_Age:SetPosition(0, -100);
	-- label_Age:SetDepth(3);
	-- self.mUIRoot:AddChild(label_Age);
	
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
	
end

--����
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
end

return SceneWelcom