#pragma once

#include "Renderer.h"

using namespace std;

class ShaderCore
{
public:
	ShaderCore();
	~ShaderCore();

	void generate_shader(string vertex_shader, string geometry_shader, string fragment_shader);
	void accept(Renderer * renderer);

private:
	GLuint shader_program;

};

