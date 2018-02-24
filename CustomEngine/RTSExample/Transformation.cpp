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
	m_orientation[3][0] += translation.x;
	m_orientation[3][1] += translation.y;
	m_orientation[3][2] += translation.z;

	m_translation = translation;
}

void Transformation::AddRotation(glm::vec3 euler)
{
	glm::mat3 rot3x3 = glm::mat3(glm::yawPitchRoll(euler.x, euler.y, euler.z));

	m_rotation = rot3x3 * m_rotation;

	m_orientation = glm::mat4(m_rotation[0][0], m_rotation[0][1], m_rotation[0][2], m_translation.x,
								m_rotation[1][0], m_rotation[1][1], m_rotation[1][2], m_translation.y,
								m_rotation[2][0], m_rotation[2][1], m_rotation[2][2], m_translation.z,
								0.f, 0.f, 0.f, 1.f);
}

void Transformation::Accept(Traverser * traverser)
{
	if (traverser == nullptr)
		return;

	traverser->Visit(this);

	if (m_gameObject != nullptr)
	{
		m_gameObject->Accept(traverser);
	}

	for (Component * child : m_listChildren)
	{
		if (child == nullptr)
			continue;

		child->Accept(traverser);
	}

	traverser->PostVisit(this);
}

void Transformation::Attach(Leaf * object)
{
	m_gameObject = object;
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

/*void Transformation::AddAction(unsigned char key, std::function<void()> func)
{
	m_gameObject->AddAction(key, func);

	Component::AddAction(key, func);
}*/

void Transformation::UpdateInput()
{
	m_gameObject->UpdateInput();

	Component::UpdateInput();
}

void Transformation::SetWorldOrientation(Renderer * renderer)
{
	m_worldOrientation = m_orientation * renderer->GetModel();
}

void Transformation::Foo()
{
}

/*void Transformation::AddInput(unsigned char key, void(Transformation::* func)(), Transformation & obj)
{
}*/

void Transformation::PushTransformation(Renderer * renderer)
{
	renderer->PushModelMatrix(m_orientation);
	//renderer->PushModelMatrix(m_translation * m_rotation);
}

void Transformation::PopTransformation(Renderer * renderer)
{
	renderer->PopModelMatrix();
}
