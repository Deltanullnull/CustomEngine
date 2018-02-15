#pragma once

#include "Component.h"

class Light : public Component
{
public:
	Light();
	~Light();

	void UpdateOrientation(glm::vec3 position, glm::vec3 direction, glm::vec3 up);
	void UpdateProjection(float left, float right, float bottom, float top, float zNear, float zFar);

	void Accept(Traverser * traverser) override;

	void PushTransformation(Renderer * renderer);
	void PopTransformation(Renderer * renderer);

	void PushPosition(Renderer * renderer);
	void PopPosition(Renderer * renderer);

public:

	glm::mat4 m_projection = glm::mat4(1.0f);
	glm::mat4 m_orientation = glm::mat4(1.0f);
	
	glm::vec3 m_position;
	glm::vec3 m_direction;
	glm::vec3 m_up;

	float strength = 1.f;

};

