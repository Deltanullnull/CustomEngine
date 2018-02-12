#pragma once

#include "Core.h"

class TextureCore : Core
{
public:
	TextureCore();
	~TextureCore();

	void AddTexture(GLubyte * imageBuffer, int width, int height);

	void BindTexture();

	void UnbindTexture();

private:
	GLuint m_texture;

	vector<GLuint> m_listTextures;


};

