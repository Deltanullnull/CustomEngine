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

	void PushLightPosition(vec3 pos);

	void PopModelMatrix();
	void PopViewMatrix();
	void PopProjectionMatrix();

	void PopLightPosition();

	mat4 ModelTop();
	mat4 ViewTop();
	mat4 ProjectionTop();

	mat4 GetModel();
	mat4 GetView();
	mat4 GetProjection();

	vec3 GetLightPosition();

	void SetModelViewTop(mat4 matrix);
	void SetProjectionTop();

	int ModelCount();
	int ViewCount();
	int ProjectionCount();

private:
	stack<mat4> viewStack;
	stack<mat4> projectionStack;
	stack<mat4> modelStack;

	stack<vec3> lightPositionStack;

	stack<mat4> lightStack;
	stack<mat4> lightViewStack;
	stack<mat4> lightProjectionStack;

};

