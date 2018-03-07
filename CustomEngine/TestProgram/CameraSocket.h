#pragma once
#include ".\..\RTSExample\GameObject.h"
class CameraSocket : public GameObject
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

