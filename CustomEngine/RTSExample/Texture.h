#pragma once

#include <setjmp.h>

#include <stdio.h>

class Texture
{
public:
	Texture();
	~Texture();

	static void LoadTexture(const char * fileName);
};

