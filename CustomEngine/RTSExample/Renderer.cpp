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

void Renderer::PushModelMatrix(mat4 matrix)
{
	glm::mat4 matTop = ModelTop();

	//modelStack.push(matrix * matTop);
	modelStack.push(matTop * matrix);
}

void Renderer::PushViewMatrix(mat4 matrix)
{	
	viewStack.push(matrix);
}

void Renderer::PushProjectionMatrix(mat4 matrix)
{
	projectionStack.push(matrix);
}

void Renderer::PushLightMatrix(mat4 matrix)
{
	lightStack.push(matrix);
}

void Renderer::PushLightPosition(vec3 pos)
{
	lightPositionStack.push(pos);
}

void Renderer::PopModelMatrix()
{
	if (ModelCount() > 0)
	{
		modelStack.pop();
	}
}

void Renderer::PopViewMatrix()
{
	if (ViewCount() > 0)
	{
		viewStack.pop();
	}
}

void Renderer::PopProjectionMatrix()
{
	if (ProjectionCount() > 0)
	{
		projectionStack.pop();
	}
}

void Renderer::PopLightMatrix()
{
	if (lightStack.size() > 0)
	{
		lightStack.pop();
	}
}

void Renderer::PopLightPosition()
{
	if (lightPositionStack.size() > 0)
	{
		lightPositionStack.pop();
	}
}

mat4 Renderer::ModelTop()
{
	if (modelStack.size() > 0)
		return modelStack.top();

	return mat4(1.0f);
}

mat4 Renderer::ViewTop()
{
	if (viewStack.size() > 0)
		return viewStack.top();

	return mat4(1.0f);
}

mat4 Renderer::ProjectionTop()
{
	if (ProjectionCount() > 0)
		return projectionStack.top();

	return mat4(1.0f);
}

mat4 Renderer::LightTop()
{
	if (lightStack.size() > 0)
		return lightStack.top();

	return mat4(1.0f);
}

mat4 Renderer::GetModel()
{
	return ModelTop();
}

mat4 Renderer::GetView()
{
	return ViewTop();
}

mat4 Renderer::GetProjection()
{
	return ProjectionTop();
}

mat4 Renderer::GetLight()
{
	return LightTop();
}

vec3 Renderer::GetLightPosition()
{
	if (lightPositionStack.size() > 0)
		return lightPositionStack.top();

	return vec3();
}

void Renderer::SetModelViewTop(mat4 matrix)
{
	viewStack.top() = matrix;
}

void Renderer::SetProjectionTop()
{
}

int Renderer::ModelCount()
{
	return modelStack.size();
}

int Renderer::ViewCount()
{
	return viewStack.size();
}

int Renderer::ProjectionCount()
{
	return projectionStack.size();
}

