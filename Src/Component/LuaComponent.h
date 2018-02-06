#pragma once
#include "Component.h"

#include<string>

class LuaComponent :
	public Component
{
	DECLEAR_DYNCRT_ACTION(LuaComponent)
public:
	LuaComponent();
	~LuaComponent();

	void DoFile(const char* varFilePath);

public:
	std::string mLuaFilePath;

private:
	int mAwakeIndex;
	int mOnEnableIndex;
	int mStartIndex;
	int mUpdateIndex;
	int mOnDisableIndex;
	int mOnDestroyIndex;

public:
	void Awake() override;
	void OnEnable() override;
	void Start() override;

	void Update() override;

	void OnDisable() override;
	void OnDestroy() override;
};

