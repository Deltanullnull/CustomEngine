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

	modelStack.push(matrix * matTop);
}

void Renderer::PushViewMatrix(mat4 matrix)
{
	//glm::mat4 matTop = ViewTop();
	//viewStack.push(matrix * matTop);

	viewStack.push(matrix);
}

void Renderer::PushProjectionMatrix(mat4 matrix)
{
	//glm::mat4 matTop = ProjectionTop();
	//projectionStack.push(matrix * matTop);

	projectionStack.push(matrix);
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

