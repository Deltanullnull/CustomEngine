#include <GL\glew.h>

class Component;

#pragma once
class Traverser
{
public:
	Traverser();
	~Traverser();

	virtual void Visit(Component * component) = 0;
	virtual void PostVisit(Component * component) = 0;
};

