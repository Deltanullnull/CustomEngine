#include "GeometryCore.h"



GeometryCore::GeometryCore()
{
	glGenVertexArrays(1, &m_vao);

	glGenBuffers(10, m_vbo);
}


GeometryCore::~GeometryCore()
{
}

void GeometryCore::SetVertices(GLfloat * buffer, int size)
{
	glBindVertexArray(m_vao);

	/*for (int i = 0; i < size / sizeof(GLfloat); i += 3)
	{
		cout << buffer[i] << " " << buffer[i + 1] << " " << buffer[i + 2] << endl;
	}*/

	
	m_nVertices = size / sizeof(GLfloat);

	BindBuffer((void*)buffer, size, 3, 0);
}

void GeometryCore::SetUV(GLfloat * buffer, int size)
{
	glBindVertexArray(m_vao);

	BindBuffer((void*)buffer, size, 2, 1);
}

void GeometryCore::SetNormals(GLfloat * buffer, int size)
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

	VertexAttribPointer(0, 3);
	VertexAttribPointer(1, 2);
	VertexAttribPointer(2, 3);

	//glDrawElements(GL_TRIANGLES, m_nFaces, GL_UNSIGNED_INT, 0);

	glDrawArrays(GL_TRIANGLES, 0, m_nVertices);

}

void GeometryCore::SetBufferData(int attrib_pointer, void * buffer, int size)
{
	int i = attrib_pointer;

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo[i]);
	glBufferData(GL_ARRAY_BUFFER, size, buffer, GL_DYNAMIC_DRAW);
}

void GeometryCore::BindBuffer(void * buffer, int size, int stride, int attrib_pointer)
{
	int i = attrib_pointer;

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo[i]);
	glBufferData(GL_ARRAY_BUFFER, size, buffer, GL_DYNAMIC_DRAW);

	//set attributes
	glEnableVertexAttribArray(i);
	glVertexAttribPointer(i, stride, GL_FLOAT, false, 0, 0);

	//cout << "Binding buffer at vbo " << m_vbo[i] << endl;
}

void GeometryCore::VertexAttribPointer(int attrib_pointer, int stride)
{
	int i = attrib_pointer;

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo[i]);

	//set attributes
	glVertexAttribPointer(i, stride, GL_FLOAT, false, 0, 0);
}
