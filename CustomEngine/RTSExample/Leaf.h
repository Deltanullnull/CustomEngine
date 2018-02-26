#pragma once
#include "Component.h"

class Transformation;

class Leaf :
	public Component
{
public:
	Leaf();
	~Leaf();

	virtual void GetMouseInput(int& x, int& y);

	virtual void Init() = 0;

	virtual void Update() = 0;

public:
	Transformation * m_transform = nullptr;
};

