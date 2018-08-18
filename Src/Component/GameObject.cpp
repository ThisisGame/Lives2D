#include "GameObject.h"
#include<Tools/Helper.h>
#include"Transform.h"
#include"PlayerPrefs/Convert.h"
#include"PlayerPrefs/TinyXml/tinyxml.h"



GameObject::GameObject(const char * varName):mGameObjectParent(nullptr)
{
	name = varName;

	Awake();

	mTransform = (Transform*)Reflection::CreateInstance("Transform");
	mTransform->mGameObject = this;
	mTransform->Awake();
}

std::vector<GameObject*>& GameObject::GetVectorGameObject()
{
	static std::vector<GameObject*> sVectorGameObject;
	return sVectorGameObject;
}

void GameObject::AddChild(GameObject * varGameObject)
{
	bool tmpFind = false;
	for (size_t tmpChildIndex = 0; tmpChildIndex < mVectorChild.size(); tmpChildIndex++)
	{
		if (mVectorChild[tmpChildIndex] == varGameObject)
		{
			tmpFind = true;
			break;
		}
	}
	if (tmpFind == false)
	{

		mVectorChild.push_back(varGameObject);

		//×ø±êÉèÖÃ
		varGameObject->mTransform->SetPosition(mTransform->GetPosition());
	}
}

int GameObject::GetChildCount()
{
	return mVectorChild.size();
}

GameObject * GameObject::GetChild(int varIndex)
{
	if (varIndex < mVectorChild.size())
	{
		GameObject* tmpGameObject = mVectorChild[varIndex];
		return tmpGameObject;
	}
	else
	{
		Helper::LOG("No Much Child");
		return nullptr;
	}
}

GameObject* GameObject::GetChild(const char* varName)
{
	for (size_t i = 0; i < mVectorChild.size(); i++)
	{
		if (strcmp(mVectorChild[i]->name.c_str(), varName) == 0)
		{
			return mVectorChild[i];
		}
	}
	return nullptr;
}

void GameObject::SetParent(GameObject * varGameObjectParent)
{
	mGameObjectParent = varGameObjectParent;
}

GameObject * GameObject::GetParent()
{
	return mGameObjectParent;
}

Component * GameObject::AddComponent(const char * varComponentName)
{
	Component* tmpComponent = Reflection::CreateInstance(varComponentName);
	tmpComponent->Awake();
	tmpComponent->mGameObject = this;
	tmpComponent->mTransform = mTransform;
	mVectorComponent.push_back(tmpComponent);
	return tmpComponent;
}

void GameObject::RemoveComponent(const char * varComponentName)
{
	for (size_t tmpComponentIndex = 0; tmpComponentIndex < mVectorComponent.size(); tmpComponentIndex++)
	{
		Component* tmpComponent = mVectorComponent[tmpComponentIndex];
		if (strcmp( tmpComponent->GetComponentName().c_str(), varComponentName)==0)
		{
			auto tmpIter = mVectorComponent.begin();
			mVectorComponent.erase(tmpIter+tmpComponentIndex);
			tmpComponent->OnDestroy();
			return;
		}
	}
}

Component * GameObject::GetComponent(const char * varComponentName)
{
	for (size_t tmpComponentIndex = 0; tmpComponentIndex < mVectorComponent.size(); tmpComponentIndex++)
	{
		Component* tmpComponent = mVectorComponent[tmpComponentIndex];
		if (strcmp(tmpComponent->GetComponentName().c_str(), varComponentName) == 0)
		{
			return tmpComponent;
		}
	}
	return nullptr;
}

std::vector<Component*> GameObject::GetComponents(const char * varComponentName)
{
	std::vector<Component*> tmpVectorComponent;
	for (size_t tmpComponentIndex = 0; tmpComponentIndex < mVectorComponent.size(); tmpComponentIndex++)
	{
		Component* tmpComponent = mVectorComponent[tmpComponentIndex];
		if (strcmp(tmpComponent->GetComponentName().c_str(), varComponentName) == 0)
		{
			tmpVectorComponent.push_back(tmpComponent);
		}
	}
	return tmpVectorComponent;
}

LuaComponent * GameObject::AddLuaComponent(const char * varFilePath)
{
	LuaComponent* tmpLuaComponent=(LuaComponent*)Reflection::CreateInstance("LuaComponent");
	tmpLuaComponent->mGameObject = this;
	tmpLuaComponent->mTransform = mTransform;
	tmpLuaComponent->DoFile(varFilePath);
	tmpLuaComponent->Awake();
	mVectorLuaComponent.push_back(tmpLuaComponent);
	return tmpLuaComponent;
}

void GameObject::RemoveLuaComponent(const char * varFilePath)
{
	for (size_t tmpLuaComponentIndex = 0; tmpLuaComponentIndex < mVectorLuaComponent.size(); tmpLuaComponentIndex++)
	{
		LuaComponent* tmpLuaComponent = mVectorLuaComponent[tmpLuaComponentIndex];
		if (strcmp(tmpLuaComponent->mLuaFilePath.c_str(), varFilePath) == 0)
		{
			auto tmpIter = mVectorLuaComponent.begin();
			mVectorLuaComponent.erase(tmpIter + tmpLuaComponentIndex);
			tmpLuaComponent->OnDestroy();
			return;
		}
	}
}

void GameObject::Awake()
{
	//for (size_t tmpComponentIndex = 0; tmpComponentIndex < mVectorComponent.size(); tmpComponentIndex++)
	//{
	//	Component* tmpComponent = mVectorComponent[tmpComponentIndex];
	//	tmpComponent->Awake();
	//}

	//for (size_t tmpLuaComponentIndex = 0; tmpLuaComponentIndex < mVectorLuaComponent.size(); tmpLuaComponentIndex++)
	//{
	//	LuaComponent* tmpLuaComponent = mVectorLuaComponent[tmpLuaComponentIndex];
	//	tmpLuaComponent->Awake();
	//}

	for (size_t tmpChildIndex = 0; tmpChildIndex < mVectorChild.size(); tmpChildIndex++)
	{
		mVectorChild[tmpChildIndex]->Awake();
	}
}

