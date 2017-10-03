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
	
	void AddCore(ShaderCore * core);
	void AddCore(TextureCore * core);
	void AddCore(GeometryCore * core);

	void Accept(Renderer* renderer);

private:

	glm::mat4 m_matModel;

	ShaderCore * m_pShaderCore = NULL;
	TextureCore * m_pTextureCore = NULL;
	GeometryCore * m_pGeometryCore = NULL;

	list<Object*> m_listChildren;

};

