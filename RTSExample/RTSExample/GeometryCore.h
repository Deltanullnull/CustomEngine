#include "Core.h"

#pragma once
class GeometryCore : Core
{
public:
	GeometryCore();
	~GeometryCore();

	void Render();

private:

	GLuint m_vao;
	//GLuint
};

