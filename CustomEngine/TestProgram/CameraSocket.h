#pragma once
#include "./../RTSExample/Behavior.h"

class CameraSocket : public Behavior
{
public:
	CameraSocket();
	~CameraSocket();

	void Init() override;

	void Update() override;

	void MoveForward();

	void MoveBackwards();

	void MoveLeft();

	void MoveRight();

	void MoveDown();

	void MoveUp();

private:

	int mouseX = -1, mouseY = -1;

	float turnRate = 0.01f;


};

