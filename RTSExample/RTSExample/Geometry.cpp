#include "Geometry.h"



Geometry::Geometry()
{
}


Geometry::~Geometry()
{
}

GeometryCore * Geometry::CreatePlane(float width, float height)
{
	glm::vec3 vertices[4];

	vertices[0] = glm::vec3(-width / 2.f, -height / 2.f, 0.f);
	vertices[1] = glm::vec3(width / 2.f, -height / 2.f, 0.f);
	vertices[2] = glm::vec3(width / 2.f, height / 2.f, 0.f);
	vertices[3] = glm::vec3(-width / 2.f, height / 2.f, 0.f);

	GLuint faces[6] = {0, 1, 3, 1, 2, 3};

	GeometryCore * core = new GeometryCore();

	core->SetVertices(vertices, 4);
	core->SetFaces(faces, 6);

	return core;
}

