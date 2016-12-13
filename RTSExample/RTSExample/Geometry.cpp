#include "Geometry.h"



Geometry::Geometry()
{
}


Geometry::~Geometry()
{
}

void Geometry::add_vertices(GLfloat * buffer, int size)
{
	glBindVertexArray(m_vao);

	bind_buffer((void*)buffer, size, 3, 0);
}

void Geometry::accept(Renderer * renderer)
{
	glBindVertexArray(m_vao);

	glDrawArrays(GL_TRIANGLES, 0, m_n_faces);
}

void Geometry::bind_buffer(void * buffer, int size, int stride, int attrib_pointer)
{
	int i = attrib_pointer;

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo[i]);
	glBufferData(GL_ARRAY_BUFFER, size, buffer, GL_DYNAMIC_DRAW);

	//set attributes
	glEnableVertexAttribArray(i);
	glVertexAttribPointer(i, stride, GL_FLOAT, false, 0, 0);
}
