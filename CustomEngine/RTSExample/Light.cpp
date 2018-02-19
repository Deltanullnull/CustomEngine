#include "Light.h"



Light::Light()
{
	InitRenderBuffer();
}


Light::~Light()
{
}

void Light::UpdateOrientation(glm::vec3 position, glm::vec3 direction, glm::vec3 up)
{
	m_position = position;
	m_direction = direction;
	m_up = up;

	m_orientation = glm::lookAt(m_position, m_position + m_direction, m_up);
}

void Light::UpdateProjection(float left, float right, float bottom, float top, float zNear, float zFar)
{
	m_projection = glm::ortho<GLfloat>(left, right, bottom, top, zNear, zFar);
}

void Light::Accept(Traverser * traverser)
{
	traverser->Visit(this);
}

void Light::PushTransformation(Renderer * renderer)
{
	if (renderer == nullptr)
		return;

	renderer->PushViewMatrix(m_orientation);
	renderer->PushProjectionMatrix(m_projection);
}

void Light::PopTransformation(Renderer * renderer)
{
	if (renderer == nullptr)
		return;

	renderer->PopViewMatrix();
	renderer->PopProjectionMatrix();
}

void Light::PushPosition(Renderer * renderer)
{
	if (renderer == nullptr)
		return;

	renderer->PushLightPosition(m_position);
}

void Light::PopPosition(Renderer * renderer)
{
	if (renderer == nullptr)
		return;

	renderer->PopLightPosition();
}

void Light::InitRenderBuffer() // For shadow mapping
{
	glGenTextures(1, &depthTexture);

	glBindTexture(GL_TEXTURE_2D, depthTexture);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT16, 1024, 1024, 0, GL_DEPTH_COMPONENT, GL_FLOAT, 0);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_FUNC, GL_LEQUAL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE, GL_COMPARE_R_TO_TEXTURE);

	
	glGenFramebuffers(1, &frameBuffer);

	glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer);

	glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, depthTexture, 0);
	glDrawBuffer(GL_NONE);

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	
}
