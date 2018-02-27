#include "CameraSocket.h"



CameraSocket::CameraSocket() : GameObject()
{
	Init();
}


CameraSocket::~CameraSocket()
{
}

void CameraSocket::Init()
{
	AddAction('w', std::bind(&CameraSocket::MoveForward, this));
	AddAction('s', std::bind(&CameraSocket::MoveBackwards, this));
	AddAction('a', std::bind(&CameraSocket::MoveLeft, this));
	AddAction('d', std::bind(&CameraSocket::MoveRight, this));
}

void CameraSocket::Update()
{

}

void CameraSocket::MoveForward()
{
	m_transform->AddTranslation(vec3(0, 0, 0.1f));
}

void CameraSocket::MoveBackwards()
{
	m_transform->AddTranslation(vec3(0, 0, -0.1f));
}

void CameraSocket::MoveLeft()
{
	m_transform->AddTranslation(vec3(0.1f, 0, 0));
}

void CameraSocket::MoveRight()
{
	m_transform->AddTranslation(vec3(-0.1f, 0, 0));
}
