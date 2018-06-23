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

	void BindAwake(const char* varLuaFunctionName);
	void BindOnEnable(const char* varLuaFunctionName);
	void BindStart(const char* varLuaFunctionName);
	void BindUpdate(const char* varLuaFunctionName);
	void BindOnDisable(const char* varLuaFunctionName);
	void BindOnDestroy(const char* varLuaFunctionName);

public:
	std::string mLuaFilePath;


private:
	const char* mLuaFunctionNameAwake;
	const char* mLuaFunctionNameOnEnable;
	const char* mLuaFunctionNameStart;
	const char* mLuaFunctionNameUpdate;
	const char* mLuaFunctionNameOnDisable;
	const char* mLuaFunctionNameOnDestroy;

public:
	void Awake() override;
	void OnEnable() override;
	void Start() override;

	void Update() override;

	void OnDisable() override;
	void OnDestroy() override;
};

