#pragma once
#include "Component.h"
#include <glm\ext.hpp>
class Transformation :
	public Component
{
public:
	Transformation();
	~Transformation();

	void PushTransformation(Renderer * renderer);
	void PopTransformation(Renderer * renderer);
	
	void AddTranslation(glm::vec3 translation);

	void AddRotation(glm::vec3 euler);

	void Accept(Traverser * traverser) override;

	void KeyUp(unsigned char key) override;

	void KeyDown(unsigned char key) override;

	void AddAction(unsigned char key, std::function<void(Component*)>) override;

	void UpdateInput() override;

	void Foo();

	void AddInput(unsigned char key, void(Transformation::*func) (), Transformation& obj);


public:

	Component * m_gameObject;

private:

	glm::mat4 m_translation = glm::mat4(1.0f);;

	glm::mat4 m_rotation = glm::mat4(1.0f);
};

