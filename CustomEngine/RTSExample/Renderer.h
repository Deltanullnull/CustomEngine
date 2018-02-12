#pragma once

#include "ShaderClass.h"
#include <stack>

using namespace std;
using namespace glm;

class Renderer
{
public:
	Renderer();
	~Renderer();

	void RenderModel();

	void PushModelMatrix(mat4 matrix);
	void PushViewMatrix(mat4 matrix);
	void PushProjectionMatrix(mat4 matrix);

	void PopModelMatrix();
	void PopViewMatrix();
	void PopProjectionMatrix();

	mat4 ModelTop();
	mat4 ViewTop();
	mat4 ProjectionTop();

	mat4 GetModel();
	mat4 GetView();
	mat4 GetProjection();

	void SetModelViewTop(mat4 matrix);
	void SetProjectionTop();

	int ModelCount();
	int ViewCount();
	int ProjectionCount();

private:
	stack<mat4> viewStack;
	stack<mat4> projectionStack;
	stack<mat4> modelStack;

};

