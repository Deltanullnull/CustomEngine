#include "Transformation.h"



Transformation::Transformation()
{
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

void Transformation::Accept(Renderer * renderer)
{
	if (renderer == nullptr)
		return;

	//traverser->Visit(this);

	PushTransformation(renderer);

	m_gameObject->Accept(renderer);

	for (Component * child : m_listChildren)
	{
		if (child == nullptr)
			continue;

		child->Accept(renderer);
	}

	PopTransformation(renderer);
}

void Transformation::PushTransformation(Renderer * renderer)
{
	//renderer->PushModelViewMatrix(m_rotation * m_translation);
	renderer->PushModelViewMatrix(m_translation * m_rotation);
}

void Transformation::PopTransformation(Renderer * renderer)
{
	renderer->PopModelViewMatrix();
}
