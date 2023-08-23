#include "CubeModel.h"



CubeModel::CubeModel()
{

	
	unsigned int indices[] = {
		// front
		5, 2, 1,
		5, 2, 6,
		// right
		2, 7, 3,
		2, 7, 6,
		// back
		7, 0, 4,
		7, 0, 3,
		// left
		0, 5, 4,
		0, 5, 1,
		// bottom
		5, 7, 4,
		5, 7, 6,
		// top
		1, 3, 0,
		1, 3, 2
	};

	GLfloat vertices[] = {

		-1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, //V0
		-1.0f,-1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, //v1
		1.0f,-1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.66f, 1.0f,	//v2
		1.0f,1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.33f, 1.0f,	//v3


		-1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f,  //v4
		-1.0f,-1.0f, -1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f,	//v5
		1.0f, -1.0f,-1.0f, 1.0f, 0.5f, 0.0f, 0.66f, 0.0f,   //v6
		1.0f, 1.0f, -1.0f, 0.0f, 1.0f, 0.5f, 0.33f, 0.0f  //v7

	};

	
	/*
	unsigned int indices[] = {
		// front
		5, 2, 1,
		5, 2, 6,
		// right
		2, 7, 3,
		2, 7, 6,
		// back
		7, 0, 4,
		7, 0, 3,
		// left
		0, 5, 4,
		0, 5, 1,
		// bottom
		5, 7, 4,
		5, 7, 6,
		// top
		1, 3, 0,
		1, 3, 2
	};

	GLfloat vertices[] = {

		-1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, //V0
		-1.0f,-1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, //v1
		1.0f,-1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,	//v2
		1.0f,1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.5f, 1.0f,	//v3


		-1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f,  //v4
		-1.0f,-1.0f, -1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f,	//v5
		1.0f, -1.0f,-1.0f, 1.0f, 0.5f, 0.0f, 1.0f, 0.0f,   //v6
		1.0f, 1.0f, -1.0f, 0.0f, 1.0f, 0.5f, 0.5f, 0.0f  //v7

	};

	*/

	/*
	GLfloat vertices[] = {
		//X     Y      Z    R     G     B    u     v
		0.5f, 1.0f, 0.5f, 1.0f, 0.0f, 0.0f, 0.5f, 1.0f, //top middle & half behind, point 0 
		0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, //left bottom, point 1
		1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f,//right bottom, point 2 
		0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.5f, 0.5f,//bottom middle behind, point 3 
	};

	unsigned int indices[] = {
	0, 1, 2,//front
	0, 2, 3,//right
	0, 3, 1,//left
	1, 2, 3//bottom
	};
	*/


	glGenBuffers(1, &IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertices[0]) * 8, 0);  //total values in a point
	glEnableVertexAttribArray(0);


	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertices[0]) * 8, (void*)(sizeof(vertices[0]) * 3));  //total values in a point
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(vertices[0]) * 8, (void*)(sizeof(vertices[0]) * 6));  //total values in a point
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void CubeModel::RenderMeshModel()
{
	glBindVertexArray(VAO);

	//glDrawArrays(GL_TRIANGLES, 0, 12);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


	glBindVertexArray(0);
}


CubeModel::~CubeModel()
{
	if (VBO != 0)
	{
		glDeleteBuffers(1, &VBO);
		VBO = 0;
	}

	if (VAO != 0)
	{
		glDeleteVertexArrays(1, &VAO);
		VAO = 0;
	}

	if (IBO != 0)
	{
		glDeleteBuffers(1, &IBO);
		IBO = 0;
	}

}


