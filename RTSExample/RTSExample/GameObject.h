#include "Transformation.h"

#include "TextureCore.h"
#include "ShaderCore.h"
#include "GeometryCore.h"

#include <glm\glm.hpp>

class Renderer;

#pragma once
class GameObject : public Component
{
public:
	GameObject();
	~GameObject();

	void Render(Renderer * renderer);

	void AddTranslation(glm::vec3 translation);

	void AddRotation(glm::vec3 euler);
	
	/// Shader
	void AddCore(ShaderCore * core);
	
	/// Texture
	void AddCore(TextureCore * core);

	/// Mesh
	void AddCore(GeometryCore * core);

	void Accept(Renderer* renderer) override;

	void MoveForward();

	void AddInput(unsigned char key, void(GameObject::*func) ());

public:

	Transformation * m_transformation = nullptr;

private:

	ShaderCore * m_pShaderCore = NULL;
	TextureCore * m_pTextureCore = NULL;
	GeometryCore * m_pGeometryCore = NULL;

	list<GameObject*> m_listChildren;

	std::map<unsigned char, void (GameObject::*)()> m_functionMap;

};

