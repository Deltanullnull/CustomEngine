#include "Component.h"
#include "Camera.h"

#pragma once

class Scene : public Component
{
public:
	Scene();
	~Scene();
	
	void Accept(Renderer * renderer);

	void SetMainCamera(Camera * camera);

	//void AddChild(Component * child);

public:
	Camera * m_pMainCamera = nullptr;

	//list<Component*> m_listChildren;
};

