#include "Mesh.h"
#include<stdlib.h>
#include<string.h>


Mesh::Mesh():mVertexCount(0),mVertexArray(nullptr),mVertexPositionAnim(nullptr),mApplyedSkin(false)
{
}


Mesh::~Mesh()
{
}

void Mesh::SetVertexCount(int varVertexCount)
{
	mVertexCount = varVertexCount;
}

void Mesh::PushVertexArray(Vertex * varVertex)
{
	mVertexArray = varVertex;
}

glm::vec3 * Mesh::GetVertexPositionAnim()
{
	if (mVertexPositionAnim == nullptr)
	{
		size_t tmpSize = sizeof(glm::vec3)*mVertexCount;
		mVertexPositionAnim = (glm::vec3*)malloc(tmpSize);
		memset(mVertexPositionAnim, 0, tmpSize);
	}
	return mVertexPositionAnim;
}

void Mesh::ApplySkin()
{
	mApplyedSkin = true;
}

const bool& Mesh::GetApplyedSkin()
{
	return mApplyedSkin;
}



Vertex * Mesh::GetVertexArray()
{
	return mVertexArray;
}

const int& Mesh::GetVertexCount()
{
	return mVertexCount;
}

void Mesh::SetVertexIndicesSize(int varVertexIndicesSize)
{
	mVertexIndicesSize = varVertexIndicesSize;
}

#ifdef MINI_MESH
void Mesh::PushVertexIndicesArray(unsigned short * varVertexIndices)
#else
void Mesh::PushVertexIndicesArray(int * varVertexIndices)
#endif
{
	mVertexIndices = varVertexIndices;
}

const int& Mesh::GetVertexIndicesSize()
{
	return mVertexIndicesSize;
}


#ifdef MINI_MESH
unsigned short * Mesh::GetVertexIndices()
#else
int * Mesh::GetVertexIndices()
#endif
{
	return mVertexIndices;
}
