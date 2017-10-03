#include "Scene.h"



Scene::Scene()
{
}


Scene::~Scene()
{
}

void Scene::Accept(Traverser * traverser)
{
	if (traverser == nullptr)
		return;

	traverser->Visit(m_pMainCamera);

	// TODO visit light

	for (list<Component *>::iterator it = m_listChildren.begin(); it != m_listChildren.end(); it++)
	{
		Component * child = (*it);

		if (child == nullptr)
			continue;

		child->Accept(traverser);
	}

	traverser->PostVisit(m_pMainCamera);
}

void Scene::SetMainCamera(Camera * camera)
{
	m_pMainCamera = camera;
}
