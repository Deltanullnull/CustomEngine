#include "Traverser.h"
#include "Transformation.h"
#include "Renderer.h"

#include "GeometryCore.h"

#include "Camera.h"

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


	void Visit(Transformation * transformation);


	void PostVisit(Transformation * transformation);

	// TODO: visit for different kinds of component (transformation, geometry, shader, texture etc.)

private:

	// TODO: add matrix stack
	Renderer * renderer;

};

