#include "Geometry.h"



Geometry::Geometry()
{
}


Geometry::~Geometry()
{
}

void Geometry::addVertices(GLfloat * buffer, int size)
{
	glBindVertexArray(m_vao);

	bindBuffer((void*)buffer, size, 3, 0);
}

void Geometry::addUV(GLfloat * buffer, int size)
{
	glBindVertexArray(m_vao);

	bindBuffer((void*)buffer, size, 2, 1);
}

void Geometry::addNormals(GLfloat * buffer, int size)
{
	glBindVertexArray(m_vao);

	bindBuffer((void*)buffer, size, 3, 2);
}

void Geometry::addTriangles(GLuint * buffer, int size)
{
	m_nFaces = (GLuint) size / sizeof(GLuint);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vbo[4]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size * 3, buffer, GL_DYNAMIC_DRAW);
}

void Geometry::accept(Renderer * renderer)
{
	glBindVertexArray(m_vao);

	glDrawArrays(GL_TRIANGLES, 0, m_nFaces);
}

void Geometry::bindBuffer(void * buffer, int size, int stride, int attrib_pointer)
{
	int i = attrib_pointer;

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo[i]);
	glBufferData(GL_ARRAY_BUFFER, size, buffer, GL_DYNAMIC_DRAW);

	//set attributes
	glEnableVertexAttribArray(i);
	glVertexAttribPointer(i, stride, GL_FLOAT, false, 0, 0);
}
