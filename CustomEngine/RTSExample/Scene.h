#include "Component.h"
#include "Camera.h"
#include "Light.h"

#pragma once

class Scene : public Component
{
public:
	Scene();
	~Scene();
	
	void Accept(Traverser * traverser) override;

	void SetMainCamera(Camera * camera);

	void AddLight(Light * light);

public:
	Camera * m_pMainCamera = nullptr;

	std::list<Light*> m_pLights;

	Light * m_pCurrentLight;

};

