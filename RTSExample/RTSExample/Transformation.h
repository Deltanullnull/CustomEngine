#include "Component.h"

#include "TextureCore.h"
#include "ShaderCore.h"
#include "GeometryCore.h"

#include <glm\glm.hpp>

class Renderer;

#pragma once
class Object
{
public:
	Object();
	~Object();

	void PushTransformation(Renderer * renderer);
	void PopTransformation(Renderer * renderer);

	void Render(Renderer * renderer);

	void AddTranslation(glm::vec3 translation);
	
	/// Shader
	void AddCore(ShaderCore * core);
	
	/// Texture
	void AddCore(TextureCore * core);

	/// Mesh
	void AddCore(GeometryCore * core);

	void Accept(Renderer* renderer);

private:

	glm::mat4 m_matModel = glm::mat4(1.0f);

	glm::vec3 m_position = glm::vec3(0.0f, 0.0f, 0.0f);

	glm::mat4 m_rotation = glm::mat4(1.0f);

	ShaderCore * m_pShaderCore = NULL;
	TextureCore * m_pTextureCore = NULL;
	GeometryCore * m_pGeometryCore = NULL;

	list<Object*> m_listChildren;

};

