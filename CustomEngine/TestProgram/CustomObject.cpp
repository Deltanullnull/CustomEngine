#include "CustomObject.h"




CustomObject::CustomObject(): GameObject()
{
	Init();
}

CustomObject::~CustomObject()
{
}

void CustomObject::Update()
{
	int deltaX, deltaY;

	GetMouseDelta(deltaX, deltaY);

	AddRotation(m_transform->upVector, -deltaX * 0.01f);
}

void CustomObject::Init()
{
	AddAction('w', std::bind(&CustomObject::MoveForward, this));
	AddAction('s', std::bind(&CustomObject::MoveBackwards, this));
	AddAction('a', std::bind(&CustomObject::MoveLeft, this));
	AddAction('d', std::bind(&CustomObject::MoveRight, this));
	AddAction('e', std::bind(&CustomObject::MoveUp, this));
	AddAction('q', std::bind(&CustomObject::MoveDown, this));
}


void CustomObject::MoveForward()
{
	Transformation * childTransform = (Transformation *) (m_transform->GetChild(0));

	if (childTransform != nullptr)
	{
		glm::mat4 childOrientation = m_transform->m_orientation * childTransform->m_orientation;
		glm::vec3 forward = glm::normalize(glm::vec3(childOrientation[2][0], childOrientation[2][1], childOrientation[2][2]));
		//glm::vec3  up = glm::normalize(glm::vec3(childOrientation[1][0], childOrientation[1][1], childOrientation[1][2]));
		m_transform->AddTranslation(forward * 0.1f);
	}
	
	/*m_transform->AddTranslation(m_transform->forwardVector * 0.1f);*/
}

void CustomObject::MoveBackwards()
{
	Transformation * childTransform = (Transformation *)(m_transform->GetChild(0));

	if (childTransform != nullptr)
	{
		glm::mat4 childOrientation = m_transform->m_orientation * childTransform->m_orientation;
		glm::vec3 forward = glm::normalize(glm::vec3(childOrientation[2][0], childOrientation[2][1], childOrientation[2][2]));
		//glm::vec3  up = glm::normalize(glm::vec3(childOrientation[1][0], childOrientation[1][1], childOrientation[1][2]));
		m_transform->AddTranslation(forward * -0.1f);
	}

	//m_transform->AddTranslation(m_transform->forwardVector * -0.1f);
}

void CustomObject::MoveLeft()
{
	m_transform->AddTranslation(m_transform->rightVector * -0.1f);
}

void CustomObject::MoveRight()
{
	m_transform->AddTranslation(m_transform->rightVector * 0.1f);
}

void CustomObject::MoveDown()
{
	Transformation * childTransform = (Transformation *)(m_transform->GetChild(0));

	if (childTransform != nullptr)
	{
		glm::mat4 childOrientation = m_transform->m_orientation * childTransform->m_orientation;
		glm::vec3  up = glm::normalize(glm::vec3(childOrientation[1][0], childOrientation[1][1], childOrientation[1][2]));
		m_transform->AddTranslation(up * -0.1f);
	}

	//m_transform->AddTranslation(vec3(0, -0.1f, 0));
}

void CustomObject::MoveUp()
{
	Transformation * childTransform = (Transformation *)(m_transform->GetChild(0));

	if (childTransform != nullptr)
	{
		glm::mat4 childOrientation = m_transform->m_orientation * childTransform->m_orientation;
		glm::vec3  up = glm::normalize(glm::vec3(childOrientation[1][0], childOrientation[1][1], childOrientation[1][2]));
		m_transform->AddTranslation(up * 0.1f);
	}

	//m_transform->AddTranslation(vec3(0, 0.1f, 0));
}