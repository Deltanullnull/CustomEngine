#include "Transformation.h"



Transformation::Transformation()
{
	GenerateID();
}


Transformation::~Transformation()
{
}

void Transformation::AddTranslation(glm::vec3 translation)
{
	m_translation[3][0] += translation.x;
	m_translation[3][1] += translation.y;
	m_translation[3][2] += translation.z;
}

void Transformation::AddRotation(glm::vec3 euler)
{
	 m_rotation = glm::yawPitchRoll(euler.x, euler.y, euler.z) * m_rotation;
}

void Transformation::Accept(Traverser * traverser)
{
	if (traverser == nullptr)
		return;

	traverser->Visit(this);

	for (Component * child : m_listChildren)
	{
		if (child == nullptr)
			continue;

		child->Accept(traverser);
	}

	traverser->PostVisit(this);
}

void Transformation::KeyUp(unsigned char key)
{
	m_gameObject->KeyUp(key);

	Component::KeyUp(key);
}

void Transformation::KeyDown(unsigned char key)
{
	m_gameObject->KeyDown(key);

	Component::KeyDown(key);
}

void Transformation::AddAction(unsigned char key, std::function<void(Component*)> func)
{
	m_gameObject->AddAction(key, func);

	Component::AddAction(key, func);
}

void Transformation::UpdateInput()
{
	m_gameObject->UpdateInput();

	Component::UpdateInput();
}

void Transformation::Foo()
{
}

/*void Transformation::AddInput(unsigned char key, void(Transformation::* func)(), Transformation & obj)
{
}*/

void Transformation::PushTransformation(Renderer * renderer)
{
	renderer->PushModelMatrix(m_translation * m_rotation);
}

void Transformation::PopTransformation(Renderer * renderer)
{
	renderer->PopModelMatrix();
}
