#include "LightManager.h"

LightManager* LightManager::mSingleton;

LightManager * LightManager::GetSingleton()
{
	if (mSingleton == nullptr)
	{
		mSingleton = new LightManager();
	}
	return mSingleton;
}

void LightManager::AddLight(Light* varLight)
{
	mVectorLight.push_back(varLight);
}

const std::vector<Light*>& LightManager::GetLights()
{
	return mVectorLight;
}

LightManager::LightManager()
{
}


LightManager::~LightManager()
{
}
