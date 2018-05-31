#include "MovementScript.h"



MovementScript::MovementScript()
{
}


MovementScript::~MovementScript()
{
}

void MovementScript::Init()
{
}

void MovementScript::Update()
{
	AddAction('w', std::bind(&MovementScript::MoveForward, this));
	AddAction('s', std::bind(&MovementScript::MoveBackwards, this));
	AddAction('a', std::bind(&MovementScript::MoveLeft, this));
	AddAction('d', std::bind(&MovementScript::MoveRight, this));
	AddAction('e', std::bind(&MovementScript::MoveUp, this));
	AddAction('q', std::bind(&MovementScript::MoveDown, this));
}


void MovementScript::MoveForward()
{
	Transformation * childTransform = (Transformation *)(m_transform->GetChild(0));

	if (childTransform != nullptr)
	{
		glm::mat4 childOrientation = m_transform->m_orientation * childTransform->m_orientation;
		glm::vec3 forward = glm::normalize(glm::vec3(childOrientation[2][0], childOrientation[2][1], childOrientation[2][2]));
		//glm::vec3  up = glm::normalize(glm::vec3(childOrientation[1][0], childOrientation[1][1], childOrientation[1][2]));
		m_transform->AddTranslation(forward * 0.1f);
	}

	/*m_transform->AddTranslation(m_transform->forwardVector * 0.1f);*/
}

void MovementScript::MoveBackwards()
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

void MovementScript::MoveLeft()
{
	m_transform->AddTranslation(m_transform->rightVector * -0.1f);
}

void MovementScript::MoveRight()
{
	m_transform->AddTranslation(m_transform->rightVector * 0.1f);
}

void MovementScript::MoveDown()
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

void MovementScript::MoveUp()
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