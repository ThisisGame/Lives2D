#pragma once

#include<glm/glm.hpp>

struct  Vector3
{
	float mX;
	float mY;
	float mZ;

	Vector3() {}

	Vector3(float varX, float varY, float varZ)
	{
		mX = varX;
		mY = varY;
		mZ = varZ;
	}
};

class Math
{
public:
	static glm::vec3 Vector3ToGlm(Vector3 varVector3)
	{
		glm::vec3 tmpVec3(varVector3.mX, varVector3.mY, varVector3.mZ);
		return tmpVec3;
	}


	static Vector3 GlmToVector(glm::vec3 varVec3)
	{
		Vector3 tmpVector3(varVec3.x, varVec3.y, varVec3.z);
		return tmpVector3;
	}
};




