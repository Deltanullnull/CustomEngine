#pragma once

#include "ShaderCore.h"

#include <map>

class TextureCore : Core
{
public:
	TextureCore();
	~TextureCore();

	void AddTexture(GLubyte * imageBuffer, int width, int height);

	void AddTextureCubemap(GLubyte * imageBuffer, int width, int height);

	void BindTexture(ShaderCore * shaderCore);

	void UnbindTexture();

private:
	GLuint m_texture;

	vector<GLuint> m_listTextures;

	map<GLuint, GLenum> m_mapTextures;

};

