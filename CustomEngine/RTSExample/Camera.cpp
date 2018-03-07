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
	//cout << "looking at" << endl;

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

	//cout << m_transform->m_worldOrientation[3][0] << ", " << m_transform->m_worldOrientation[3][1] << ", " << m_transform->m_worldOrientation[3][2] << endl;

	//glm::mat4 transformedView = m_transform->m_worldOrientation * m_viewMatrix;
	glm::mat4 transformedView =  m_viewMatrix * glm::inverse(m_transform->m_worldOrientation);

	//cout << transformedView[3][0] << ", " << transformedView[3][1] << ", " << transformedView[3][2] << endl;
	/*cout << "View:" << endl;
	cout << transformedView[0][0] << ", " << transformedView[1][0] << ", " << transformedView[2][0] << ", " << transformedView[3][0] << endl;
	cout << transformedView[0][1] << ", " << transformedView[1][1] << ", " << transformedView[2][1] << ", " << transformedView[3][1] << endl;
	cout << transformedView[0][2] << ", " << transformedView[1][2] << ", " << transformedView[2][2] << ", " << transformedView[3][2] << endl;*/

	renderer->PushViewMatrix(transformedView);
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
