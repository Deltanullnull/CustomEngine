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

	m_mapTextures.insert(make_pair(indexTexture, GL_TEXTURE_2D));

	//m_mapTextures.at(indexTexture) = GL_TEXTURE_2D;

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

void TextureCore::GetSubTexture(GLubyte * imageBuffer, int width, int height, int channels, int x, int y, GLubyte ** outBuffer, int * outWidth, int * outHeight)
{
	int subWidth = width / 4;
	int subHeight = height / 3;

	GLubyte * subBuffer = new GLubyte[subWidth * subHeight * channels];

	for (int v = 0; v < subHeight; v++)
	{
		for (int u = 0; u < subWidth; u++)
		{
			int subIdx = u + v * subWidth;

			int idx = (x * subWidth + u) + (y * subHeight + v) * width;


			subBuffer[subIdx] = imageBuffer[idx];
		}
	}
	
	*outBuffer = subBuffer;
	*outWidth = subWidth;
	*outHeight = subHeight;
}

void TextureCore::AddTextureCubemap(GLubyte * imageBuffer, int width, int height)
{
	GLenum target[] = {
		GL_TEXTURE_CUBE_MAP_NEGATIVE_X,
		GL_TEXTURE_CUBE_MAP_NEGATIVE_Y,
		GL_TEXTURE_CUBE_MAP_NEGATIVE_Z,
		GL_TEXTURE_CUBE_MAP_POSITIVE_X,
		GL_TEXTURE_CUBE_MAP_POSITIVE_Y,
		GL_TEXTURE_CUBE_MAP_POSITIVE_Z
	};
	GLuint indexTexture;

	glGenTextures(1, &indexTexture);

	m_mapTextures.at(indexTexture) = GL_TEXTURE_CUBE_MAP;

	m_listTextures.push_back(indexTexture);

	glBindTexture(GL_TEXTURE_CUBE_MAP, indexTexture);

	int batchCoordinatesX[6] = { 0, 1, 2, 3, 3, 3 };
	int batchCoordinatesY[6] = { 1, 1, 1, 1, 0, 2 };

	for (int i = 0; i < 6; i++)
	{
		// TODO get subset of image
		GLubyte * subTexture;
		int subWidth, subHeight;
		int x = batchCoordinatesX[i];
		int y = batchCoordinatesY[i];
		TextureCore::GetSubTexture(imageBuffer, width, height, 3, x, y, &subTexture, &subWidth, &subHeight);

		glTexImage2D(target[i], 0, GL_RGB, subWidth, subHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, subTexture);
	}
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
