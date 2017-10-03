#include "RenderTraverser.h"



RenderTraverser::RenderTraverser()
{
}


RenderTraverser::~RenderTraverser()
{
}

void RenderTraverser::Visit(Component * component)
{
	cout << "Visit: component" << endl;
}

void RenderTraverser::PostVisit(Component * component)
{
	cout << "Post visit: component" << endl;
}

void RenderTraverser::Visit(Camera * camera)
{
	cout << "Visit: camera" << endl;

	camera->PushCameraMatrix(m_pRenderer);
}

void RenderTraverser::PostVisit(Camera * camera)
{
	cout << "Post visit: camera" << endl;

	camera->PopCameraMatrix(m_pRenderer);
}

void RenderTraverser::Visit(Scene * scene)
{
	cout << "Visit: scene" << endl;
}

void RenderTraverser::PostVisit(Scene * scene)
{
	cout << "Post visit: scene" << endl;
}

void RenderTraverser::Visit(Object * transformation)
{
	cout << "Visit: transformation" << endl;

	transformation->PushTransformation(m_pRenderer);	

	transformation->Render();
}

void RenderTraverser::PostVisit(Object * transformation)
{
	cout << "Post visit: transformation" << endl;

	transformation->PopTransformation(m_pRenderer);
}
