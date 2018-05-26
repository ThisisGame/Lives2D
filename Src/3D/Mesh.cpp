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

const bool Mesh::GetApplyedSkin()
{
	return mApplyedSkin;
}



Vertex * Mesh::GetVertexArray()
{
	return mVertexArray;
}

const unsigned short Mesh::GetVertexCount()
{
	return mVertexCount;
}

void Mesh::SetVertexIndicesSize(unsigned short varVertexIndicesSize)
{
	mVertexIndicesSize = varVertexIndicesSize;
}

void Mesh::PushVertexIndicesArray(unsigned short * varVertexIndices)
{
	mVertexIndices = varVertexIndices;
}

const unsigned short Mesh::GetVertexIndicesSize()
{
	return mVertexIndicesSize;
}



unsigned short * Mesh::GetVertexIndices()
{
	return mVertexIndices;
}
