#pragma once

#include<vector>
#include"Light.h"

class LightManager
{
public:
	static LightManager* GetSingleton();

	///Ìí¼ÓÒ»¸öLight
	void AddLight(Light* varLight);

	const std::vector<Light*>& GetLights();

private:
	LightManager();
	~LightManager();

private:
	static LightManager* mSingleton;

	std::vector<Light*> mVectorLight;
};

