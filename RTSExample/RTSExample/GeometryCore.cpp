#include "GeometryCore.h"



GeometryCore::GeometryCore()
{
}


GeometryCore::~GeometryCore()
{
}

void GeometryCore::SetVertices(glm::vec3 * buffer, int size)
{
	glBindVertexArray(m_vao);

	BindBuffer((void*)buffer, size, 3, 0);
}

void GeometryCore::SetUV(glm::vec2 * buffer, int size)
{
	glBindVertexArray(m_vao);

	BindBuffer((void*)buffer, size, 2, 1);
}

void GeometryCore::SetNormals(glm::vec3 * buffer, int size)
{
	glBindVertexArray(m_vao);

	BindBuffer((void*)buffer, size, 3, 2);
}

void GeometryCore::SetFaces(GLuint * buffer, int size)
{
	m_nFaces = (GLuint)size / sizeof(GLuint);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vbo[4]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, buffer, GL_DYNAMIC_DRAW);
}


void GeometryCore::Render()
{
	glBindBuffer(GL_ARRAY_BUFFER, m_vao);

	//glDrawArrays()
}

void GeometryCore::BindBuffer(void * buffer, int size, int stride, int attrib_pointer)
{
	int i = attrib_pointer;

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo[i]);
	glBufferData(GL_ARRAY_BUFFER, size, buffer, GL_DYNAMIC_DRAW);

	//set attributes
	glEnableVertexAttribArray(i);
	glVertexAttribPointer(i, stride, GL_FLOAT, false, 0, 0);
}
