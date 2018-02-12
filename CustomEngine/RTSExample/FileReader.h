#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

#pragma once
class FileReader
{
public:
	FileReader();
	~FileReader();

	static void LoadFileOBJ(string inputFileName, float ** points, float ** normals, float ** uvMap, unsigned int ** faces, int * nPoints, int * nTriangles);
};

