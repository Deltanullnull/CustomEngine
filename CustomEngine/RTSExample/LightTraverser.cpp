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
	glBindFramebuffer(GL_FRAMEBUFFER, scene->m_pCurrentLight->frameBuffer);

	scene->m_pCurrentLight->PushTransformation(m_pRenderer);
}

void LightTraverser::PostVisit(Scene * scene)
{
	scene->m_pCurrentLight->PopTransformation(m_pRenderer);

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void LightTraverser::Visit(GameObject * gameObject)
{
	gameObject->RenderDepth(m_pRenderer);
}

void LightTraverser::PostVisit(GameObject * gameObject)
{
}

void LightTraverser::Visit(Skybox * transformation)
{

}

void LightTraverser::PostVisit(Skybox * transformation)
{

}

void LightTraverser::Visit(Transformation * transformation)
{
	transformation->PushTransformation(m_pRenderer);
}

void LightTraverser::PostVisit(Transformation * transformation)
{
	transformation->PopTransformation(m_pRenderer);
}

void LightTraverser::Visit(Light * light)
{
	//light->PushTransformation(m_pRenderer);
	
}

void LightTraverser::PostVisit(Light * light)
{

}
