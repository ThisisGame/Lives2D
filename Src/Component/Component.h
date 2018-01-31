#pragma once
#include "Object.h"
#include<string>
#include"Reflection.h"

class Transform;
class GameObject;
class Component :
	public Object
{
public:
	Component();
	~Component();

	void SetComponentName(std::string varComponentName);

	std::string GetComponentName();

public:
	virtual void Awake() {};
	virtual void OnEnable() {};
	virtual void Start() {};
	
	virtual void Update() {};

	virtual void OnDisable() {};
	virtual void OnDestroy() {};

private:
	std::string mComponentName;

public:
	GameObject* mGameObject;
	Transform* mTransform;
};

