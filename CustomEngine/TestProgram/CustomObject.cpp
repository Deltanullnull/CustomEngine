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
	

	//cout << "Custom update" << endl;
}

void CustomObject::Init()
{
	AddAction('u', std::bind(&CustomObject::MoveForward, this));
	AddAction('i', std::bind(&CustomObject::MoveDown, this));
}


void CustomObject::MoveForward()
{
	this->AddTranslation(glm::vec3(0.f, 0.f, 0.1f));
}

void CustomObject::MoveDown()
{
	AddTranslation(glm::vec3(0.f, -0.1f, 0.f));
}
