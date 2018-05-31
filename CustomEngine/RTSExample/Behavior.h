#pragma once

#include "Leaf.h"
#include "Transformation.h"


class Behavior : public Leaf
{
public:
	Behavior();
	~Behavior();

	virtual void Init() {}
	virtual void Update() {}
};

