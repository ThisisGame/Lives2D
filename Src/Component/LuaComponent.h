#pragma once
#include "Component.h"

#include<string>
#include<map>

struct map_cmp_str
{
	bool operator()(char const* a, char const* b) const
	{
		return std::strcmp(a, b) < 0;
	}
};

class LuaComponent :
	public Component
{
	DECLEAR_DYNCRT_ACTION(LuaComponent)
public:
	LuaComponent();
	~LuaComponent();

	void DoFile(const char* varFilePath);

	
	///Bind a Function to a key in lua code,then we can call lua function by global functionname
	void Bind(const char* varKey,const char* varLuaFunctionName);

	void Invoke(const char* varKey);

	void Invoke(const char* varKey, Transform* varTransA, Transform* varTransB);

public:
	std::string mLuaFilePath;


private:
	

	std::map<const char*, const char*, map_cmp_str> mBindLuaFunctionMap;

public:
	void Awake() override;
	void OnEnable() override;
	void Start() override;

	void Update() override;

	void OnDisable() override;
	void OnDestroy() override;
};

