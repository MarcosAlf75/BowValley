#pragma once
#include <GL\glew.h>
class CubeModel
{
public:
	CubeModel();
	void RenderMeshModel();
	~CubeModel();

private:
	GLuint VAO, VBO, IBO;
};

