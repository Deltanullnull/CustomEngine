#pragma once
#include "Core.h"

#include <glm\glm.hpp>

class AnimationCore :
	public Core
{
public:
	AnimationCore();
	~AnimationCore();

	void SetWeights(GLfloat * weights, int nBones, int nVertices)
	{

	}
};

