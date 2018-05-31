#include "ObjectFactory.h"
#include <assimp\Importer.hpp>
#include <assimp\scene.h>
#include <assimp\postprocess.h>
#include <map>
#include <set>

GameObject * ObjectFactory::LoadFile(string file)
{
	Assimp::Importer importer;

	const aiScene * scene = importer.ReadFile(file, aiProcess_CalcTangentSpace | aiProcess_Triangulate | aiProcess_JoinIdenticalVertices | aiProcess_SortByPType);

	cout << "New scene" << endl;

	if (!scene)
		return nullptr;

	cout << "New mesh: " << scene->mNumMeshes << " meshes" << endl;

	GameObject * root = new GameObject();

	for (int i = 0; i < scene->mNumMeshes; i++)
	{
		vector<glm::vec3> verticesTotal, normalsTotal;
		vector<glm::vec2> uvTotal;

		GameObject * part = new GameObject();
		// Make GameObject for each scene

		vector<glm::vec3> vertices, normals;
		vector<glm::vec2> uvs;

		vector<int> faces;

		aiMesh * mesh = scene->mMeshes[i];

		//cout << mesh->mNumVertices << " vertices" << endl;

		for (int v = 0; v < mesh->mNumVertices; v++)
		{
			aiVector3D vertex = mesh->mVertices[v];
			glm::vec3 vertex3(vertex.x, vertex.y, vertex.z);
			vertices.push_back(vertex3);

			if (mesh->mNormals)
			{
				aiVector3D normal = mesh->mNormals[v];
				glm::vec3 normal3(normal.x, normal.y, normal.z);
				normals.push_back(normal3);
			}

			if (mesh->mTextureCoords)
			{
				//if (mesh->mTextureCoords[v])
				{
					aiVector3D texCoord = mesh->mTextureCoords[0][v];
					glm::vec2 uv2(texCoord.x, texCoord.y);
					uvs.push_back(uv2);
				}

			}

		}

		cout << mesh->mNumFaces << " faces" << endl;


		if (mesh->mNumFaces > 0)
		{
			for (int f = 0; f < mesh->mNumFaces; f++)
			{
				aiFace face = mesh->mFaces[f];

				for (int a = 0; a < face.mNumIndices; a++)
				{
					unsigned int fac = face.mIndices[a];

					faces.push_back((int)fac);
				}
			}

			if (!mesh->mNormals)
			{
				normals = CreateNormals(vertices, faces);
			}

			for (int f : faces)
			{
				//cout << f << endl;
				verticesTotal.push_back(vertices.at(f));
				uvTotal.push_back(uvs.at(f));

				if (normals.size() > 0)
					normalsTotal.push_back(normals.at(f));
			}


		}
		else
		{
			verticesTotal.insert(verticesTotal.end(), vertices.begin(), vertices.end());
			uvTotal.insert(uvTotal.end(), uvs.begin(), uvs.end());
			normalsTotal.insert(normalsTotal.end(), normals.begin(), normals.end());
		}


		auto material = scene->mMaterials[mesh->mMaterialIndex];
		//material->GetTexture()
		

		GeometryCore * core = new GeometryCore();

		core->SetVertices((GLfloat*)&verticesTotal[0], verticesTotal.size() * sizeof(glm::vec3));

		if (uvTotal.size() > 0)
		{
			core->SetUV((GLfloat*)&uvTotal[0], uvTotal.size() * sizeof(glm::vec2));
		}

		if (normalsTotal.size() > 0)
		{
			core->SetNormals((GLfloat*)&normalsTotal[0], normalsTotal.size() * sizeof(glm::vec3));
		}

		TextureCore * tex = new TextureCore();

		part->AddCore(core);
		part->AddCore(tex);

		root->AddChild(part);
	}

	return root;
}

vector<glm::vec3> ObjectFactory::CreateNormals(vector<glm::vec3> vertices, vector<int> faces)
{
	vector<pair<int, glm::vec3>> normalMap;
	normalMap.resize(vertices.size());

	int nFaces = faces.size() / 3;

	for (int f = 0; f < nFaces; f++)
	{
		int f0 = faces.at(f * 3 + 0);
		int f1 = faces.at(f * 3 + 1);
		int f2 = faces.at(f * 3 + 2);

		glm::vec3 v0 = vertices.at(f0);
		glm::vec3 v1 = vertices.at(f1);
		glm::vec3 v2 = vertices.at(f2);

		glm::vec3 normal = glm::normalize(glm::cross((v2 - v0), (v1 - v0)));

		normalMap.at(f0).first += 1;
		normalMap.at(f0).second += normal;

		normalMap.at(f1).first += 1;
		normalMap.at(f1).second += normal;

		normalMap.at(f2).first += 1;
		normalMap.at(f2).second += normal;

	}

	vector<glm::vec3> normals;

	for (int i = 0; i < normalMap.size(); i++)
	{
		normals.push_back(glm::normalize(normalMap.at(i).second / (float)normalMap.at(i).first));
	}

	return normals;
}
