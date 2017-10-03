#include "Transformation.h"
#include "Camera.h"

#pragma once

class Scene
{
public:
	Scene();
	~Scene();
	
	void Accept(Renderer * renderer);

	void SetMainCamera(Camera * camera);

	void AddChild(Object * child);

public:
	Camera * m_pMainCamera = nullptr;

	list<Object*> m_listChildren;
};

