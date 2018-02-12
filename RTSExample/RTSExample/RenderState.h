#include "MatrixStack.h"

class ShaderCore;

#pragma once
class RenderState
{
public:
	RenderState();
	~RenderState();

	void PassToShader();

	void SetShader(ShaderCore * core);

private:

	MatrixStack stack;

	ShaderCore * m_shaderCore;
};

	