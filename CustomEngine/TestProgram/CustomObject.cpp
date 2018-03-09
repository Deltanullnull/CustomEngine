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

	/*if (deltaX != 0 || deltaY != 0)
		printf("DeltaX: %d, %d\n", deltaX, deltaY);*/

	//AddRotation(glm::vec3(deltaX, 0, 0) * 0.01f);

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
	m_transform->AddTranslation(m_transform->forwardVector * 0.1f);
	//m_transform->AddTranslation(vec3(0, 0, 0.1f));
}

void CustomObject::MoveBackwards()
{
	m_transform->AddTranslation(m_transform->forwardVector * -0.1f);
	//m_transform->AddTranslation(vec3(0, 0, -0.1f));
}

void CustomObject::MoveLeft()
{
	m_transform->AddTranslation(m_transform->rightVector * -0.1f);
	//m_transform->AddTranslation(vec3(-0.1f, 0, 0));
}

void CustomObject::MoveRight()
{
	m_transform->AddTranslation(m_transform->rightVector * 0.1f);
	//m_transform->AddTranslation(vec3(0.1f, 0, 0));
}

void CustomObject::MoveDown()
{
	m_transform->AddTranslation(vec3(0, -0.1f, 0));
}

void CustomObject::MoveUp()
{
	m_transform->AddTranslation(vec3(0, 0.1f, 0));
}