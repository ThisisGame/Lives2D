#pragma once

#include "Component.h"
#include "Math/Math.h"


class Transform :
	public Component
{
	DECLEAR_DYNCRT_ACTION(Transform)


public:
	Transform();
	~Transform();

	//**************************************************坐标系相关

public:
	void SetLocalPosition(Vector3 varVector3);

	void SetLocalRotation(Vector3 varVector3);

	void SetLocalScale(Vector3 varVector3);

	Vector3 GetLocalPosition();

	Vector3 GetLocalRotation();

	Vector3 GetLocalScale();

	Vector3 GetPosition();

	void SetPosition(Vector3 varVector3);

private:
	Vector3 mLocalPosition;
	Vector3 mLocalRotation;
	Vector3 mLocalScale;

	Vector3 mPosition;

	//************************************************
};

