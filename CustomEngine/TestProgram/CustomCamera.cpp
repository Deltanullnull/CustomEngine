#include "CustomCamera.h"



CustomCamera::CustomCamera() : Camera()
{

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

void CustomCamera::Update()
{
	int mX, mY;
	GetMouseInput(mX, mY);

	printf("Mouse at: %d, %d \n", mX, mY);
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
