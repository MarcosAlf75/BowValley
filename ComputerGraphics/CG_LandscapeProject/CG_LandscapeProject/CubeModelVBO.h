#pragma once
#include <GL\glew.h>
class CubeModelVBO
{
public:
	CubeModelVBO();
	void RenderMeshModel();
	~CubeModelVBO();

private:
	GLuint VAO, VBO;

};



