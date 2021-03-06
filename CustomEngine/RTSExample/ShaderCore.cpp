#include "ShaderCore.h"



ShaderCore::ShaderCore()
{
}


ShaderCore::~ShaderCore()
{
}

void ShaderCore::GenerateShader(string vertex_shader, string geometry_shader, string fragment_shader)
{
	m_pVertexShader = vertex_shader;
	m_pGeometryShader = geometry_shader;
	m_pFragmentShader = fragment_shader;

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

void ShaderCore::SetUniformVector3f(string name, GLsizei count, const GLfloat *parameter )
{
	int loc = glGetUniformLocation(m_shader, name.c_str());

	//cout << "Setting uniform matrix at " << loc << endl;

	glUniform3fv(loc, count, parameter);
}

void ShaderCore::SetUniform1i(string name, int val)
{
	int loc = glGetUniformLocation(m_shader, name.c_str());

	//cout << "Setting uniform matrix at " << loc << endl;

	glUniform1i(loc, val);
}


