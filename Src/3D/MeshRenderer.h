#pragma once
#include "Renderer.h"
class MeshRenderer :
	public Renderer
{
public:
	MeshRenderer();
	~MeshRenderer();

	void Render() override;
};

