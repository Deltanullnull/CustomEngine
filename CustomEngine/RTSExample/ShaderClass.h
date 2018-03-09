#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include <GL/glew.h>
#include <gl\freeglut.h>
#include <GLFW\glfw3.h>

#include <glm\glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace std;

static class ShaderClass
{
public:
	ShaderClass();
	~ShaderClass();

	static GLuint loadShader(const char *vertex_path, const char *fragment_path);

private:
	static std::string readFile(const char * filePath);

};

