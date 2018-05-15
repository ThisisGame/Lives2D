#pragma once
#include"Math/Math.h"
#include"3D/Camera.h"
#include"RaycastHit.h"

class GameObject;
class Raycast
{
public:
	Raycast();
	~Raycast();

	//从屏幕坐标发射射线
	static bool ScreenPointToRay(Vector3& varScreenTouchPosition, Camera* varCamera,RaycastHit* varRaycastHit);

};

