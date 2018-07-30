#pragma once

#include <stack>
#include <QMatrix4x4>
#include <QVector3d>

class Renderer
{
public:
	Renderer();
	~Renderer();


	void PushModelMatrix(QMatrix4x4 matrix)
	{
		QMatrix4x4 matTop = ModelTop();

		//modelStack.push(matrix * matTop);
		modelStack.push(matTop * matrix);
	}

	void PushViewMatrix(QMatrix4x4 matrix)
	{
		viewStack.push(matrix);
	}

	void PushProjectionMatrix(QMatrix4x4 matrix)
	{
		projectionStack.push(matrix);
	}

	void PushLightMatrix(QMatrix4x4 matrix)
	{
		lightStack.push(matrix);
	}

	void PushLightPosition(QVector3D pos)
	{
		lightPositionStack.push(pos);
	}

	void PopModelMatrix()
	{
		if (ModelCount() > 0)
		{
			modelStack.pop();
		}
	}

	void PopViewMatrix()
	{
		if (ViewCount() > 0)
		{
			viewStack.pop();
		}
	}

	void PopProjectionMatrix()
	{
		if (ProjectionCount() > 0)
		{
			projectionStack.pop();
		}
	}

	void PopLightMatrix()
	{
		if (ProjectionCount() > 0)
		{
			projectionStack.pop();
		}
	}

	void PopLightPosition()
	{
		if (lightPositionStack.size() > 0)
		{
			lightPositionStack.pop();
		}
	}

	QMatrix4x4 ModelTop()
	{
		if (modelStack.size() > 0)
			return modelStack.top();

		return QMatrix4x4();
	}


	QMatrix4x4 ViewTop()
	{
		if (viewStack.size() > 0)
			return viewStack.top();

		return QMatrix4x4();
	}

	QMatrix4x4 ProjectionTop()
	{
		if (ProjectionCount() > 0)
			return projectionStack.top();

		return QMatrix4x4();
	}

	QMatrix4x4 LightTop()
	{
		if (lightStack.size() > 0)
			return lightStack.top();

		return QMatrix4x4();
	}

	QMatrix4x4 GetModel()
	{
		return ModelTop();
	}
	
	QMatrix4x4 GetView()
	{
		return ViewTop();
	}

	QMatrix4x4 GetProjection()
	{
		return ProjectionTop();
	}

	QMatrix4x4 GetLight()
	{
		return LightTop();
	}

	QVector3D GetLightPosition()
	{
		if (lightPositionStack.size() > 0)
			return lightPositionStack.top();

		return QVector3D();
	}

	int ModelCount()
	{
		return modelStack.size();
	}

	int ViewCount()
	{
		return viewStack.size();
	}

	int ProjectionCount()
	{
		return projectionStack.size();
	}


private:
	std::stack<QMatrix4x4> viewStack;
	std::stack<QMatrix4x4> projectionStack;
	std::stack<QMatrix4x4> modelStack;

	std::stack<QVector3D> lightPositionStack;

	std::stack<QMatrix4x4> lightStack;
	std::stack<QMatrix4x4> lightViewStack;
	std::stack<QMatrix4x4> lightProjectionStack;
};

