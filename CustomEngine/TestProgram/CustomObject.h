#pragma once

#include "./../RTSExample/GameObject.h"

class CustomObject : public GameObject
{
public:
	CustomObject();
	~CustomObject();

	virtual void Update() override;
	virtual void Init() override;

	void MoveForward(Component * comp);
	void MoveDown(Component * comp);

	

};

