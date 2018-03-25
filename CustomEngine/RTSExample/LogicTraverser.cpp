#include "LogicTraverser.h"



LogicTraverser::LogicTraverser()
{
}


LogicTraverser::~LogicTraverser()
{
}

void LogicTraverser::Visit(Component * component)
{
}

void LogicTraverser::PostVisit(Component * component)
{
}

void LogicTraverser::Visit(Camera * camera)
{
	camera->Update();
}

void LogicTraverser::PostVisit(Camera * camera)
{
}

void LogicTraverser::Visit(Scene * scene)
{
}

void LogicTraverser::PostVisit(Scene * scene)
{
}

void LogicTraverser::Visit(GameObject * gameObject)
{
	gameObject->Update();
}

void LogicTraverser::PostVisit(GameObject * gameObject)
{
}

void LogicTraverser::Visit(Skybox * transformation)
{
	
}

void LogicTraverser::PostVisit(Skybox * transformation)
{
	
}

void LogicTraverser::Visit(Transformation * transformation)
{
	transformation->PushTransformation(m_pRenderer);

	transformation->SetWorldOrientation(m_pRenderer);

	transformation->m_gameObject->Accept(this);
}

void LogicTraverser::PostVisit(Transformation * transformation)
{
	transformation->PopTransformation(m_pRenderer);
}

void LogicTraverser::Visit(Light * light)
{
}

void LogicTraverser::PostVisit(Light * light)
{
}
