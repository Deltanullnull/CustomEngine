#pragma once

#include "GeometryCore.h"
#include "TextureCore.h"


class Geometry
{
public:
	Geometry();
	~Geometry();

	static GeometryCore * CreatePlane(float width, float height);

	static GeometryCore * CreateBox(float width, float height, float depth);

	

	//static GeometryCore * LoadFile(string file);

private:
	static vector<glm::vec3> CreateNormals(vector<glm::vec3> vertices, vector<int> faces);

};

