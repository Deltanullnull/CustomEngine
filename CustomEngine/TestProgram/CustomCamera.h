#pragma once

#include ".\..\RTSExample\Camera.h"

class CustomCamera : public Camera
{
public:
	CustomCamera() ;
	~CustomCamera();

	virtual void Init() override;

	virtual void Update() override;

	void MoveForward();

	void MoveBackwards();

	void MoveLeft();

	void MoveRight();

};

