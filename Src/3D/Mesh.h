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

	glm::vec3* GetVertexPositionAnim();

	void ApplySkin();

	bool GetApplyedSkin();

	Vertex* GetVertexArray();

	int GetVertexCount();

	void SetVertexIndicesSize(int varVertexIndicesSize);

	void PushVertexIndicesArray(unsigned short* varVertexIndices);

	int GetVertexIndicesSize();
	unsigned short* GetVertexIndices();

private:
	int mVertexCount;
	Vertex* mVertexArray;

	glm::vec3* mVertexPositionAnim;

	int mVertexIndicesSize;
	unsigned short* mVertexIndices;

	bool mApplyedSkin;
};

