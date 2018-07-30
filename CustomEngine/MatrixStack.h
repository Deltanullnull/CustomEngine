#pragma once

#include <QMatrix4x4>
#include <stack>

class MatrixStack
{

public:
	MatrixStack() {}
	~MatrixStack() {}

	void PushModelViewMatrix(QMatrix4x4 matrix)
	{
		stackModelView.push(matrix);
	}

	void PushProjectionMatrix(QMatrix4x4 matrix)
	{
		stackProjection.push(matrix);
	}

	void PopModelViewMatrix()
	{
		if (ModelViewCount() > 0)
			stackModelView.pop();
	}

	void PopProjectionMatrix()
	{
		if (ProjectionCount() > 0)
			stackProjection.pop();
	}

	QMatrix4x4 ModelViewTop()
	{
		if (stackModelView.size() > 0)
			return stackModelView.top();

		return QMatrix4x4();
	}


	QMatrix4x4 ProjectionTop()
	{
		if (ProjectionCount() > 0)
			return stackProjection.top();

		return QMatrix4x4();
	}


	void SetModelViewTop(QMatrix4x4 matrix)
	{
		stackModelView.top() = matrix;
	}


	void SetProjectionTop(QMatrix4x4 matrix)
	{
		stackProjection.top() = matrix;
	}

	int ModelViewCount()
	{
		return stackModelView.size();
	}

	int ProjectionCount()
	{
		return stackProjection.size();
	}

private:
	std::stack<QMatrix4x4> stackModelView;
	std::stack<QMatrix4x4> stackProjection;

	std::stack<QMatrix4x4> stackShadowModelView;
	std::stack<QMatrix4x4> stackShadowProjection;
};