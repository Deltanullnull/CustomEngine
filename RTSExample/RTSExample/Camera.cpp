#include "Camera.h"



Camera::Camera()
{
}


Camera::~Camera()
{
}

void Camera::Visit(Renderer * renderer)
{
	PushCameraMatrix(renderer);
	
}

void Camera::PostVisit(Renderer * renderer)
{
	PopCameraMatrix(renderer);
}

void Camera::Move(glm::vec3 direction)
{
	m_position += direction;

	m_lookAt += direction;

	m_matView = glm::lookAt(m_position, m_lookAt, m_up);
}

void Camera::Rotate(glm::mat4 rotation)
{
	
}

void Camera::LookAt(glm::vec3 eye, glm::vec3 target, glm::vec3 up)
{
	m_position = eye;
	m_lookAt = target;
	m_up = up;

	m_matView = glm::lookAt(eye, target, up);
}

void Camera::CreateProjection(float fov, float ratio, float zNear, float zFar)
{
	m_matProjection = glm::perspective(fov / 180.f * glm::pi<float>(), ratio, zNear, zFar);
}

void Camera::PushCameraMatrix(Renderer * renderer)
{
	if (renderer == nullptr)
		return;

	renderer->PushModelViewMatrix(m_matView);
	renderer->PushProjectionMatrix(m_matProjection);
}

void Camera::PopCameraMatrix(Renderer * renderer)
{
	if (renderer == nullptr)
		return;

	renderer->PopModelViewMatrix();
	renderer->PopProjectionMatrix();
}
