#pragma once
#include "Core.h"
#include <QOpenGLShaderProgram>

class ShaderCore :
	public Core
{
public:
	ShaderCore();
	ShaderCore(QOpenGLFunctions_4_3_Core * func);
	~ShaderCore();

	void generateShader(std::string vertex_shader, std::string geometry_shader, std::string fragment_shader);

	void bindShader();

private:
	QOpenGLShaderProgram * m_program;
};

