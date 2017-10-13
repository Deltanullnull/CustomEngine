#include "LightTraverser.h"



LightTraverser::LightTraverser()
{
}


LightTraverser::~LightTraverser()
{
}

void LightTraverser::Visit(Component * component)
{
}

void LightTraverser::PostVisit(Component * component)
{
}

void LightTraverser::Visit(Camera * camera)
{
}

void LightTraverser::PostVisit(Camera * camera)
{
}

void LightTraverser::Visit(Scene * scene)
{
}

void LightTraverser::PostVisit(Scene * scene)
{
}

void LightTraverser::Visit(GameObject * transformation)
{
}

void LightTraverser::PostVisit(GameObject * transformation)
{
}

void LightTraverser::Visit(Transformation * transformation)
{
}

void LightTraverser::PostVisit(Transformation * transformation)
{
}

void LightTraverser::Visit(Light * light)
{
	// Push view and projection from light
}

void LightTraverser::PostVisit(Light * light)
{
	// Pop view and projection from light
}
