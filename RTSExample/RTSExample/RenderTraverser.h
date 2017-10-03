#include "Traverser.h"
#include "Transformation.h"
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

	void Visit(Object * transformation);
	void PostVisit(Object * transformation);

	// TODO: visit for different kinds of component (transformation, geometry, shader, texture etc.)

public:

	// TODO: add matrix stack
	Renderer * m_pRenderer;

};

