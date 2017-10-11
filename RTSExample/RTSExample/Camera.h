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

	void SetRotationHorizontal(float angle);

	void Rotate(float horizontal, float vertical);

	void RotateHorizontal(float angle);
	void RotateVertical(float angle);

	void Rotate(glm::mat4 rotation);

	void LookAt(glm::vec3 eye, glm::vec3 direction, glm::vec3 up);
	void CreateProjection(float fov, float ratio, float zNear, float zFar);

	void PushCameraMatrix(Renderer * renderer);
	void PopCameraMatrix(Renderer * renderer);

	glm::vec3 GetForwardVector();
	glm::vec3 GetUpVector();
	glm::vec3 GetRightVector();

private:

	glm::mat4 m_matView;
	glm::mat4 m_matProjection;

	glm::vec3 m_position;
	glm::vec3 m_lookDirection;
	glm::vec3 m_up;

	float angleHorizontal = 0.f;
	float angleVertical = 0.f;

	float moveSpeed = 10.f;
};

