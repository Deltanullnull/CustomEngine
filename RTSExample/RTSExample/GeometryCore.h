#include "Core.h"

#include <glm\glm.hpp>

#pragma once
class GeometryCore : Core
{
public:
	GeometryCore();
	~GeometryCore();

	void SetVertices(glm::vec3 * buffer, int size);
	void SetUV(glm::vec2 * buffer, int size);
	void SetNormals(glm::vec3 * buffer, int size);
	void SetFaces(GLuint * buffer, int size);

	

	void Render();

private:

	void BindBuffer(void * buffer, int size, int stride, int attrib_pointer);

	GLuint m_vao;
	GLuint m_vbo[3];

	int m_nFaces;
};

