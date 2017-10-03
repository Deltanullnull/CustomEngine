#include "Component.h"
#include "Camera.h"

#pragma once

class Scene : public Component
{
public:
	Scene();
	~Scene();
	
	void Accept(Traverser * traverser);

	void SetMainCamera(Camera * camera);

public:
	Camera * m_pMainCamera;
};

