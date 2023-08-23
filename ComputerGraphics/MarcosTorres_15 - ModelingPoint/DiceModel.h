#pragma once
#include <GL\glew.h>
class DiceModel
{
public:
	DiceModel();
	void RenderMeshModel();
	~DiceModel();

private:
	GLuint VAO, VBO;
};