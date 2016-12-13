#pragma once

#include "Renderer.h"

class TextureCore
{
public:
	TextureCore();
	~TextureCore();

	void CreateTexture(GLubyte * imageBuffer, int width, int height);

private:
	GLuint m_texture;
};

