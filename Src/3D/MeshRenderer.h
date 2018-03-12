#pragma once
#include "Renderer.h"
class MeshRenderer :
	public Renderer
{
	DECLEAR_DYNCRT_ACTION(MeshRenderer)

public:
	MeshRenderer();
	~MeshRenderer();
};

