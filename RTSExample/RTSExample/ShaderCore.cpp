#include "ShaderCore.h"



ShaderCore::ShaderCore()
{
}


ShaderCore::~ShaderCore()
{
}

void ShaderCore::GenerateShader(string vertex_shader, string geometry_shader, string fragment_shader)
{
	m_shader = ShaderClass::loadShader(vertex_shader.c_str(), fragment_shader.c_str());
}

void ShaderCore::BindShader()
{
	
	glUseProgram(m_shader);
}

void ShaderCore::SetUniformMatrix4f(string name, GLsizei count, const GLfloat * parameter)
{
	glUniformMatrix4fv(glGetUniformLocation(m_shader, name.c_str()), count, false, parameter);
}


