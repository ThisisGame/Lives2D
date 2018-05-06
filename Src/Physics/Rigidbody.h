#pragma once
#include "Component/Component.h"
#include"btBulletDynamicsCommon.h"
#include"PhysicsShape.h"


class Rigidbody :
	public Component
{
	DECLEAR_DYNCRT_ACTION(Rigidbody)

public:
	Rigidbody();
	~Rigidbody();

public:
	void Awake() override;

	void OnDestroy() override;

public:
	void SetCollisionShape(int varRigidbodyShape,int varMass, float varX, float varY, float varZ);

private:
	void SetCollisionShape(RigidbodyShape varRigidbodyShape, int varMass, float varX, float varY, float varZ);

private:
	RigidbodyShape mRigidbodyShape;

	btScalar mScalar_X;
	btScalar mScalar_Y;
	btScalar mScalar_Z;
};

