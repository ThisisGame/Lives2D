#include "GameObject.h"
#include<Tools/Helper.h>
#include"Transform.h"


GameObject::GameObject(const char * varName):mGameObjectParent(nullptr)
{
	name = varName;

	mTransform = (Transform*)Reflection::CreateInstance("Transform");
	mTransform->mGameObject = this;
}


void GameObject::AddChild(GameObject * varGameObject)
{
	for (size_t tmpChildIndex = 0; tmpChildIndex < mVectorChild.size(); tmpChildIndex++)
	{
		if (mVectorChild[tmpChildIndex] == varGameObject)
		{
			return;
		}

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
			return;
		}
	}
}

void GameObject::Awake()
{
	for (size_t tmpComponentIndex = 0; tmpComponentIndex < mVectorComponent.size(); tmpComponentIndex++)
	{
		Component* tmpComponent = mVectorComponent[tmpComponentIndex];
		tmpComponent->Awake();
	}

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
