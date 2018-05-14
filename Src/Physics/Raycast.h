#pragma once
#include"Math/Math.h"
#include"3D/Camera.h"

class GameObject;
class Raycast
{
public:
	Raycast();
	~Raycast();


	void RaycastScreenPosToWorld(int varScreenX, int varScreenY, Camera* varCamera, Vector3& varOrigin, Vector3& varDirection);

};

