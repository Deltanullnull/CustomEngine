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

	vector<glm::vec3> vertexList;

	for (int i = 0; i < 6; i++)
	{
		int idx = faces[i];

		vertexList.push_back(vertices[idx]);
	}

	core->SetVertices((GLfloat*)&vertexList[0], vertexList.size() * sizeof(glm::vec3));
	  
	return core;
}

GeometryCore * Geometry::CreateBox(float width, float height, float depth)
{
	glm::vec3 vertices[8], normals[6];

	vertices[0] = glm::vec3(-width / 2.f, -height / 2.f, -depth / 2.f);
	vertices[1] = glm::vec3(width / 2.f, -height / 2.f, -depth / 2.f);
	vertices[2] = glm::vec3(width / 2.f, height / 2.f, -depth / 2.f);
	vertices[3] = glm::vec3(-width / 2.f, height / 2.f, -depth / 2.f);

	vertices[4] = glm::vec3(-width / 2.f, -height / 2.f, depth / 2.f);
	vertices[5] = glm::vec3(width / 2.f, -height / 2.f, depth / 2.f);
	vertices[6] = glm::vec3(width / 2.f, height / 2.f, depth / 2.f);
	vertices[7] = glm::vec3(-width / 2.f, height / 2.f, depth / 2.f);


	normals[0] = glm::vec3(1.f, 0.f, 0.f);
	normals[1] = glm::vec3(-1.f, 0.f, 0.f);
	normals[2] = glm::vec3(0.f, 1.f, 0.f);
	normals[3] = glm::vec3(0.f, -1.f, 0.f);
	normals[4] = glm::vec3(0.f, 0.f, 1.f);
	normals[5] = glm::vec3(0.f, 0.f, -1.f);

	GLuint facesVertices[24] = { 0, 1, 3, 1, 2, 3, // front
						5, 4, 7, 5, 7, 6, // back
						0, 4, 3, 0, 7, 4, // left
						1, 5, 6, 2, 6, 5 // right
	};

	GLuint facesNormals[24] = { 4, 4, 4, 4, 4, 4, // front
								5, 5, 5, 5, 5, 5, // back
								1, 1, 1, 1, 1, 1, // left
								0, 0, 0, 0, 0, 0 // right
	};

	vector<glm::vec3> vertexList;

	vector<glm::vec3> normalList;

	for (int i = 0; i < 24; i++)
	{
		int idx = facesVertices[i];

		vertexList.push_back(vertices[idx]);

		idx = facesNormals[i];

		normalList.push_back(normals[idx]);
	}

	GeometryCore * core = new GeometryCore();

	core->SetVertices((GLfloat*) &vertexList[0], vertexList.size() * sizeof(glm::vec3));
	core->SetNormals((GLfloat*)&normalList[0], normalList.size() * sizeof(glm::vec3));

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

