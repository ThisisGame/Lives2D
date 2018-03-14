#include "Mesh.h"



Mesh::Mesh():mVertexCount(0),mVertexArray(nullptr)
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

Vertex * Mesh::GetVertexArray()
{
	return mVertexArray;
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
