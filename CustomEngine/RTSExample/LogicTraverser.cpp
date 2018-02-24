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

void LogicTraverser::Visit(Transformation * transformation)
{
	transformation->SetWorldOrientation(m_pRenderer);

	transformation->m_gameObject->Accept(this);
}

void LogicTraverser::PostVisit(Transformation * transformation)
{
}

void LogicTraverser::Visit(Light * light)
{
}

void LogicTraverser::PostVisit(Light * light)
{
}
