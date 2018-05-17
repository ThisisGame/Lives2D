#include "PhysicsWorld.h"
#include"Tools/Helper.h"
#include"Component/Transform.h"

btDiscreteDynamicsWorld* PhysicsWorld::sDiscreteDynamicsWorld=nullptr;
btAlignedObjectArray<btCollisionShape*> PhysicsWorld::sAlignedObjectArray_CollisionShapes;
std::map<btRigidBody*, Transform*> PhysicsWorld::sMapRigidBodyToTransform;

IMPLEMENT_DYNCRT_ACTION(PhysicsWorld)
PhysicsWorld::PhysicsWorld()
{
}


PhysicsWorld::~PhysicsWorld()
{
}

void PhysicsWorld::Awake()
{
	///-----initialization_start-----

	///collision configuration contains default setup for memory, collision setup. Advanced users can create their own configuration.
	mCollisionConfiguration = new btDefaultCollisionConfiguration();

	///use the default collision dispatcher. For parallel processing you can use a diffent dispatcher (see Extras/BulletMultiThreaded)
	mCollisionDispatcher = new btCollisionDispatcher(mCollisionConfiguration);

	//btDbvtBroadphase is a good general purpose broadphase. You can also try out btAxis3Sweep.
	mBroadphaseInterface_OverlappingPairCache = new btDbvtBroadphase();

	///the default constraint solver. For parallel processing you can use a different solver (see Extras/BulletMultiThreaded)
	mSequentialImpulseConstraintSolver = new btSequentialImpulseConstraintSolver;

	sDiscreteDynamicsWorld = new btDiscreteDynamicsWorld(mCollisionDispatcher, mBroadphaseInterface_OverlappingPairCache, mSequentialImpulseConstraintSolver, mCollisionConfiguration);

	sDiscreteDynamicsWorld->setGravity(btVector3(0, -10, 0));

	///-----initialization_end-----
}

void PhysicsWorld::OnDestroy()
{
	//cleanup in the reverse order of creation/initialization

	///-----cleanup_start-----

	//remove the rigidbodies from the dynamics world and delete them
	for (int i = sDiscreteDynamicsWorld->getNumCollisionObjects() - 1; i >= 0; i--)
	{
		btCollisionObject* obj = sDiscreteDynamicsWorld->getCollisionObjectArray()[i];
		btRigidBody* body = btRigidBody::upcast(obj);
		if (body && body->getMotionState())
		{
			delete body->getMotionState();
		}
		sDiscreteDynamicsWorld->removeCollisionObject(obj);
		delete obj;
	}

	//delete collision shapes
	for (int j = 0; j < sAlignedObjectArray_CollisionShapes.size(); j++)
	{
		btCollisionShape* shape = sAlignedObjectArray_CollisionShapes[j];
		sAlignedObjectArray_CollisionShapes[j] = 0;
		delete shape;
	}

	//delete dynamics world
	delete sDiscreteDynamicsWorld;

	//delete solver
	delete mSequentialImpulseConstraintSolver;

	//delete broadphase
	delete mBroadphaseInterface_OverlappingPairCache;

	//delete dispatcher
	delete mCollisionDispatcher;

	delete mCollisionConfiguration;

	//next line is optional: it will be cleared by the destructor when the array goes out of scope
	sAlignedObjectArray_CollisionShapes.clear();
}

void PhysicsWorld::AddCollisionShape(btCollisionShape * varCollisionShape)
{
	sAlignedObjectArray_CollisionShapes.push_back(varCollisionShape);
}

void PhysicsWorld::AddRigidBody(btRigidBody * varRigidBody, Transform* varTransform)
{
	sDiscreteDynamicsWorld->addRigidBody(varRigidBody);

	sMapRigidBodyToTransform.insert(std::pair<btRigidBody*, Transform*>(varRigidBody,varTransform));
}

void PhysicsWorld::Simulation()
{
	if (sDiscreteDynamicsWorld == nullptr)
	{
		return;
	}
	sDiscreteDynamicsWorld->stepSimulation(1.f / 60.f, 10);

	//print positions of all objects
	for (int j = sDiscreteDynamicsWorld->getNumCollisionObjects() - 1; j >= 0; j--)
	{
		btCollisionObject* obj = sDiscreteDynamicsWorld->getCollisionObjectArray()[j];
		btRigidBody* body = btRigidBody::upcast(obj);
		btTransform trans;
		if (body && body->getMotionState())
		{
			body->getMotionState()->getWorldTransform(trans);
		}
		else
		{
			trans = obj->getWorldTransform();
		}

		float tmpX = float(trans.getOrigin().getX());
		float tmpY = float(trans.getOrigin().getY());
		float tmpZ = float(trans.getOrigin().getZ());

		//Helper::LOG("world pos object %d = %f,%f,%f\n", j, tmpX, tmpY, tmpZ);

		Transform* tmpTransform = sMapRigidBodyToTransform[body];
		tmpTransform->SetPosition(Vector3(tmpX, tmpY, tmpZ));
	}
}

bool PhysicsWorld::RayTest(btVector3 & varOrigin, btVector3 & varEnd, RaycastHit* varRaycastHit)
{
	btCollisionWorld::ClosestRayResultCallback tmpRayResultCallback(varOrigin, varEnd);
	if (sDiscreteDynamicsWorld == nullptr)
	{
		return false;
	}
	sDiscreteDynamicsWorld->rayTest(varOrigin, varEnd, tmpRayResultCallback);

	if (tmpRayResultCallback.hasHit())
	{
		const char* tmpGameObjectName =(const char*) tmpRayResultCallback.m_collisionObject->getUserPointer();

		btRigidBody* tmpRigidBody = (btRigidBody*)tmpRayResultCallback.m_collisionObject;
		Transform* tmpHitTransform = sMapRigidBodyToTransform[tmpRigidBody];
		varRaycastHit->SetHitGameObject(tmpHitTransform->mGameObject);

		return true;
	}
	else
	{
		return false;
	}
}

