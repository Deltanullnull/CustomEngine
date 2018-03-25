#pragma once

#include "Traverser.h"
#include "GameObject.h"
#include "Renderer.h"

#include "GeometryCore.h"

#include "Camera.h"
#include "Scene.h"
#include "Light.h"

class LightTraverser : public Traverser
{
public:
	LightTraverser();
	~LightTraverser();

	// Inherited via Traverser
	virtual void Visit(Component * component) override;
	virtual void PostVisit(Component * component) override;
	virtual void Visit(Camera * camera) override;
	virtual void PostVisit(Camera * camera) override;
	virtual void Visit(Scene * scene) override;
	virtual void PostVisit(Scene * scene) override;
	virtual void Visit(GameObject * transformation) override;
	virtual void PostVisit(GameObject * transformation) override;
	void Visit(Skybox * transformation);
	void PostVisit(Skybox * transformation);
	virtual void Visit(Transformation * transformation) override;
	virtual void PostVisit(Transformation * transformation) override;
	virtual void Visit(Light * light) override;
	virtual void PostVisit(Light * light) override;

};

