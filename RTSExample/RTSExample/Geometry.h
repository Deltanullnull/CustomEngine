#pragma once

#include "Renderer.h"

class Geometry
{
public:
	Geometry();
	~Geometry();

	void addVertices(GLfloat * buffer, int size);
	void addUV(GLfloat * buffer, int size);
	void addNormals(GLfloat * buffer, int size);
	void addTriangles(GLuint * buffer, int size);

	void accept(Renderer * renderer);

private:
	GLuint m_vao;
	GLuint m_vbo[3];

	void bindBuffer(void * buffer, int size, int stride, int attrib_pointer);

	int m_nFaces;
};

