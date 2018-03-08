#pragma once

#include "./../RTSExample/GameObject.h"

class CustomObject : public GameObject
{
public:
	CustomObject();
	~CustomObject();

	virtual void Update() override;
	virtual void Init() override;

	void MoveForward();
	void MoveBackwards();
	void MoveLeft();
	void MoveRight();
	void MoveDown();

	void MoveUp();
	

};

