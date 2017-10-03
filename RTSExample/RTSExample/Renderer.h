#pragma once

#include "ShaderClass.h"
#include "Core.h"
#include <stack>

using namespace std;
using namespace glm;

class Renderer
{
public:
	Renderer();
	~Renderer();

	void RenderModel();

	void PushModelViewMatrix(mat4 matrix);
	void PushProjectionMatrix(mat4 matrix);

	void PopModelViewMatrix();
	void PopProjectionMatrix();

	mat4 ModelViewTop();
	mat4 ProjectionTop();

	void SetModelViewTop(mat4 matrix);
	void SetProjectionTop();

	int ModelViewCount();
	int ProjectionCount();

	void Traverse(Core * core);

private:
	stack<mat4> modelViewStack;
	stack<mat4> projectionStack;

};

