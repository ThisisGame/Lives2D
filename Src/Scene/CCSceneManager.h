#pragma once
#include<iostream>
#include<map>
#include"CCSceneBase.h"
#include"Helper.h"

#define REGISTER_SCENE(SCENETYPE,SCENECLASS) \
	SCENECLASS* p ## SCENECLASS = new SCENECLASS(); \
	RegisterScene(SCENETYPE,p ## SCENECLASS); \

enum SCENE_TYPE
{
	SCENE_WELCOME,
	SCENE_MAIN,
	SCENE_COUNT
};

class CCSceneManager
{
public:
	static CCSceneManager* SharedInstance();


	//Update 负责逻辑更新
	void Update();

	//Draw负责界面更新
	void Draw();

	//注册Scene
	void RegisterScene(SCENE_TYPE type,CCSceneBase* scene);

	//注册所有的Scene
	void RegisterAllScene();

private:
	CCSceneManager();
	~CCSceneManager();

private:
	static CCSceneManager* m_Instance;

	typedef std::map<SCENE_TYPE,CCSceneBase*> SCENE_MAP;
	SCENE_MAP m_SceneMap;
};

