#include <GL\glew.h>

class Component;
class Transformation;
class Camera;
class Scene;

#pragma once
class Traverser
{
public:
	Traverser();
	~Traverser();

	virtual void Visit(Component * component) = 0;
	virtual void PostVisit(Component * component) = 0;

	virtual void Visit(Camera * camera) = 0;
	virtual void PostVisit(Camera * camera) = 0;

	virtual void Visit(Scene * scene) = 0;
	virtual void PostVisit(Scene * scene) = 0;

	virtual void Visit(Transformation * transformation) = 0;
	virtual void PostVisit(Transformation * transformation) = 0;
};


