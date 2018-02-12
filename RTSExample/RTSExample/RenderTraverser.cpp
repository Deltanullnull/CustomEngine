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

	Visit(scene->m_pMainCamera);
}

void RenderTraverser::PostVisit(Scene * scene)
{
	cout << "Post visit: scene" << endl;

	PostVisit(scene->m_pMainCamera);
}

void RenderTraverser::Visit(GameObject * transformation)
{
	cout << "Visit: object" << endl;

	transformation->Render(m_pRenderer);
}

void RenderTraverser::PostVisit(GameObject * transformation)
{
	cout << "Post visit: object" << endl;
}

void RenderTraverser::Visit(Transformation * transformation)
{
	cout << "Visit: transformation" << endl;

	transformation->PushTransformation(m_pRenderer);

	transformation->m_gameObject->Accept(this);
}

void RenderTraverser::PostVisit(Transformation * transformation)
{
	cout << "Post visit: transformation" << endl;

	transformation->PopTransformation(m_pRenderer);
}

void RenderTraverser::Visit(Light * light)
{
}

void RenderTraverser::PostVisit(Light * light)
{
}
