#include "Texture.h"

#include <jpeglib.h>

Texture::Texture()
{
}


Texture::~Texture()
{
}

TextureCore * Texture::CreateEmpty()
{
	TextureCore * tex = new TextureCore();

	tex->AddTexture(new GLubyte[3]{ (GLubyte)(0.2 * 255), (GLubyte)(0.2 * 255), (GLubyte) (0.2 * 255) }, 1, 1);

	return tex;
}

bool Texture::LoadTexture(const char * fileName, BYTE ** outBuffer, int * outWidth, int * outHeight)
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
		printf("Error opening the file!\n");
		return false;
	}

	if (setjmp(jerr.setjmp_buffer))
	{
		jpeg_destroy_decompress(&cinfo);
		fclose(inFile);
		return false;
	}

	jpeg_create_decompress(&cinfo);

	jpeg_stdio_src(&cinfo, inFile);

	jpeg_read_header(&cinfo, true);

	jpeg_start_decompress(&cinfo);

	int rowStride = cinfo.output_width * cinfo.output_components;

	JSAMPARRAY buffer = (*cinfo.mem->alloc_sarray) ((j_common_ptr)&cinfo, JPOOL_IMAGE, rowStride, 1);

	BYTE * imageBuffer = new BYTE[cinfo.image_width * cinfo.image_height * cinfo.num_components];

	int j = 0;

	while (cinfo.output_scanline < cinfo.output_height)
	{
		jpeg_read_scanlines(&cinfo, buffer, 1);

		// put_scanline_someplace

		for (int i = 0; i < cinfo.image_width * cinfo.num_components; i++)
		{
			imageBuffer[j++] = buffer[0][i];
		}
	}

	jpeg_finish_decompress(&cinfo);

	jpeg_destroy_decompress(&cinfo);

	fclose(inFile);

	*outWidth = cinfo.image_width;
	*outHeight = cinfo.image_height;
	*outBuffer = imageBuffer;

	return true;
}

TextureCore * Texture::CreateTextureCoreFromFile(const char * fileName)
{
	BYTE * imageBuffer;
	int width, height;

	LoadTexture(fileName, &imageBuffer, &width, &height);

	cout << "Image loaded" << endl;

	TextureCore * tex = new TextureCore();

	tex->AddTexture(imageBuffer, width, height);

	return tex;
}

TextureCore * Texture::CreateCubemapCoreFromFile(const char * fileName[6])
{
	BYTE * imageBuffers[6];

	BYTE * imageBuffer;
	int width, height;


	for (int i = 0; i < 6; i++)
	{
		if (!LoadTexture(fileName[i], &imageBuffers[i], &width, &height))
			return nullptr;
	}
	
	TextureCore * tex = new TextureCore();

	tex->AddTextureCubemap(imageBuffers, width, height);

	return tex;
}

TextureCore * Texture::CreateCubemapCoreFromFile(const char * fileName)
{
	BYTE * imageBuffer;
	int width, height;

	if (LoadTexture(fileName, &imageBuffer, &width, &height))
	{
		TextureCore * tex = new TextureCore();

		tex->AddTextureCubemap(imageBuffer, width, height);

		return tex;
	}

	return nullptr;
}
