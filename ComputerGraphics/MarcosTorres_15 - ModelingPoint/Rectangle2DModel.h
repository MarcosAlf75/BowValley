#pragma once
#include <GL\glew.h>
#include <glm/glm.hpp>

class Rectangle2DModel
{
public:
	Rectangle2DModel();
	void RenderMeshModel();
	void calcAverageNormals(unsigned int* indices, unsigned int indiceCount, GLfloat* vertices, unsigned int verticeCount,
		unsigned int vLength, unsigned int normalOffset);
	~Rectangle2DModel();

private:
	GLuint VAO, VBO, IBO;
};

