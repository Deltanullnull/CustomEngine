#include "CustomObject0.h"
#include "CustomObject.h"




CustomObject0::CustomObject0() : GameObject()
{
	Init();
}

CustomObject0::~CustomObject0()
{
}

void CustomObject0::Update()
{
	Rotate();

	cout << "Custom update" << endl;
}

void CustomObject0::Init()
{
	cout << "Init " << endl;
}

void CustomObject0::Rotate()
{
	AddRotation(glm::vec3(0, 0, 0.01f));
}
