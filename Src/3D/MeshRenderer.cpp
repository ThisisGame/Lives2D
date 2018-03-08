#include "MeshRenderer.h"



MeshRenderer::MeshRenderer()
{
}


MeshRenderer::~MeshRenderer()
{

}

void MeshRenderer::Render()
{
	Renderer::Render();

	mMaterial->Render();
}
