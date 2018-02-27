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
	
}

void CustomCamera::Update()
{
	int mX, mY;
	GetMouseInput(mX, mY);

	//printf("Mouse at: %d, %d \n", mX, mY);
}


