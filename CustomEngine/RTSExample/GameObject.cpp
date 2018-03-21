#include "GameObject.h"

#include "Renderer.h"

GameObject::GameObject()
{
	m_transform = new Transformation();

	m_transform->Attach(this);

	GenerateID();

	Init();
}


GameObject::~GameObject()
{
}

void GameObject::Render(Renderer * renderer)
{
	if (m_pShaderCore != nullptr)
	{
		m_pShaderCore->BindShader();
		if (m_pTextureCore != nullptr)
			m_pTextureCore->BindTexture(m_pShaderCore);
	}
	

	// bind uniform to shader

	glm::mat4 modelMatrix = renderer->GetModel();
	glm::mat4 view = renderer->GetView();
	glm::mat4 projection = renderer->GetProjection();

	glm::mat4 modelView = view * modelMatrix;

	glm::mat4 mvp = projection * modelView;

	glm::mat4 lightMatrix = renderer->GetLight();

	glm::vec3 lightPosition = renderer->GetLightPosition();

	if (m_pShaderCore != nullptr)
	{
		m_pShaderCore->SetUniformMatrix4f("modelView", 1, &modelView[0][0]);
		m_pShaderCore->SetUniformMatrix4f("view", 1, &view[0][0]);
		m_pShaderCore->SetUniformMatrix4f("mvp", 1, &mvp[0][0]);

		m_pShaderCore->SetUniformMatrix4f("light", 1, &lightMatrix[0][0]);

		m_pShaderCore->SetUniformVector3f("lightPosition", 1, &lightPosition[0]);

	}
	if (m_pGeometryCore != nullptr)
		m_pGeometryCore->Render();

	if (m_pShaderCore != nullptr)
	{
		
		if (m_pTextureCore != nullptr)
			m_pTextureCore->UnbindTexture();
	}
}

void GameObject::RenderDepth(Renderer * renderer)
{
	if (m_pShadowShaderCore != nullptr)
		m_pShadowShaderCore->BindShader();

	
	// bind uniform to shader
	glm::mat4 modelView = renderer->GetView() * renderer->GetModel();
	glm::mat4 view = renderer->GetView();
	glm::mat4 projection = renderer->GetProjection();

	glm::mat4 mvp = projection * modelView;

	if (m_pShadowShaderCore != nullptr)
	{
		m_pShadowShaderCore->SetUniformMatrix4f("modelView", 1, &modelView[0][0]);
		m_pShadowShaderCore->SetUniformMatrix4f("view", 1, &view[0][0]);
		m_pShadowShaderCore->SetUniformMatrix4f("mvp", 1, &mvp[0][0]);

		
	}
	if (m_pGeometryCore != nullptr)
		m_pGeometryCore->Render();
}

void GameObject::AddTranslation(glm::vec3 translation)
{
	if (m_transform)
	{
		m_transform->AddTranslation(translation);
	}
}

void GameObject::AddRotation(glm::vec3 euler)
{
	if (m_transform)
	{
		m_transform->AddRotation(euler);
	}
}

void GameObject::AddRotation(glm::vec3 axis, float angle)
{
	if (m_transform)
	{
		m_transform->AddRotation(axis, angle);
	}
}

void GameObject::AddCore(ShaderCore * core)
{
	m_pShaderCore = core;

	string vertexShader = m_pShaderCore->m_pVertexShader;
	string geometryShader = m_pShaderCore->m_pGeometryShader;
	

	string shaderRoot = "./../glsl/"; // TODO get root of other shaders
	string fragmentShader = shaderRoot + "default.frag";

	m_pShadowShaderCore = new ShaderCore();
	m_pShadowShaderCore->GenerateShader(vertexShader, geometryShader, fragmentShader);

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

void GameObject::MoveForward(float distance)
{
	AddTranslation(glm::vec3(0.f, 0.f, distance));
}

void GameObject::MoveUp(float distance)
{
	AddTranslation(glm::vec3(0.f, distance, 0.f));
}