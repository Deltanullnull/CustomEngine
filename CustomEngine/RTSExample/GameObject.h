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

	virtual void Render(Renderer * renderer);

	virtual void Init() = 0;

	virtual void Update() = 0;

	virtual void AddTranslation(glm::vec3 translation);

	virtual void AddRotation(glm::vec3 euler);
	
	/// Shader
	virtual void AddCore(ShaderCore * core);
	
	/// Texture
	virtual void AddCore(TextureCore * core);

	/// Mesh
	virtual void AddCore(GeometryCore * core);

	virtual void Accept(Traverser* traverser) override;

	virtual void MoveForward();

	virtual void AddInput(unsigned char key, void(GameObject::*func) ());

public:

	Transformation * m_transformation = nullptr;

private:

	ShaderCore * m_pShaderCore = NULL;
	TextureCore * m_pTextureCore = NULL;
	GeometryCore * m_pGeometryCore = NULL;

	list<GameObject*> m_listChildren;

	std::map<unsigned char, void (GameObject::*)()> m_functionMap;

};

