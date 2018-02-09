#pragma once

#include "ShaderCore.h"
#include "Geometry.h"

class Model
{
public:
	Model();
	~Model();

	void render(Renderer * renderer);
private:
	ShaderCore * shader_core;

	Geometry * geometry_core;

};

