#include "Mesh.h"



Mesh::Mesh():mVertexCount(0),mVertexArray(nullptr),mVertexPositionAnim(nullptr)
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

void Mesh::PushVertexPositionAnim(glm::vec3 * varVertexPositionAnim)
{
	if (mVertexPositionAnim != nullptr)
	{
		delete(mVertexPositionAnim);
		mVertexPositionAnim = nullptr;
	}
	mVertexPositionAnim = varVertexPositionAnim;
}

glm::vec3 * Mesh::GetVertexPositionAnim()
{
	return mVertexPositionAnim;
}



Vertex * Mesh::GetVertexArray()
{
	return mVertexArray;
}

int Mesh::GetVertexCount()
{
	return mVertexCount;
}

void Mesh::SetVertexIndicesSize(int varVertexIndicesSize)
{
	mVertexIndicesSize = varVertexIndicesSize;
}

void Mesh::PushVertexIndicesArray(unsigned short * varVertexIndices)
{
	mVertexIndices = varVertexIndices;
}

int Mesh::GetVertexIndicesSize()
{
	return mVertexIndicesSize;
}

unsigned short * Mesh::GetVertexIndices()
{
	return mVertexIndices;
}
