#include <GL\glew.h>
#include <glm\glm.hpp>
#include <stack>

#pragma once

using namespace std;

class MatrixStack
{
public:
	MatrixStack();
	~MatrixStack();

	void PushModelViewMatrix(glm::mat4 matrix);
	void PushProjectionMatrix(glm::mat4 matrix);

	void PopModelViewMatrix();
	void PopProjectionMatrix();

	glm::mat4 ModelViewTop();
	glm::mat4 ProjectionTop();


	void SetModelViewTop(glm::mat4 matrix);
	void SetProjectionTop(glm::mat4 matrix);

	int ModelViewCount();
	int ProjectionCount();

private:
	stack<glm::mat4> stackModelView;
	stack<glm::mat4> stackProjection;

	stack<glm::mat4> stackShadowModelView;
	stack<glm::mat4> stackShadowProjection;
};

