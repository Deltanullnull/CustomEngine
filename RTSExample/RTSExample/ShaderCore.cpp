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

	BindShader();
}

void ShaderCore::BindShader()
{
	//cout << "Binding shader " << m_shader << endl;

	glUseProgram(m_shader);
}

void ShaderCore::SetUniformMatrix4f(string name, GLsizei count, const GLfloat * parameter)
{

	int loc = glGetUniformLocation(m_shader, name.c_str());

	//cout << "Setting uniform matrix at " << loc << endl;

	glUniformMatrix4fv(loc, count, false, parameter);
}


