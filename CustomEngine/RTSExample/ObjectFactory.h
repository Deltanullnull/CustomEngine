#pragma once

#include "GeometryCore.h"
#include "TextureCore.h"
#include "GameObject.h"

class ObjectFactory
{
public:
	
	//static GeometryCore * CreatePlane(float width, float height);

	//static GeometryCore * CreateBox(float width, float height, float depth);



	static bool LoadFile(string file, GameObject ** gameObject, vector<GeometryCore*>* geometryCore, vector<TextureCore*>* textureCore);

	static GameObject * LoadFile(string file);

private:
	static vector<glm::vec3> CreateNormals(vector<glm::vec3> vertices, vector<int> faces);

};

