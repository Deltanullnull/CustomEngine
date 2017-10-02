#pragma once

#include "Renderer.h"

using namespace std;

class ShaderCore
{
public:
	ShaderCore();
	~ShaderCore();

	void GenerateShader(string vertex_shader, string geometry_shader, string fragment_shader);
	void BindShader();

	void SetUniformMatrix4f(string name, GLsizei count, const GLfloat * parameter);
		
private:
	GLuint m_shader;

};

