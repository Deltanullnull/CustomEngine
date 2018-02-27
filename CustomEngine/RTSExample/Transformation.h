#pragma once

#include "Leaf.h"
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

	void Attach(Leaf * object);

	void KeyUp(unsigned char key) override;

	void KeyDown(unsigned char key) override;

	//void AddAction(unsigned char key, std::function<void()>) override;

	void UpdateInput() override;

	void SetWorldOrientation(Renderer * renderer);

	void Foo();

	//void AddInput(unsigned char key, void(Transformation::*func) (), Transformation& obj);


public:
	
	Leaf * m_gameObject;

	glm::mat4 m_orientation = glm::mat4(1.f);

	glm::mat4 m_worldOrientation = glm::mat4(1.f);

private:

	glm::vec3 m_translation = glm::vec3(0.0f);


	glm::mat3 m_rotation = glm::mat3(1.0f);
};

