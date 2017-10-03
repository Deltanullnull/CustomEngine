#include "Transformation.h"

#include "Renderer.h"

Object::Object()
{
	glm::mat4 translationMatrix(1.0f);

	translationMatrix[0][3] = m_position.x;
	translationMatrix[1][3] = m_position.y;
	translationMatrix[2][3] = m_position.z;

	m_matModel = m_rotation * translationMatrix;
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
	glm::mat4 modelView = renderer->GetModelView();
	glm::mat4 projection = renderer->GetProjection();

	glm::mat4 mvp = projection * modelView;

	cout << mvp[0][0] << " " << mvp[0][1] << " " << mvp[0][2] << " " << mvp[0][3] << endl;
	cout << mvp[1][0] << " " << mvp[1][1] << " " << mvp[1][2] << " " << mvp[1][3] << endl;
	cout << mvp[2][0] << " " << mvp[2][1] << " " << mvp[2][2] << " " << mvp[2][3] << endl;
	cout << mvp[3][0] << " " << mvp[3][1] << " " << mvp[3][2] << " " << mvp[3][3] << endl;

	if (m_pShaderCore != nullptr)
		m_pShaderCore->SetUniformMatrix4f("mvp", 1, &mvp[0][0]);

	if (m_pGeometryCore != nullptr)
		m_pGeometryCore->Render();
}

void Object::AddTranslation(glm::vec3 translation)
{
	glm::mat4 translationMatrix(1.0f);

	m_position += translation;

	translationMatrix[0][3] = m_position.x;
	translationMatrix[1][3] = m_position.y;
	translationMatrix[2][3] = m_position.z;

	m_matModel = m_rotation * translationMatrix;
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

void Object::Accept(Renderer * renderer)
{
	if (renderer == nullptr)
		return;

	//traverser->Visit(this);

	PushTransformation(renderer);

	Render(renderer);

	for (Object * child : m_listChildren)
	{
		if (child == nullptr)
			continue;

		child->Accept(renderer);
	}

	PopTransformation(renderer);

	//traverser->PostVisit(this);
}


