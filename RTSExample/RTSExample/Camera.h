#include "Component.h"
#include "Renderer.h"

#pragma once
class Camera : Component
{
public:
	Camera();
	~Camera();

	//void Accept(Traverser * traverser);

	void PushCameraMatrix(Renderer * renderer);
	void PopCameraMatrix(Renderer * renderer);

private:

	glm::mat4 m_matView;
	glm::mat4 m_matProjection;

};

