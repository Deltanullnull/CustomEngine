#pragma once

#include "GeometryCore.h"



class Geometry
{
public:
	Geometry();
	~Geometry();

	static GeometryCore * CreatePlane(float width, float height);

private:
	GLuint m_vao;
	GLuint m_vbo[3];

	void bindBuffer(void * buffer, int size, int stride, int attrib_pointer);

	int m_nFaces;
};

