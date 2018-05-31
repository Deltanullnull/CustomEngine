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
	/*m_orientation[3][0] += translation.x;
	m_orientation[3][1] += translation.y;
	m_orientation[3][2] += translation.z;*/

	m_transMat = glm::translate(m_transMat, translation);

	m_translation += translation;
}

void Transformation::AddRotation(glm::vec3 euler)
{
	glm::mat3 rot3x3 = glm::mat3(glm::yawPitchRoll(euler.x, euler.y, euler.z));

	m_rotMat = glm::yawPitchRoll(euler.x, euler.y, euler.z) * m_rotMat;

	forwardVector = glm::normalize(glm::vec3(m_rotMat[2][0], m_rotMat[2][1], m_rotMat[2][2]));
	rightVector = -glm::normalize(glm::vec3(m_rotMat[0][0], m_rotMat[0][1], m_rotMat[0][2]));
	upVector = glm::normalize(glm::vec3(m_rotMat[1][0], m_rotMat[1][1], m_rotMat[1][2]));

}

void Transformation::Scale(glm::vec3 euler)
{
	m_scaleMat[0][0] = euler.x;
	m_scaleMat[1][1] = euler.y;
	m_scaleMat[2][2] = euler.z;
}

void Transformation::AddRotation(glm::vec3 axis, float angle)
{
	m_rotMat = glm::rotate(angle, axis) * m_rotMat;

	forwardVector = glm::normalize(glm::vec3(m_rotMat[2][0], m_rotMat[2][1], m_rotMat[2][2]));
	rightVector = -glm::normalize(glm::vec3(m_rotMat[0][0], m_rotMat[0][1], m_rotMat[0][2]));
	upVector = glm::normalize(glm::vec3(m_rotMat[1][0], m_rotMat[1][1], m_rotMat[1][2]));
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

void Transformation::PushTransformation(Renderer * renderer)
{
	m_orientation = m_scaleMat * m_transMat * m_rotMat;

	renderer->PushModelMatrix(m_orientation);
}

void Transformation::PopTransformation(Renderer * renderer)
{
	renderer->PopModelMatrix();
}
