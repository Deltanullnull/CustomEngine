#pragma once

#include <stdio.h>


#include <setjmp.h>

#include "TextureCore.h"

class Texture
{
public:
	Texture();
	~Texture();

	
	static TextureCore * CreateEmpty();

	static bool LoadTexture(const char * fileName, BYTE ** outBuffer, int * outWidth, int * outHeight);

	static TextureCore * CreateTextureCoreFromFile(const char * fileName);

	static TextureCore * LoadCubemap(const char * fileName);
};

