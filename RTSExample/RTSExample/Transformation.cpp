#include "Transformation.h"

#include "Renderer.h"

Object::Object()
{
}


Object::~Object()
{
}

void Object::PushTransformation(Renderer * renderer)
{
	renderer->PushModelViewMatrix(m_matModel);
}

void Object::PopTransformation(Renderer * renderer)
{
	renderer->PopModelViewMatrix();

}

void Object::Render(Renderer * renderer)
{
	if (m_pShaderCore != nullptr)
		m_pShaderCore->BindShader();
	
	if (m_pTextureCore != nullptr)
		m_pTextureCore->BindTexture();

	

	// TODO: bind uniform to shader
	glm::mat4 modelView = renderer->ModelViewTop();
	glm::mat4 projection = renderer->ProjectionTop();

	glm::mat4 mvp = projection * modelView;

	m_pShaderCore->SetUniformMatrix4f("mvp", 1, &mvp[0][0]);

	if (m_pGeometryCore != nullptr)
		m_pGeometryCore->Render();
}

void Object::AddCore(ShaderCore * core)
{
	m_pShaderCore = core;
}

void Object::AddCore(TextureCore * core)
{
	m_pTextureCore = core;
}

void Object::AddCore(GeometryCore * core)
{
	m_pGeometryCore = core;
}


