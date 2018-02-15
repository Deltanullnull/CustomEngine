#pragma once

#include "./../RTSExample/GameObject.h"

class CustomObject0 : public GameObject
{
public:
	CustomObject0();
	~CustomObject0();

	virtual void Update() override;
	virtual void Init() override;

};

