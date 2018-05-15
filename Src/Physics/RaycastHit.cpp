#include "RaycastHit.h"

RaycastHit::RaycastHit()
{
}


RaycastHit::~RaycastHit()
{
}

float RaycastHit::GetDistance()
{
	return mDistance;
}

void RaycastHit::SetPoint(Vector3 & varPoint)
{
	mPoint = varPoint;
}

Vector3 RaycastHit::GetPoint()
{
	return mPoint;
}

void RaycastHit::SetHitGameObject(GameObject * varGameObject)
{
	mHitGameObject = varGameObject;
}

GameObject * RaycastHit::GetHitGameObject()
{
	return mHitGameObject;
}



