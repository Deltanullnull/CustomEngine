#include "Scene.h"



Scene::Scene()
{
	cType = "Scene";

	GenerateID();
}


Scene::~Scene()
{
}

void Scene::Accept(Traverser * traverser)
{
	if (traverser == nullptr)
		return;

	traverser->Visit(this);

	// TODO visit light

	for (Component * child : m_listChildren)
	{
		if (child == nullptr)
			continue;

		child->Accept(traverser);
	}

	traverser->PostVisit(this);
}

void Scene::SetMainCamera(Camera * camera)
{
	m_pMainCamera = camera;
}
