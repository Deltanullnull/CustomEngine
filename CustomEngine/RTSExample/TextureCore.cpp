#include "TextureCore.h"



TextureCore::TextureCore()
{
}


TextureCore::~TextureCore()
{
}

void TextureCore::AddTexture(GLubyte * imageBuffer, int width, int height)
{
	int nTextures = m_listTextures.size();

	GLuint indexTexture;

	glGenTextures(1, &indexTexture);

	m_listTextures.push_back(indexTexture);

	if (imageBuffer != nullptr)
	{
		glActiveTexture(GL_TEXTURE0 + nTextures);

	
		glBindTexture(GL_TEXTURE_2D, indexTexture);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, imageBuffer);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		glBindTexture(GL_TEXTURE_2D, 0);
	}
}

void TextureCore::AddTextureCubemap(GLubyte * imageBuffer, int width, int height)
{
}

void TextureCore::BindTexture(ShaderCore * shaderCore)
{
	for (int i = 0; i < m_listTextures.size(); i++)
	{
		glActiveTexture(GL_TEXTURE0 + i);
		glBindTexture(GL_TEXTURE_2D, m_listTextures[i]);

		shaderCore->SetUniform1i("tex" + to_string(i), i);
	}
	
}

void TextureCore::UnbindTexture()
{
	for (int i = 0; i < m_listTextures.size(); i++)
	{
		glActiveTexture(GL_TEXTURE0 + i);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}
