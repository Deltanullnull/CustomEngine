#include "Texture.h"

#include <jpeglib.h>

Texture::Texture()
{
}


Texture::~Texture()
{
}

TextureCore * Texture::LoadTexture(const char * fileName)
{

	struct my_error_mgr {
		struct jpeg_error_mgr pub;	

		jmp_buf setjmp_buffer;	
	};


	cout << "Load image" << endl;

	jpeg_decompress_struct cinfo;

	FILE * inFile;

	my_error_mgr jerr;

	cinfo.err = jpeg_std_error(&jerr.pub);

	

	if ((inFile = fopen(fileName, "rb")) == nullptr)
	{
		return nullptr;
	}

	if (setjmp(jerr.setjmp_buffer))
	{

	}

	jpeg_create_decompress(&cinfo);

	jpeg_stdio_src(&cinfo, inFile);


	
	cout << "Image loaded" << endl;

	TextureCore * tex = new TextureCore();

	//tex->AddTexture(image.data(), image.width(), image.height());

	return tex;
}
