local ResourcesManager=require("ResourcesManager")

local SceneWelcom=class()

function SceneWelcom:ctor()
	print("SceneWelcom:ctor")
	self.mUIRoot=nil
	self.mScene=nil
	print(ResourcesManager:DataPath())
end

--��ʼ��
function SceneWelcom:Init()
	print("SceneWelcom:Init")
	
	local tmpGoCamera=GameObject:new("sceneCamera")
	self.mCamera=tmpGoCamera:AddComponent("Camera")
	
	local tmpSceneParser=SceneParser:new()
	self.mScene=tmpSceneParser:CreateScene(ResourcesManager:DataPath() .. "/Resource/Anim/9000001/9000001.xml");
	
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
	
	if self.mScene~=nil then
		self.mScene:Update()
	end
end

return SceneWelcom