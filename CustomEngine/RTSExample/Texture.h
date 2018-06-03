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

	static bool LoadJPG(const char * fileName, BYTE ** outBuffer, int * outWidth, int * outHeight);

	static bool LoadPNG(const char * fileName, BYTE ** outBuffer, int * outWidth, int * outHeight);

	static bool LoadTexture(const char * fileName, BYTE ** outBuffer, int * outWidth, int * outHeight);

	static TextureCore * CreateTextureCoreFromFile(const char * fileName);

	static TextureCore * CreateCubemapCoreFromFile(const char * fileName[6]);

	static TextureCore * CreateCubemapCoreFromFile(const char * fileName);
};

