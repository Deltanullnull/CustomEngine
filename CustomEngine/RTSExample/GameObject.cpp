#include "GameObject.h"

#include "Renderer.h"

GameObject::GameObject()
{
	m_transformation = new Transformation();

	m_transformation->m_gameObject = this;

	GenerateID();
}


GameObject::~GameObject()
{
}

void GameObject::Render(Renderer * renderer)
{
	if (m_pShaderCore != nullptr)
		m_pShaderCore->BindShader();
	
	if (m_pTextureCore != nullptr)
		m_pTextureCore->BindTexture();

	// bind uniform to shader
	glm::mat4 modelView = renderer->GetView() * renderer->GetModel();
	glm::mat4 projection = renderer->GetProjection();

	glm::mat4 mvp = projection * modelView;

	if (m_pShaderCore != nullptr)
		m_pShaderCore->SetUniformMatrix4f("mvp", 1, &mvp[0][0]);

	if (m_pGeometryCore != nullptr)
		m_pGeometryCore->Render();
}

void GameObject::AddTranslation(glm::vec3 translation)
{
	if (m_transformation)
	{
		m_transformation->AddTranslation(translation);
	}
}

void GameObject::AddRotation(glm::vec3 euler)
{
	if (m_transformation)
	{
		m_transformation->AddRotation(euler);
	}
}

void GameObject::AddCore(ShaderCore * core)
{
	m_pShaderCore = core;
}

void GameObject::AddCore(TextureCore * core)
{
	m_pTextureCore = core;
}

void GameObject::AddCore(GeometryCore * core)
{
	m_pGeometryCore = core;
}

void GameObject::Accept(Traverser * traverser)
{
	traverser->Visit(this);

	traverser->PostVisit(this);
}

void GameObject::MoveForward()
{
	AddTranslation(glm::vec3(-0.01f, 0.f, 0.f));
}

void GameObject::AddInput(unsigned char key, void(GameObject::* func)())
{
	m_functionMap[key] = func;
}


