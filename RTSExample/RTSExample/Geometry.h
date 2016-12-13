#pragma once

#include "Renderer.h"

class Geometry
{
public:
	Geometry();
	~Geometry();

	void add_vertices(GLfloat * buffer, int size);

	void accept(Renderer * renderer);

private:
	GLuint m_vao;
	GLuint m_vbo[3];

	void bind_buffer(void * buffer, int size, int stride, int attrib_pointer);

	int m_n_faces;
};

