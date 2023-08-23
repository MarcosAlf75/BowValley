#include "MeshModel.h"

MeshModel::MeshModel()
{
	//GLfloat vertices[] = {
	//	//X     Y      Z    R     G     B
	//	0.5f, 1.0f, 0.5f, 1.0f, 0.0f, 0.0f,  //top middle & half behind, point 0 
	//	0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,  //left bottom, point 1
	//	1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,  //right bottom, point 2 
	//	0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f,  //bottom middle behind, point 3 
	//};

	//unsigned int indices[] = {
	//	0, 1, 2,  //front
	//	0, 2, 3,  //right
	//	0, 3, 1,  //left
	//	1, 2, 3   //bottom
	//};

	//glGenBuffers(1, &IBO);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


	//glGenVertexArrays(1, &VAO);
	//glBindVertexArray(VAO);
	//glGenBuffers(1, &VBO);
	//glBindBuffer(GL_ARRAY_BUFFER, VBO);

	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertices[0]) * 6, 0);  //total values in a point
	//glEnableVertexAttribArray(0);


	//glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertices[0]) * 6, (void*)(sizeof(vertices[0]) * 3));  //total values in a point
	//glEnableVertexAttribArray(1);

	//glBindBuffer(GL_ARRAY_BUFFER, 0);
	//glBindVertexArray(0);
}

void MeshModel::CreateObjectModel(GLfloat* vertices, unsigned int* indices, unsigned int nVertices, unsigned int nIndices)
{
	this->iCount = nIndices;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glGenBuffers(1, &IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0]) * nIndices, indices, GL_STATIC_DRAW);
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * nVertices, vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertices[0]) * 8, 0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(vertices[0]) * 8, (void*)(sizeof(vertices[0]) * 3));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(vertices[0]) * 8, (void*)(sizeof(vertices[0]) * 5));
	glEnableVertexAttribArray(3);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

}

void MeshModel::RenderMeshModel()
{
	glBindVertexArray(VAO);
	//glDrawArrays(GL_TRIANGLES, 0, 12);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glDrawElements(GL_TRIANGLES, iCount, GL_UNSIGNED_INT, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

MeshModel::~MeshModel()
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
