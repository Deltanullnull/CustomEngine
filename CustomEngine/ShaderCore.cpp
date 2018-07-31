#include "ShaderCore.h"



ShaderCore::ShaderCore()
{
	
}

ShaderCore::ShaderCore(QOpenGLFunctions_4_3_Core * func) 
{
	m_func = func;
}


ShaderCore::~ShaderCore()
{
}

void ShaderCore::generateShader(std::string vertex_shader, std::string geometry_shader, std::string fragment_shader)
{
	m_program = new QOpenGLShaderProgram;

	m_program->addShaderFromSourceCode(QOpenGLShader::Vertex, vertex_shader.c_str());
	m_program->addShaderFromSourceCode(QOpenGLShader::Geometry, geometry_shader.c_str());
	m_program->addShaderFromSourceCode(QOpenGLShader::Fragment, fragment_shader.c_str());

	m_program->link();
}

void ShaderCore::bindShader()
{
	m_program->bind();
}
