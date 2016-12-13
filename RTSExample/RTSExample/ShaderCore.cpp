#include "ShaderCore.h"



ShaderCore::ShaderCore()
{
}


ShaderCore::~ShaderCore()
{
}

void ShaderCore::generate_shader(string vertex_shader, string geometry_shader, string fragment_shader)
{
	shader_program = ShaderClass::loadShader(vertex_shader.c_str(), fragment_shader.c_str());
}

void ShaderCore::accept(Renderer * renderer)
{
	glUseProgram(shader_program);
}
