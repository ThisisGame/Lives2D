#include "Rigidbody.h"
#include"PhysicsWorld.h"
#include"PhysicsShape.h"
#include"Component/Transform.h"
#include"Component/GameObject.h"

IMPLEMENT_DYNCRT_ACTION(Rigidbody)
Rigidbody::Rigidbody()
{
}


Rigidbody::~Rigidbody()
{
}

void Rigidbody::Awake()
{
}

void Rigidbody::OnDestroy()
{
}

void Rigidbody::SetCollisionShape(int varRigidbodyShape, int varMass, float varX, float varY, float varZ)
{
	SetCollisionShape((RigidbodyShape)varRigidbodyShape, varMass, varX, varY, varZ);
}

void Rigidbody::SetCollisionShape(RigidbodyShape varRigidbodyShape, int varMass, float varX, float varY, float varZ)
{
	mRigidbodyShape = varRigidbodyShape;
	mScalar_X = btScalar(varX);
	mScalar_Y = btScalar(varY);
	mScalar_Z = btScalar(varZ);

	btCollisionShape* tmpCollisionShape;
	switch (varRigidbodyShape)
	{
		case BoxShape:
		{
			tmpCollisionShape = new btBoxShape(btVector3(btScalar(varX), btScalar(varY), btScalar(varZ)));
			
		}
		break;
		case SphereShape:
		{
			
			tmpCollisionShape = new btSphereShape(btScalar(varX));
			
		}
		break;
		default:
			break;
	}

	PhysicsWorld::AddCollisionShape(tmpCollisionShape);

	btTransform groundTransform;
	groundTransform.setIdentity();


	groundTransform.setOrigin(btVector3(mTransform->GetPosition().mX, mTransform->GetPosition().mY, mTransform->GetPosition().mZ));

	btScalar mass(varMass);

	//rigidbody is dynamic if and only if mass is non zero, otherwise static
	bool isDynamic = (mass != 0.f);

	btVector3 localInertia(0, 0, 0);
	if (isDynamic)
		tmpCollisionShape->calculateLocalInertia(mass, localInertia);

	//using motionstate is optional, it provides interpolation capabilities, and only synchronizes 'active' objects
	btDefaultMotionState* myMotionState = new btDefaultMotionState(groundTransform);
	btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, myMotionState, tmpCollisionShape, localInertia);
	btRigidBody* body = new btRigidBody(rbInfo);

	//add the body to the dynamics world
	PhysicsWorld::AddRigidBody(body, mTransform);

	body->setUserPointer((void*)mGameObject->name.c_str());
}