void GameObject::OnEnable()
{
	for (size_t tmpComponentIndex = 0; tmpComponentIndex < mVectorComponent.size(); tmpComponentIndex++)
	{
		Component* tmpComponent = mVectorComponent[tmpComponentIndex];
		tmpComponent->Awake();
	}

	for (size_t tmpLuaComponentIndex = 0; tmpLuaComponentIndex < mVectorLuaComponent.size(); tmpLuaComponentIndex++)
	{
		LuaComponent* tmpLuaComponent = mVectorLuaComponent[tmpLuaComponentIndex];
		tmpLuaComponent->Awake();
	}

	for (size_t tmpChildIndex = 0; tmpChildIndex < mVectorChild.size(); tmpChildIndex++)
	{
		mVectorChild[tmpChildIndex]->Awake();
	}
}

void GameObject::Start()
{
	for (size_t tmpComponentIndex = 0; tmpComponentIndex < mVectorComponent.size(); tmpComponentIndex++)
	{
		Component* tmpComponent = mVectorComponent[tmpComponentIndex];
		tmpComponent->Start();
	}

	for (size_t tmpLuaComponentIndex = 0; tmpLuaComponentIndex < mVectorLuaComponent.size(); tmpLuaComponentIndex++)
	{
		LuaComponent* tmpLuaComponent = mVectorLuaComponent[tmpLuaComponentIndex];
		tmpLuaComponent->Start();
	}

	for (size_t tmpChildIndex = 0; tmpChildIndex < mVectorChild.size(); tmpChildIndex++)
	{
		mVectorChild[tmpChildIndex]->Start();
	}
}

void GameObject::Update()
{
	for (size_t tmpComponentIndex = 0; tmpComponentIndex < mVectorComponent.size(); tmpComponentIndex++)
	{
		Component* tmpComponent = mVectorComponent[tmpComponentIndex];
		tmpComponent->Update();
	}

	for (size_t tmpLuaComponentIndex = 0; tmpLuaComponentIndex < mVectorLuaComponent.size(); tmpLuaComponentIndex++)
	{
		LuaComponent* tmpLuaComponent = mVectorLuaComponent[tmpLuaComponentIndex];
		tmpLuaComponent->Update();
	}

	for (size_t tmpChildIndex = 0; tmpChildIndex < mVectorChild.size(); tmpChildIndex++)
	{
		mVectorChild[tmpChildIndex]->Update();
	}
}

void GameObject::OnDisable()
{
	for (size_t tmpComponentIndex = 0; tmpComponentIndex < mVectorComponent.size(); tmpComponentIndex++)
	{
		Component* tmpComponent = mVectorComponent[tmpComponentIndex];
		tmpComponent->OnDisable();
	}

	for (size_t tmpLuaComponentIndex = 0; tmpLuaComponentIndex < mVectorLuaComponent.size(); tmpLuaComponentIndex++)
	{
		LuaComponent* tmpLuaComponent = mVectorLuaComponent[tmpLuaComponentIndex];
		tmpLuaComponent->OnDisable();
	}

	for (size_t tmpChildIndex = 0; tmpChildIndex < mVectorChild.size(); tmpChildIndex++)
	{
		mVectorChild[tmpChildIndex]->OnDisable();
	}
}

void GameObject::OnDestroy()
{
	for (size_t tmpComponentIndex = 0; tmpComponentIndex < mVectorComponent.size(); tmpComponentIndex++)
	{
		Component* tmpComponent = mVectorComponent[tmpComponentIndex];
		if (tmpComponent != nullptr)
		{
			tmpComponent->OnDestroy();
			delete(tmpComponent);
			tmpComponent = nullptr;
		}
	}


	for (size_t tmpLuaComponentIndex = 0; tmpLuaComponentIndex < mVectorLuaComponent.size(); tmpLuaComponentIndex++)
	{
		LuaComponent* tmpLuaComponent = mVectorLuaComponent[tmpLuaComponentIndex];
		if (tmpLuaComponent != nullptr)
		{
			tmpLuaComponent->OnDestroy();
			delete(tmpLuaComponent);
			tmpLuaComponent = nullptr;
		}
	}

	for (size_t tmpChildIndex = 0; tmpChildIndex < mVectorChild.size(); tmpChildIndex++)
	{
		GameObject* tmpGo = mVectorChild[tmpChildIndex];
		if (tmpGo != nullptr)
		{
			tmpGo->OnDestroy();
			delete(tmpGo);
			tmpGo = nullptr;
		}
	}
}



GameObject::~GameObject()
{
}

void GameObject::Destroy(GameObject * varGo)
{
	if (varGo != nullptr)
	{
		varGo->OnDisable();
		varGo->OnDestroy();

		delete(varGo);
		varGo = nullptr;
	}

	
}

void GameObject::InitWithXml(TiXmlElement * varTiXmlElement)
{
	Vector3 tmpLocalPosition = Convert::StringToVector3(varTiXmlElement->Attribute("Position"));
	Vector3 tmpLocalRotation = Convert::StringToVector3(varTiXmlElement->Attribute("Rotation"));
	Vector3 tmpLocalScale = Convert::StringToVector3(varTiXmlElement->Attribute("Scale"));

	mTransform->SetLocalPosition(tmpLocalPosition);
	mTransform->SetLocalRotation(tmpLocalRotation);
	mTransform->SetLocalScale(tmpLocalScale);
 }
