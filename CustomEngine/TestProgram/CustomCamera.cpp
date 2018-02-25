#include "CustomCamera.h"



CustomCamera::CustomCamera()
{
	m_transform = new Transformation();

	m_transform->Attach(this);

	GenerateID();

	Init();
}


CustomCamera::~CustomCamera()
{
}

void CustomCamera::Init()
{
	AddAction('w', std::bind(&CustomCamera::MoveForward, this));
	AddAction('s', std::bind(&CustomCamera::MoveBackwards, this));
	AddAction('a', std::bind(&CustomCamera::MoveLeft, this));
	AddAction('d', std::bind(&CustomCamera::MoveRight, this));
}


void CustomCamera::MoveForward()
{
	m_transform->AddTranslation(vec3(0, 0, 0.1f));
}

void CustomCamera::MoveBackwards()
{
	m_transform->AddTranslation(vec3(0, 0, -0.1f));
}

void CustomCamera::MoveLeft()
{
	m_transform->AddTranslation(vec3(-0.1f, 0, 0));
}

void CustomCamera::MoveRight()
{
	m_transform->AddTranslation(vec3(0.1f, 0, 0));
}
