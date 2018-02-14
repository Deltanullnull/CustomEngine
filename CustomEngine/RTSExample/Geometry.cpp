#include "Geometry.h"
#include <assimp\Importer.hpp>
#include <assimp\scene.h>
#include <assimp\postprocess.h>

Geometry::Geometry()
{
}


Geometry::~Geometry()
{
}

GeometryCore * Geometry::CreatePlane(float width, float height)
{
	glm::vec3 vertices[4];

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

GeometryCore * Geometry::LoadFile(string file)
{
	Assimp::Importer importer;

	const aiScene * scene = importer.ReadFile(file, aiProcess_CalcTangentSpace | aiProcess_Triangulate | aiProcess_JoinIdenticalVertices | aiProcess_SortByPType);

	if (!scene)
		return nullptr;

	GeometryCore * core = new GeometryCore();

	vector<glm::vec3> vertices;

	for (int i = 0; i < scene->mNumMeshes; i++)
	{
		aiMesh * mesh = scene->mMeshes[i];

		for (int v = 0; v < mesh->mNumVertices; v++)
		{
			aiVector3D vertex = mesh->mVertices[v];

			glm::vec3 vertex3(vertex.x, vertex.y, vertex.z);

			vertices.push_back(vertex3);
		}
	}

	core->SetVertices((GLfloat*)&vertices[0], vertices.size() * sizeof(glm::vec3));

	return core;
}

