#include "CubeModelVBO.h"


CubeModelVBO::CubeModelVBO()
{


	GLfloat vertices[] = {

		       -1.0f, -1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 	//v5
				 1.0f, -1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,	    //v2
				  -1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,  //v1

				-1.0f, -1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,	//v5
				  1.0f, -1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,	//v2
				  1.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f,   //v6

				  1.0f, -1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,	//v2
				  1.0f, 1.0f, -1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f,  //v7
				  1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f,	//v3

				  1.0f, -1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,	//v2
				  1.0f, 1.0f, -1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f,  //v7
				 1.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f,   //v6

				 1.0f, 1.0f, -1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f,  //v7
				 -1.0f, 1.0f, 1.0f, 1.0f, 0.5f, 0.0f, 1.0f, 1.0f, //V0
				-1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,  //v4

				 1.0f, 1.0f, -1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f,  //v7
				-1.0f, 1.0f, 1.0f, 1.0f, 0.5f, 0.0f, 1.0f, 1.0f, //V0
				1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f,	//v3

				-1.0f, 1.0f, 1.0f, 1.0f, 0.5f, 0.0f, 0.0f, 1.0f, //V0
				-1.0f, -1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,	//v5
				-1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,  //v4

				-1.0f, 1.0f, 1.0f, 1.0f, 0.5f, 0.0f, 0.0f, 1.0f, //V0
				-1.0f, -1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,	//v5
				-1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, //v1


				-1.0f, -1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,	//v5
				1.0f, 1.0f, -1.0f,0.0f, 1.0f, 1.0f, 1.0f, 1.0f,  //v7
				-1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,  //v4


				-1.0f, -1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,	//v5
				1.0f, 1.0f, -1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f,  //v7
				1.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f,   //v6

				-1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, //v1
				1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f,	//v3
				-1.0f, 1.0f, 1.0f, 1.0f, 0.5f, 0.0f, 0.0f, 1.0f, //V0

				-1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, //v1
				1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f,	//v3
				1.0f, -1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f	//v2

	};


	



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

void CubeModelVBO::RenderMeshModel()
{
	glBindVertexArray(VAO);

	glDrawArrays(GL_TRIANGLES, 0, 36);

	glBindVertexArray(0);
}


CubeModelVBO::~CubeModelVBO()
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

}



