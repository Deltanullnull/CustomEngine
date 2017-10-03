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

	m_pMainCamera->Accept(renderer);

	// TODO visit light

	for (Object * child : m_listChildren)
	{
		if (child == nullptr)
			continue;

		child->Accept(renderer);
	}

	//traverser->PostVisit(m_pMainCamera);
}

void Scene::SetMainCamera(Camera * camera)
{
	m_pMainCamera = camera;
}

void Scene::AddChild(Object * child)
{
	m_listChildren.push_back(child);
}
