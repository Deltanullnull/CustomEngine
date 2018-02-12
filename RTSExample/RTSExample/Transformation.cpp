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

void Transformation::Foo()
{
}

void Transformation::AddInput(unsigned char key, void(Transformation::* func)(), Transformation & obj)
{
}

void Transformation::PushTransformation(Renderer * renderer)
{
	renderer->PushModelMatrix(m_translation * m_rotation);
}

void Transformation::PopTransformation(Renderer * renderer)
{
	renderer->PopModelMatrix();
}
