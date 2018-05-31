#pragma once

#include "./../RTSExample/Behavior.h"

class MovementScript : public Behavior
{
public:
	MovementScript();
	~MovementScript();

	void Init() override;
	void Update() override;
	void MoveForward();
	void MoveBackwards();
	void MoveLeft();
	void MoveRight();
	void MoveDown();
	void MoveUp();
};

