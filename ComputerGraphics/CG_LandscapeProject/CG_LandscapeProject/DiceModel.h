#pragma once
#include <GL\glew.h>
#include <glm/glm.hpp>
class DiceModel
{
public:
	DiceModel();
	void RenderMeshModel();
	~DiceModel();
	void calcAverageNormals(unsigned int* indices, unsigned int indiceCount, GLfloat* vertices, unsigned int verticeCount,
		unsigned int vLength, unsigned int normalOffset);

private:
	GLuint VAO, VBO;
};