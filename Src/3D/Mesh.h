#pragma once
#include "Component/Object.h"
#include "Vertex.h"

class Mesh :
	public Object
{
public:
	Mesh();
	~Mesh();

	void SetVertexCount(int varVertexCount);//设置顶点数，同时申请内存

	void PushVertexArray(Vertex* varVertex);//传入顶点数据

	Vertex* GetVertexArray();

	void SetVertexIndicesSize(int varVertexIndicesSize);

	void PushVertexIndicesArray(unsigned short* varVertexIndices);

	int GetVertexIndicesSize();
	unsigned short* GetVertexIndices();

private:
	int mVertexCount;
	Vertex* mVertexArray;

	int mVertexIndicesSize;
	unsigned short* mVertexIndices;
};

