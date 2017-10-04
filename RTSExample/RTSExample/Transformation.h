#pragma once
#include "Component.h"
#include <glm\ext.hpp>
class Transformation :
	public Component
{
public:
	Transformation();
	~Transformation();

	
	void AddTranslation(glm::vec3 translation);

	void AddRotation(glm::vec3 euler);

	void Accept(Renderer * renderer) override;

private:
	void PushTransformation(Renderer * renderer);
	void PopTransformation(Renderer * renderer);

public:

	Component * m_gameObject;

private:

	glm::mat4 m_translation = glm::mat4(1.0f);;

	glm::mat4 m_rotation = glm::mat4(1.0f);
};

