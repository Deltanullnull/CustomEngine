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

	void renderModel();

	void pushModelViewMatrix(mat4 matrix);
	void pushProjectionMatrix(mat4 matrix);

	void popModelViewMatrix();
	void popProjectionMatrix();

	mat4 modelViewTop();
	mat4 projectionTop();

	void setModelViewTop(mat4 matrix);
	void setProjectionTop();

	int modelViewCount();
	int projectionCount();

	void traverse(Core * core);

private:
	stack<mat4> modelViewStack;
	stack<mat4> projectionStack;

};

