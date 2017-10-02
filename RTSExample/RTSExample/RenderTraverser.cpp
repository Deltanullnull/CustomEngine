#include "RenderTraverser.h"



RenderTraverser::RenderTraverser()
{
}


RenderTraverser::~RenderTraverser()
{
}

void RenderTraverser::Visit(Component * component)
{
	
}

void RenderTraverser::PostVisit(Component * component)
{
}

void RenderTraverser::Visit(Camera * camera)
{
	camera->PushCameraMatrix(renderer);
}

void RenderTraverser::PostVisit(Camera * camera)
{
	camera->PopCameraMatrix(renderer);
}

void RenderTraverser::Visit(Transformation * transformation)
{
	transformation->PushTransformation(renderer);	

	transformation->Render();
}

void RenderTraverser::PostVisit(Transformation * transformation)
{
	transformation->PopTransformation(renderer);
}
