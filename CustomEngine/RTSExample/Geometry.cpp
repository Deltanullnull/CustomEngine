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

	glm::vec3 normals[1];

	glm::vec2 texels[4];

	vertices[0] = glm::vec3(-width / 2.f, -height / 2.f, 0);
	vertices[1] = glm::vec3(width / 2.f, -height / 2.f, 0);
	vertices[2] = glm::vec3(width / 2.f, height / 2.f, 0);
	vertices[3] = glm::vec3(-width / 2.f, height / 2.f, 0);

	normals[0] = glm::vec3(0.f, 0.f, 1.f);

	texels[0] = glm::vec2(0, 0);
	texels[1] = glm::vec2(1, 0);
	texels[2] = glm::vec2(1, 1);
	texels[3] = glm::vec2(0, 1);

	GLuint facesVertices[6] = {0, 1, 3, 1, 2, 3};
	GLuint facesTexels[6] = { 0, 1, 3, 1, 2, 3 };
	GLuint facesNormals[6] = { 0, 0, 0, 0, 0, 0 };

	GeometryCore * core = new GeometryCore();

	vector<glm::vec3> vertexList, normalList;
	vector<glm::vec2> texelList;

	for (int i = 0; i < 6; i++)
	{
		int idx = facesVertices[i];

		vertexList.push_back(vertices[idx]);

		idx = facesTexels[i];

		texelList.push_back(texels[idx]);

		idx = facesNormals[i];

		normalList.push_back(normals[idx]);
	}

	core->SetVertices((GLfloat*)&vertexList[0], vertexList.size() * sizeof(glm::vec3));
	core->SetUV((GLfloat*)&texelList[0], texelList.size() * sizeof(glm::vec2));
	core->SetNormals((GLfloat*)&normalList[0], normalList.size() * sizeof(glm::vec3));
	  
	return core;
}

GeometryCore * Geometry::CreateBox(float width, float height, float depth)
{
	glm::vec3 vertices[8], normals[6];

	glm::vec2 texels[4];

	vertices[0] = glm::vec3(-width / 2.f, height / 2.f, -depth / 2.f);
	vertices[1] = glm::vec3(-width / 2.f, -height / 2.f, -depth / 2.f);
	vertices[2] = glm::vec3(width / 2.f, -height / 2.f, -depth / 2.f);
	vertices[3] = glm::vec3(width / 2.f, height / 2.f, -depth / 2.f);
	
	vertices[4] = glm::vec3(-width / 2.f, -height / 2.f, depth / 2.f);
	vertices[5] = glm::vec3(-width / 2.f, height / 2.f, depth / 2.f);
	vertices[6] = glm::vec3(width / 2.f, -height / 2.f, depth / 2.f);
	vertices[7] = glm::vec3(width / 2.f, height / 2.f, depth / 2.f);

	


	normals[0] = glm::vec3(1.f, 0.f, 0.f);
	normals[1] = glm::vec3(-1.f, 0.f, 0.f);
	normals[2] = glm::vec3(0.f, 1.f, 0.f);
	normals[3] = glm::vec3(0.f, -1.f, 0.f);
	normals[4] = glm::vec3(0.f, 0.f, 1.f);
	normals[5] = glm::vec3(0.f, 0.f, -1.f);

	texels[0] = glm::vec2(0, 0);
	texels[1] = glm::vec2(1, 0);
	texels[2] = glm::vec2(1, 1);
	texels[3] = glm::vec2(0, 1);

	const int nIndices = 36;

	GLuint facesVertices[nIndices] = {	0, 1, 2, 2, 3, 0, // front
										4, 1, 0, 0, 5, 4, // back
										2, 6, 7, 7, 3, 2, // left
										4, 5, 7, 7, 6, 4, // right
										0, 3, 7, 7, 5, 0, // up
										1, 4, 2, 2, 4, 6 // down
	};

	GLuint facesTexels[nIndices] = { 0, 1, 3, 1, 2, 3, // back
		0, 1, 3, 1, 2, 3, // front
		0, 1, 3, 1, 2, 3, // left
		0, 1, 3, 1, 2, 3, // right
		0, 1, 3, 1, 2, 3, // down						
		0, 1, 3, 1, 2, 3 };

	GLuint facesNormals[nIndices] = { 4, 4, 4, 4, 4, 4, // back
										5, 5, 5, 5, 5, 5, // front
										1, 1, 1, 1, 1, 1, // left
										0, 0, 0, 0, 0, 0, // right
										3, 3, 3, 3, 3, 3, // down						
										2, 2, 2, 2, 2, 2 };

	vector<glm::vec3> vertexList;

	vector<glm::vec2> texelList;

	vector<glm::vec3> normalList;

	for (int i = 0; i < nIndices; i++)
	{
		int idx = facesVertices[i];

		vertexList.push_back(vertices[idx]);

		idx = facesTexels[i];

		texelList.push_back(texels[idx]);

		idx = facesNormals[i];

		normalList.push_back(normals[idx]);
	}

	GeometryCore * core = new GeometryCore();

	core->SetVertices((GLfloat*) &vertexList[0], vertexList.size() * sizeof(glm::vec3));
	core->SetUV((GLfloat*)&texelList[0], texelList.size() * sizeof(glm::vec2));
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

