#pragma once
#include "GameObject.h"
class Skybox : public GameObject
{
public:
	Skybox();
	~Skybox();
	void Render(Renderer * renderer) override;
};

