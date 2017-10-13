#include "Traverser.h"
#include "GameObject.h"
#include "Renderer.h"

#include "GeometryCore.h"

#include "Camera.h"
#include "Scene.h"

#pragma once
class RenderTraverser : public Traverser
{
public:
	RenderTraverser();
	~RenderTraverser();

	void Visit(Component * component);
	void PostVisit(Component * component);

	void Visit(Camera * camera);
	void PostVisit(Camera * camera);

	void Visit(Scene * scene);
	void PostVisit(Scene * scene);

	void Visit(GameObject * gameObject);
	void PostVisit(GameObject * gameObject);

	void Visit(Transformation * transformation);
	void PostVisit(Transformation * transformation);

	// TODO: visit for different kinds of component (transformation, geometry, shader, texture etc.)

public:

	// TODO: add matrix stack
	Renderer * m_pRenderer = nullptr;

};

