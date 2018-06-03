#include "Texture.h"

#include <jpeglib.h>

#define PNG_DEBUG 3
#include <png.h>
#include <boost/filesystem.hpp>

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

bool Texture::LoadJPG(const char * fileName, BYTE ** outBuffer, int * outWidth, int * outHeight)
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

bool Texture::LoadPNG(const char * fileName, BYTE ** outBuffer, int * outWidth, int * outHeight)
{
	
	FILE * fp = fopen(fileName, "rb");
	if (!fp)
		return false;

	png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);
	if (!png)
		return false;

	png_infop info = png_create_info_struct(png);
	if (!info)
		return false;

	if (setjmp(png_jmpbuf(png)))
		return false;

	png_init_io(png, fp);

	png_read_info(png, info);

	int width = png_get_image_width(png, info);
	int height = png_get_image_height(png, info);
	int colorType = png_get_color_type(png, info);
	int bitDepth = png_get_bit_depth(png, info);

	cout << "PNG has" << width << ", " << height << ", " << colorType << ", " << bitDepth << endl;

	if (bitDepth == 16)
		png_set_strip_16(png);

	if (colorType == PNG_COLOR_TYPE_PALETTE)
		png_set_palette_to_rgb(png);

	if (colorType == PNG_COLOR_TYPE_GRAY && bitDepth < 8)
	{
		png_set_expand_gray_1_2_4_to_8(png);
	}

	png_read_update_info(png, info);

	png_bytep * row_pointers = (png_bytep*)malloc(sizeof(png_bytep) * height);
	for (int y = 0; y < height; y++)
	{
		row_pointers[y] = (png_byte*)malloc(png_get_rowbytes(png, info));
	}

	png_read_image(png, row_pointers);

	fclose(fp);

	BYTE * buffer = new BYTE[width * height * 3];

	for (int y = 0; y < height; y++)
	{
		png_byte * row = row_pointers[y];
		for (int x = 0; x < width; x++)
		{
			int idx = (height - y - 1) * width + ( x ) ;
			png_byte * ptr = &(row[x * 4]);
			buffer[idx * 3 + 0] = ptr[0];
			buffer[idx * 3 + 1] = ptr[1];
			buffer[idx * 3 + 2] = ptr[2];
			//buffer[idx * 4 + 3] = ptr[3];
		}
	}

	*outBuffer = buffer;
	*outWidth = width;
	*outHeight = height;

	return true;
}

bool Texture::LoadTexture(const char * fileName, BYTE ** outBuffer, int * outWidth, int * outHeight)
{
	// TODO get extension
	string ext = boost::filesystem::extension(fileName);

	cout << "Extension of file: " << ext << endl;
	if (ext == ".jpg")
	{
		return LoadJPG(fileName, outBuffer, outWidth, outHeight);
	}
	else if (ext == ".png")
	{
		return LoadPNG(fileName, outBuffer, outWidth, outHeight);
	}

	return false;
}

TextureCore * Texture::CreateTextureCoreFromFile(const char * fileName)
{
	BYTE * imageBuffer;
	int width, height;

	if (LoadTexture(fileName, &imageBuffer, &width, &height))
	{
		cout << "Image loaded" << endl;

		TextureCore * tex = new TextureCore();

		tex->AddTexture(imageBuffer, width, height);

		return tex;
	}

	return nullptr;
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
