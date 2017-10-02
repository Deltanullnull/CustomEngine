#include "Camera.h"



Camera::Camera()
{
}


Camera::~Camera()
{
}

void Camera::PushCameraMatrix(Renderer * renderer)
{
	renderer->pushModelViewMatrix(m_matView);
	renderer->pushModelViewMatrix(m_matProjection);
}

void Camera::PopCameraMatrix(Renderer * renderer)
{
	renderer->popModelViewMatrix();
	renderer->popProjectionMatrix();
}
