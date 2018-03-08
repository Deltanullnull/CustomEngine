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
}

void CustomObject0::Init()
{
	
}

void CustomObject0::Rotate()
{
	AddRotation(m_transform->rightVector, 0.01f);

	//cout << "Rotating right: " << m_transform->rightVector.x << ", " << m_transform->rightVector.y << ", " << m_transform->rightVector.z << endl;
	//AddRotation(glm::vec3(0, 0, 1), 0.01f);
	//AddRotation(glm::vec3(0, 0, 0.01f));
}
