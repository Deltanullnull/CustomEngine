#include "Renderer.h"



Renderer::Renderer()
{
}


Renderer::~Renderer()
{
}

void Renderer::RenderModel()
{
}

void Renderer::PushModelViewMatrix(mat4 matrix)
{
	modelViewStack.push(matrix);
}

void Renderer::PushProjectionMatrix(mat4 matrix)
{
	projectionStack.push(matrix);
}

void Renderer::PopModelViewMatrix()
{
	if (ModelViewCount() > 0)
		modelViewStack.pop();
}

void Renderer::PopProjectionMatrix()
{
	if (ProjectionCount() > 0)
		projectionStack.pop();
}

mat4 Renderer::ModelViewTop()
{
	if (modelViewStack.size() > 0)
		return modelViewStack.top();

	return mat4();
}

mat4 Renderer::ProjectionTop()
{
	if (ProjectionCount() > 0)
		return projectionStack.top();

	return mat4();
}

void Renderer::SetModelViewTop(mat4 matrix)
{
	modelViewStack.top() = matrix;
}

void Renderer::SetProjectionTop()
{
}

int Renderer::ModelViewCount()
{
	return modelViewStack.size();
}

int Renderer::ProjectionCount()
{
	return projectionStack.size();
}

void Renderer::Traverse(Core * core)
{
	
}
