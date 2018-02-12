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

	/*vertices[0] = glm::vec3(-width / 2.f, 0.f, -height / 2.f);
	vertices[1] = glm::vec3(width / 2.f, 0.f, -height / 2.f);
	vertices[2] = glm::vec3(width / 2.f, 0.f, height / 2.f);
	vertices[3] = glm::vec3(-width / 2.f, 0.f, height / 2.f);*/

	vertices[0] = glm::vec3(-width / 2.f, -height / 2.f, 0);
	vertices[1] = glm::vec3(width / 2.f, -height / 2.f, 0);
	vertices[2] = glm::vec3(width / 2.f, height / 2.f, 0);
	vertices[3] = glm::vec3(-width / 2.f, height / 2.f, 0);

	GLuint faces[6] = {0, 1, 3, 1, 2, 3};

	GeometryCore * core = new GeometryCore();
	  
	core->SetVertices((GLfloat*)vertices, 4 * sizeof(glm::vec3));
	core->SetFaces(faces, 6 * sizeof(GLuint));

	return core;
}

