#pragma once
#include"Math/Math.h"

class GameObject;
class RaycastHit
{
public:
	RaycastHit();
	~RaycastHit();


	float GetDistance();

	Vector3 GetPoint();

private:
	float mDistance;

	Vector3 mPoint;

};

