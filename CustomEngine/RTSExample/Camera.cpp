#include "Camera.h"
#include <glm\ext.hpp>


Camera::Camera()
{

	m_transform = new Transformation();

	m_transform->Attach(this);

	GenerateID();


}


Camera::~Camera()
{
}


void Camera::LookAt(glm::vec3 eye, glm::vec3 direction, glm::vec3 up)
{
	m_viewMatrix = glm::lookAt(eye, eye + direction, glm::normalize(up));
}

void Camera::CreateProjection(float fov, float ratio, float zNear, float zFar)
{
	m_projectionMatrix = glm::perspective(fov / 180.f * glm::pi<float>(), ratio, zNear, zFar);
}

void Camera::CreateProjection(float left, float right, float bottom, float top, float zNear, float zFar)
{
	m_projectionMatrix = glm::ortho(left, right, bottom, top, zNear, zFar);
}

void Camera::PushCameraMatrix(Renderer * renderer)
{
	if (renderer == nullptr)
		return;

	//m_transform->m_worldOrientation = renderer->GetModel();

	glm::mat4 transformedView = m_transform->m_worldOrientation * m_viewMatrix;

	renderer->PushViewMatrix(transformedView * m_viewMatrix);
	renderer->PushProjectionMatrix(m_projectionMatrix);
}

void Camera::PopCameraMatrix(Renderer * renderer)
{
	if (renderer == nullptr)
		return;

	renderer->PopViewMatrix();
	renderer->PopProjectionMatrix();
}

void Camera::Accept(Traverser * traverser)
{
	traverser->Visit(this);

	traverser->PostVisit(this);
}
