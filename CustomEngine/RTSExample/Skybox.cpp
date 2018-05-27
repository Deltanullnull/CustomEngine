#include "Skybox.h"



Skybox::Skybox() : GameObject()
{
	Init();
}


Skybox::~Skybox()
{
}

void Skybox::Render(Renderer * renderer)
{
	glDisable(GL_DEPTH_TEST);

	if (m_pShaderCore != nullptr)
	{
		m_pShaderCore->BindShader();
		if (m_pTextureCore != nullptr)
			m_pTextureCore->BindTexture(m_pShaderCore);
	}


	// bind uniform to shader

	glm::mat4 modelMatrix = renderer->GetModel();

	glm::mat4 view = renderer->GetView();

	view[3][0] = 0;
	view[3][1] = 0;
	view[3][2] = 0;

	//glm::mat4 projection = glm::ortho<float>(-100.0, 100.0, -100.0, 100.0, 0, 1000);
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
	}
	if (m_pGeometryCore != nullptr)
		m_pGeometryCore->Render();

	if (m_pShaderCore != nullptr)
	{

		if (m_pTextureCore != nullptr)
			m_pTextureCore->UnbindTexture();
	}

	glEnable(GL_DEPTH_TEST);
}
