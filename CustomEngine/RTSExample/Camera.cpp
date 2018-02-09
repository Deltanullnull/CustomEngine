#include "Camera.h"
#include <glm\ext.hpp>


Camera::Camera()
{

	

}


Camera::~Camera()
{
}


void Camera::Move(glm::vec3 direction)
{
	m_position += direction * moveSpeed;

	LookAt(m_position, m_lookDirection, m_up);

}

void Camera::SetRotationHorizontal(float angle)
{
	glm::vec3 direction = glm::vec3(0, 0, -1);

	direction = glm::rotateY(direction, -angle);

	LookAt(m_position, direction, m_up);
}

void Camera::Rotate(float horizontal, float vertical)
{
	angleVertical += vertical;

	angleHorizontal += horizontal;

	//cout << angleHorizontal << ", " << angleVertical << endl;

	glm::mat4 rotationVertical = glm::rotate(angleVertical, glm::vec3(1, 0, 0));

	glm::vec3 direction = glm::mat3(rotationVertical) * glm::vec3(0, 0, -1);
	glm::vec3 up = glm::mat3(rotationVertical) * glm::vec3(0, 1, 0);

	glm::mat4 rotationHorizontal = glm::rotate(angleHorizontal, glm::vec3(0, 1, 0));

	direction = glm::mat3(rotationHorizontal) * direction;
	glm::vec3 right = glm::mat3(rotationHorizontal) * glm::vec3(1, 0, 0);

	up = glm::cross(right, direction);

	LookAt(m_position, direction, up);
}

void Camera::RotateHorizontal(float angle)
{		
	angleHorizontal += angle;

	glm::mat4 rotation = glm::rotate(-angleHorizontal, glm::vec3(0, 1, 0));

	//glm::mat4 rotation = glm::rotate(-angle, glm::vec3(0, 1, 0));

	glm::vec3 direction = glm::mat3(rotation) * glm::vec3(0, 0, -1);
	glm::vec3 right = glm::mat3(rotation) * glm::vec3(1, 0, 0);
	
	glm::vec3 up = glm::cross(right, direction);

	//direction = glm::rotateY(direction, -angle);

	LookAt(m_position, direction, up);
}

void Camera::RotateVertical(float angle)
{
	glm::vec3 direction = m_lookDirection;

	if (abs(angleVertical) < 90.f)
		angleVertical += angle;

	//glm::mat4 rotation = glm::rotate(-angle, GetRightVector());
	glm::mat4 rotation = glm::rotate(-angleVertical, GetRightVector());

	direction = glm::mat3(rotation) * glm::vec3(0, 0, -1);

	//direction = glm::rotate(direction, angle, GetRightVector());

	glm::vec3 up = glm::cross(GetRightVector(), direction);

	//direction = glm::rotateY(direction, -angle);

	LookAt(m_position, direction, up);
}

void Camera::Rotate(glm::mat4 rotation)
{
	
}

void Camera::LookAt(glm::vec3 eye, glm::vec3 direction, glm::vec3 up)
{

	m_position = eye;
	m_lookDirection = glm::normalize(direction);
	m_up = glm::normalize(up);

	m_matView = glm::lookAt(m_position, m_position + m_lookDirection, m_up);
}

void Camera::CreateProjection(float fov, float ratio, float zNear, float zFar)
{
	m_matProjection = glm::perspective(fov / 180.f * glm::pi<float>(), ratio, zNear, zFar);
}

void Camera::PushCameraMatrix(Renderer * renderer)
{
	if (renderer == nullptr)
		return;

	renderer->PushViewMatrix(m_matView);
	renderer->PushProjectionMatrix(m_matProjection);
}

void Camera::PopCameraMatrix(Renderer * renderer)
{
	if (renderer == nullptr)
		return;

	renderer->PopViewMatrix();
	renderer->PopProjectionMatrix();
}

glm::vec3 Camera::GetForwardVector()
{
	glm::vec3 forward = glm::normalize(m_lookDirection);

	return forward;
}

glm::vec3 Camera::GetUpVector()
{
	return m_up;
}

glm::vec3 Camera::GetRightVector()
{
	glm::vec3 forward = GetForwardVector();

	glm::vec3 up = GetUpVector();

	glm::vec3 right = glm::cross(forward, up);

	return right;
}
