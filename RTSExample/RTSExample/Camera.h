#include "Component.h"
#include "Renderer.h"

#pragma once
class Camera 
{
public:
	Camera();
	~Camera();

	void Visit(Renderer * renderer);
	void PostVisit(Renderer * renderer);

	void Move(glm::vec3 direction);

	void Rotate(glm::mat4 rotation);

	void LookAt(glm::vec3 eye, glm::vec3 target, glm::vec3 up);
	void CreateProjection(float fov, float ratio, float zNear, float zFar);

	void PushCameraMatrix(Renderer * renderer);
	void PopCameraMatrix(Renderer * renderer);

private:

	glm::mat4 m_matView;
	glm::mat4 m_matProjection;

	glm::vec3 m_position;
	glm::vec3 m_lookAt;
	glm::vec3 m_up;
};

