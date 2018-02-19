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
	void SetUniformVector3f(string name, GLsizei count, const GLfloat *parameter);
		
public:
	string m_pVertexShader, m_pGeometryShader, m_pTesselationShader, m_pFragmentShader;

private:

	GLuint m_shader;

};

