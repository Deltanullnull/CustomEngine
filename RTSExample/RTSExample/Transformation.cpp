#include "Transformation.h"

#include "Renderer.h"

Transformation::Transformation()
{
}


Transformation::~Transformation()
{
}

void Transformation::PushTransformation(Renderer * renderer)
{
	renderer->pushModelViewMatrix(m_matModel);
}

void Transformation::PopTransformation(Renderer * renderer)
{
	renderer->popModelViewMatrix();
}

void Transformation::Render()
{
	if (m_pShaderCore != NULL)
		m_pShaderCore->BindShader();
	
	if (m_pTextureCore != NULL)
		m_pTextureCore->BindTexture();

	// TODO: bind uniform to shader

	if (m_pGeometryCore != NULL)
		m_pGeometryCore->Render();
}

void Transformation::AddCore(ShaderCore * core)
{
	m_pShaderCore = core;
}

void Transformation::AddCore(TextureCore * core)
{
	m_pTextureCore = core;
}

void Transformation::AddCore(GeometryCore * core)
{
	m_pGeometryCore = core;
}


