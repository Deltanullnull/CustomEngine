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

	for (int i = 0; i < size / sizeof(GLfloat); i+=3)
	{
		cout << buffer[i] << " " << buffer[i+1] << " " << buffer[i+2] << endl;
	}

	//cout << "Setting vertices with size " << size << endl;

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

	//cout << "Created " << m_nFaces << " faces at vbo " << m_vbo[4] << endl;
}


void GeometryCore::Render()
{
	//cout << "Rendering " << m_nFaces << " faces" << endl;

	glBindBuffer(GL_ARRAY_BUFFER, m_vao);

	glDrawElements(GL_TRIANGLES, m_nFaces, GL_UNSIGNED_INT, 0);
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
