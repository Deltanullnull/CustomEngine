#include "Renderer.h"



Renderer::Renderer()
{
}


Renderer::~Renderer()
{
}

void Renderer::renderModel()
{
}

void Renderer::pushModelViewMatrix(mat4 matrix)
{
	modelViewStack.push(matrix);
}

void Renderer::pushProjectionMatrix(mat4 matrix)
{
	projectionStack.push(matrix);
}

void Renderer::popModelViewMatrix()
{
	if (modelViewCount() > 0)
		modelViewStack.pop();
}

void Renderer::popProjectionMatrix()
{
	if (projectionCount() > 0)
		projectionStack.pop();
}

mat4 Renderer::modelViewTop()
{
	if (modelViewStack.size() > 0)
		return modelViewStack.top();

	return mat4();
}

mat4 Renderer::projectionTop()
{
	if (projectionCount() > 0)
		return projectionStack.top();

	return mat4();
}

void Renderer::setModelViewTop(mat4 matrix)
{
	modelViewStack.top() = matrix;
}

void Renderer::setProjectionTop()
{
}

int Renderer::modelViewCount()
{
	return modelViewStack.size();
}

int Renderer::projectionCount()
{
	return projectionStack.size();
}

void Renderer::traverse(Core * core)
{
	
}
