#include "Transformation.h"

#include "TextureCore.h"
#include "ShaderCore.h"
#include "GeometryCore.h"


#include <glm\glm.hpp>

class Renderer;
class Behavior;

struct Material
{

};

#pragma once
class GameObject : public Leaf
{
public:
	GameObject();
	~GameObject();

	virtual void Render(Renderer * renderer);

	virtual void RenderDepth(Renderer * renderer);

	void Scale(glm::vec3 scale);

	virtual void Init() override;

	virtual void Update() override;

	virtual void UpdateInput() override;

	virtual void KeyUp(unsigned char key) override;

	virtual void KeyDown(unsigned char key) override;

	virtual void AddTranslation(glm::vec3 translation);

	virtual void AddRotation(glm::vec3 euler);

	void AddRotation(glm::vec3 axis, float angle);
	
	/// Shader
	virtual void AddCore(ShaderCore * core);
	
	/// Texture
	virtual void AddCore(TextureCore * core);

	/// Mesh
	virtual void AddCore(GeometryCore * core);

	virtual void Accept(Traverser* traverser) override;

	virtual void MoveForward(float distance);

	void MoveUp(float distance);

	void AddBehavior(Behavior * behavior);


protected:

	ShaderCore * m_pShaderCore, * m_pShadowShaderCore = NULL;
	TextureCore * m_pTextureCore = NULL;
	GeometryCore * m_pGeometryCore = NULL;

	list<GameObject*> m_listChildren;
	list<Behavior*> m_pListBehaviors;

};

