#pragma once
#include "Object.h"
#include"Component.h"
#include<vector>

class Transform;
class GameObject :
	public Object
{

private:
	GameObject();
public:
	GameObject(const char* varName);
	~GameObject();

	static void Destroy(GameObject* varGo);

public:
	std::string name;

	Transform* mTransform;

	//**************************************************父子结构相关

public:

	///添加子物体
	void AddChild(GameObject* varGameObject);

	///获取子物体个数
	int GetChildCount();

	///获取子物体
	GameObject* GetChild(int varIndex);

	///设置父节点
	void SetParent(GameObject* varGameObjectParent);

private:
	std::vector<GameObject*> mVectorChild;//子物体列表

	GameObject* mGameObjectParent;//父节点



	//**************************************************组件
public:
	Component* AddComponent(const char* varComponentName);

	void RemoveComponent(const char* varComponentName);

private:
	std::vector<Component*> mVectorComponent;

	//**************************************************生命周期
public:
	void Awake() ;
	void OnEnable() ;
	void Start() ;

	void Update() ;

	void OnDisable() ;
	void OnDestroy() ;


	
};

