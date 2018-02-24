#pragma once

#include ".\..\RTSExample\Camera.h"

class CustomCamera : public Camera
{
public:
	CustomCamera() ;
	~CustomCamera();

	void Init() override;

	void MoveForward();

	void MoveBackwards();

	void MoveLeft();

	void MoveRight();

};

