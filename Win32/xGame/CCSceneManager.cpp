#include "CCSceneManager.h"
#include "SceneWelcome.h"

CCSceneManager* CCSceneManager::m_Instance=NULL;

CCSceneManager* CCSceneManager::SharedInstance()
{
	if(m_Instance==nullptr)
	{
		m_Instance=new CCSceneManager();
	}
	return m_Instance;
}

void CCSceneManager::Update()
{
	SCENE_MAP::iterator iter=m_SceneMap.begin();
	for (iter;iter!=m_SceneMap.end();iter++)
	{
		(iter->second)->Update();
	}
}

void CCSceneManager::Draw()
{
	SCENE_MAP::iterator iter=m_SceneMap.begin();
	for (iter;iter!=m_SceneMap.end();iter++)
	{
		(iter->second)->Draw();
	}
}

//×¢²áScene
void CCSceneManager::RegisterScene(SCENE_TYPE type,CCSceneBase* scene)
{
	SCENE_MAP::iterator iter=m_SceneMap.find(type);
	if(iter!=m_SceneMap.end())
	{
		std::cout<<"ÖØ¸´×¢²áScene£¡£¡£¡£¡£¡"<<std::endl;
		return;
	}
	m_SceneMap.insert(std::map<SCENE_TYPE,CCSceneBase*>::value_type(type,scene));
}


void CCSceneManager::RegisterAllScene()
{
	Helper::CCLOG("CCSceneManager::RegisterAllScene");
	REGISTER_SCENE(SCENE_WELCOME,SceneWelcome);
}

CCSceneManager::CCSceneManager(void)
{

}


CCSceneManager::~CCSceneManager(void)
{
}
