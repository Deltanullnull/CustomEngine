#pragma once

#include <stdio.h>


#include <setjmp.h>

#include "TextureCore.h"

class Texture
{
public:
	Texture();
	~Texture();

	static TextureCore * LoadTexture(const char * fileName);
};

