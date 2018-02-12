#include "MatrixStack.h"



MatrixStack::MatrixStack()
{
}


MatrixStack::~MatrixStack()
{
}

void MatrixStack::PushModelViewMatrix(glm::mat4 matrix)
{
	stackModelView.push(matrix);
}

void MatrixStack::PushProjectionMatrix(glm::mat4 matrix)
{
	stackProjection.push(matrix);
}

void MatrixStack::PopModelViewMatrix()
{
	if (ModelViewCount() > 0)
		stackModelView.pop();
}

void MatrixStack::PopProjectionMatrix()
{
	if (ProjectionCount() > 0)
		stackProjection.pop();
}

glm::mat4 MatrixStack::ModelViewTop()
{
	if (stackModelView.size() > 0)
		return stackModelView.top();

	return glm::mat4();
}

glm::mat4 MatrixStack::ProjectionTop()
{
	if (ProjectionCount() > 0)
		return stackProjection.top();

	return glm::mat4();
}

void MatrixStack::SetModelViewTop(glm::mat4 matrix)
{
	stackModelView.top() = matrix;
}

void MatrixStack::SetProjectionTop(glm::mat4 matrix)
{
	stackProjection.top() = matrix;
}

int MatrixStack::ModelViewCount()
{
	return stackModelView.size();
}

int MatrixStack::ProjectionCount()
{
	return stackProjection.size();
}
