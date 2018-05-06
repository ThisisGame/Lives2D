#pragma once

#include "Component/Component.h"

#include"btBulletDynamicsCommon.h"

#include<map>

class PhysicsWorld :
	public Component
{
	DECLEAR_DYNCRT_ACTION(PhysicsWorld)

public:
	PhysicsWorld();
	~PhysicsWorld();

public:
	void Awake() override;

	void OnDestroy() override;

public:
	static void AddCollisionShape(btCollisionShape* varCollisionShape);

	static void AddRigidBody(btRigidBody* varRigidBody,Transform* varTransform);

	static void Simulation();

private:
	btDefaultCollisionConfiguration* mCollisionConfiguration;

	btCollisionDispatcher* mCollisionDispatcher;

	btBroadphaseInterface* mBroadphaseInterface_OverlappingPairCache;

	btSequentialImpulseConstraintSolver* mSequentialImpulseConstraintSolver;

	static btDiscreteDynamicsWorld* sDiscreteDynamicsWorld;

	//keep track of the shapes, we release memory at exit.
	//make sure to re-use collision shapes among rigid bodies whenever possible!
	static btAlignedObjectArray<btCollisionShape*> sAlignedObjectArray_CollisionShapes;

	static std::map<btRigidBody*, Transform*> sMapRigidBodyToTransform;
};

