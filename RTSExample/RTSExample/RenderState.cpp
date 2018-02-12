#include "RenderState.h"

#include "ShaderCore.h"

RenderState::RenderState()
{
}


RenderState::~RenderState()
{
}

void RenderState::PassToShader()
{
}

void RenderState::SetShader(ShaderCore * core)
{
	m_shaderCore = core;
}

