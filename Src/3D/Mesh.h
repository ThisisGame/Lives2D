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

private:
	int mVertexCount;
	Vertex* mVertexArray;
};

