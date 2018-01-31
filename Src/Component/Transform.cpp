#include "Transform.h"
#include"GameObject.h"


IMPLEMENT_DYNCRT_ACTION(Transform)

Transform::Transform()
{
}


Transform::~Transform()
{
}


void Transform::SetLocalPosition(Vector3 varVector3)
{
	mLocalPosition = varVector3;

	mPosition= mGameObject->GetParent()->mTransform->GetPosition() + varVector3;
}

void Transform::SetLocalRotation(Vector3 varVector3)
{
	mLocalRotation = varVector3;
}

void Transform::SetLocalScale(Vector3 varVector3)
{
	mLocalScale = varVector3;
}

Vector3 Transform::GetLocalPosition()
{
	return mLocalPosition;
}

Vector3 Transform::GetLocalRotation()
{
	return mLocalRotation;
}

Vector3 Transform::GetLocalScale()
{
	return mLocalScale;
}

Vector3 Transform::GetPosition()
{
	return mPosition;
}

void Transform::SetPosition(Vector3 varVector3)
{
	mPosition = varVector3;
}
