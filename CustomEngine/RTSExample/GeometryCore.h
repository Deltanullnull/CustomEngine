#include "Core.h"

#include <glm\glm.hpp>

#pragma once
class GeometryCore : Core
{
public:
	GeometryCore();
	~GeometryCore();

	void SetVertices(GLfloat * buffer, int size);
	void SetUV(GLfloat * buffer, int size);
	void SetNormals(GLfloat * buffer, int size);
	void SetFaces(GLuint * buffer, int size);

	

	void Render();

private:

	void SetBufferData(int attrib_pointer, void * buffer, int size);
	void BindBuffer(void * buffer, int size, int stride, int attrib_pointer);
	void VertexAttribPointer(int attrib_pointer, int stride);

	GLuint m_vao = 0;
	GLuint m_vbo[10];

	int m_nFaces = 0;
	int m_nVertices = 0;
};

