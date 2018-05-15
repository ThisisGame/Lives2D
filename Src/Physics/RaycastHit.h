#pragma once
#include"Math/Math.h"

class GameObject;
class RaycastHit
{
public:
	RaycastHit();
	~RaycastHit();


	float GetDistance();

	void SetPoint(Vector3& varPoint);

	Vector3 GetPoint();

	void SetHitGameObject(GameObject* varGameObject);

	GameObject* GetHitGameObject();

private:
	float mDistance;

	Vector3 mPoint;

	GameObject* mHitGameObject;
};

