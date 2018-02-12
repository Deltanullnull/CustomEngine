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
	cout << "Custom update" << endl;
}

void CustomObject::Init()
{
	cout << "Init " << endl;
	AddAction('u', std::bind(&CustomObject::MoveForward, this, std::placeholders::_1));
}


void CustomObject::MoveForward(Component * comp)
{
	GameObject * obj = (GameObject*)comp;

	obj->MoveForward(0.1f);
}