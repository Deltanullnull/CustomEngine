#include "Light.h"



Light::Light()
{
}


Light::~Light()
{
}

void Light::UpdateOrientation(glm::vec3 position, glm::vec3 direction, glm::vec3 up)
{
	m_position = position;
	m_direction = direction;
	m_up = up;
}

void Light::UpdateProjection(float left, float right, float bottom, float top, float zNear, float zFar)
{
	m_projection = glm::ortho<GLfloat>(left, right, bottom, top, zNear, zFar);
}

void Light::PushLight(Renderer * renderer)
{
	if (renderer == nullptr)
		return;

	renderer->PushViewMatrix(m_orientation);
	renderer->PushProjectionMatrix(m_projection);
}

void Light::PopLight(Renderer * renderer)
{
	if (renderer == nullptr)
		return;

	renderer->PopViewMatrix();
	renderer->PopProjectionMatrix();
}
