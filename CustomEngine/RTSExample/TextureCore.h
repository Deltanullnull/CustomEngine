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
	static void GetSubTexture(GLubyte * imageBuffer, int width, int height, int channels, int x, int y, GLubyte ** outBuffer, int * outWidth, int * outHeight);

private:
	GLuint m_texture;

	vector<GLuint> m_listTextures;

	map<GLuint, GLenum> m_mapTextures;

};

