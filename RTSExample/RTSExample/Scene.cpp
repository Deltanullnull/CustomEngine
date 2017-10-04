#include "Scene.h"



Scene::Scene()
{
}


Scene::~Scene()
{
}

void Scene::Accept(Renderer * renderer)
{
	if (renderer == nullptr)
		return;

	//traverser->Visit(m_pMainCamera);

	m_pMainCamera->Visit(renderer);

	// TODO visit light

	for (Component * child : m_listChildren)
	{
		if (child == nullptr)
			continue;

		child->Accept(renderer);
	}

	m_pMainCamera->PostVisit(renderer);

	//traverser->PostVisit(m_pMainCamera);
}

void Scene::SetMainCamera(Camera * camera)
{
	m_pMainCamera = camera;
}
