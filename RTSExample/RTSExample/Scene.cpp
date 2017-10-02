#include "Scene.h"



Scene::Scene()
{
}


Scene::~Scene()
{
}

void Scene::SetMainCamera(Camera * camera)
{
	m_pMainCamera = camera;
}
