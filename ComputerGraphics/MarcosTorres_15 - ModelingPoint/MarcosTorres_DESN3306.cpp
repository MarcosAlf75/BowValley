#define STB_IMAGE_IMPLEMENTATION

#include <iostream> //Standard Header Files
#include<conio.h>
#include <iomanip>
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<assimp/Importer.hpp> 
#include"MeshModel.h"   //Our Own Custom Class Headers
#include"Shader.h"
#include"GLWindow.h"
#include"randomMode.h"
#include "Camera_Control.h"
#include "Model2D.h"
#include "Rectangle2DModel.h"
#include "TextureMapping.h"
#include "TetrahedronModel.h"
#include "CubeModel.h"
#include "CubeModelVBO.h"
#include "DiceModel.h"
#include "Light.h"
#include "ImportedModel.h"
#include "MaterialProperty.h"
#include "DirectionalLight.h"
#include "PointLight.h"

using namespace std;
/*
void lookInsideMatrix(glm::mat4 model)
{
	float matrix[16] = { 0 };
	memcpy(matrix, glm::value_ptr(model), sizeof(model));

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << fixed << setprecision(2) << setw(5) << matrix[i * 4 + j] << " ";
		}
		cout << endl;
	}
	//lookInsideMatrix(model);
	_getch();
	//requires headerfiles
	//#include<conio.h>
	//#include <iomanip>
}
*/	

int main()
{
	Assimp::Importer a;
	GLWindow myWindow = GLWindow(1500, 1500);
	myWindow.InitGLWindow();
	Shader* myShader = new Shader();

	//MeshModel* myShape = new MeshModel();
	//TetrahedronModel* myShape = new TetrahedronModel();

	//DiceModel* myShape1 = new DiceModel();

	Rectangle2DModel* myShape2 = new Rectangle2DModel();
	TetrahedronModel* myShape3 = new TetrahedronModel();

	MaterialProperty shinyObject = MaterialProperty(0.6f, 32);
	MaterialProperty dullObject = MaterialProperty(0.2f, 2);

	ImportedModel* XWingModel = new ImportedModel();
	XWingModel->LoadModel("3DModels/x-wing.obj");
	RandomMode* rotateXwing = new RandomMode(0.0f, 2 * 3.14159f, 0.001f, true);

	DirectionalLight ambientDiffuseLight = DirectionalLight(1.0f, 1.0f, 1.0f, 0.6f, 0.5f, 0.0f, -1.0f, 0.0f); //color+ambient intensity
	
	PointLight pointLights[MAX_POINT_LIGHTS];
	unsigned int pointLightCount = 0;

	pointLights[0] = PointLight(1.0f, 0.0f, 0.0f,
		0.5f, 3.6f,
		5.0f, 0.0f, -10.0f,
		0.3f, 0.3f, 0.3f);
	pointLightCount++;

	pointLights[1] = PointLight(0.0f, 1.0f, 0.0f,
		0.5f, 3.6f,
		-5.0f, 0.0f, -10.0f,
		0.3f, 0.2f, 0.1f);
	pointLightCount++;

	pointLights[2] = PointLight(0.0f, 0.0f, 1.0f,
		0.5f, 3.6f,
		0.0f, 0.0f, -5.0f,
		0.1f, 0.2f, 0.3f);
	pointLightCount++;


	TextureMapping myTexture1 = TextureMapping((char*)"Textures/cube2.jpg");
	myTexture1.LoadTextureImage();
	TextureMapping myTexture2 = TextureMapping((char*)"Textures/field.jpg");
	myTexture2.LoadTextureImage();
	TextureMapping myTexture3 = TextureMapping((char*)"Textures/box.jpg");
	myTexture3.LoadTextureImage();

	GLfloat deltaTime, prevTime;
	deltaTime = prevTime = 0;
	Camera_Control myCamera = Camera_Control(glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f, 1.0f, 0.0f), -90.0f, 0.0f, 0.002f);

	RandomMode* xMovement = new RandomMode(0, 1, 0.001, true);
	RandomMode* yMovement = new RandomMode(0, 1, 0.003);

	RandomMode* rotate = new RandomMode(0, 2 * 3.14159, 0.0004, true);

	RandomMode* rotate2 = new RandomMode(0, 2 * 3.14159, 0.001, true);

	//variable for degree to radian
	GLfloat toRadian = 3.141592654 / 180.0f;

	glm::mat4 projection = glm::perspective(toRadian * 45.0f, (float)myWindow.getBufferWidth() / (float)myWindow.getBufferHeight(), 0.1f, 100.0f);

	while (!myWindow.isWindowClosed()) 	// Loop until main window is closed
	{
		
		myShader->UseGpu();
		myShader->SetDirectionalLight(&ambientDiffuseLight);
		myShader->SetPointLights(pointLights, pointLightCount);
		ambientDiffuseLight.UseLight(myShader->GetAmbientIntensity(), myShader->GetColour(), myShader->GetDiffuseIntensity(), myShader->GetDirection());

		//Adjusted Hardware Speed
		GLfloat currentTime = glfwGetTime();
		deltaTime = currentTime - prevTime;
		prevTime = currentTime;


		// Get/set/control user input events
		myCamera.keyboardControl(myWindow.getsKeybordKeys(), deltaTime);
		//myCamera.mouseControl(myWindow.getXChange(), myWindow.getYChange(), deltaTime);

		
		glm::mat4 model2;
		model2 = glm::translate(model2, glm::vec3(-10.0, -1.0, 0.0)); //translation to bring the view on the projection plane
		//model2 = glm::translate(model2, glm::vec3(-10.0, -1.0, 0.0)); //translation to bring the view on the projection plane
		model2 = glm::rotate(model2, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
		model2 = glm::scale(model2, glm::vec3(20.0f, 20.0f, 20.0f));  //initial scaling
		glUniformMatrix4fv(myShader->getUnifromModel(), 1, GL_FALSE, glm::value_ptr(model2));
		//glUniformMatrix4fv(myShader->getUniformProjectionModel(), 1, GL_FALSE, glm::value_ptr(projection));
		//glUniformMatrix4fv(myShader->getCameraViewLoc(), 1, GL_FALSE, glm::value_ptr(myCamera.calculateCameraViewMatrix()));

		myTexture2.applyTexture();
		dullObject.UseMaterialProperty(myShader->GetSpecularIntensity(), myShader->GetShininess());
		myShape2->RenderMeshModel();

		/*

		glm::mat4 model2;
		model2 = glm::translate(model2, glm::vec3(-10.0, -1.0, 0.0)); //translation to bring the view on the projection plane
		model2 = glm::rotate(model2, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
		model2 = glm::scale(model2, glm::vec3(20.0f, 20.0f, 20.0f));  //initial scaling
		glUniformMatrix4fv(myShader->getUnifromModel(), 1, GL_FALSE, glm::value_ptr(model2));

		myTexture2.applyTexture();
		dullObject.UseMaterialProperty(myShader->GetSpecularIntensity(), myShader->GetShininess());
		myShape2->RenderMeshModel();
		*/


		glm::mat4 model3;
		model3 = glm::translate(model3, glm::vec3(0.0, 0.0, -12.0)); //translation to bring the view on the projection plane
		model3 = glm::rotate(model3, rotate->genCurrentValue(), glm::vec3(0.0f, -1.0f, 0.0f));
		model3 = glm::translate(model3, glm::vec3(5.0, 0.0, 0.0));
		model3 = glm::scale(model3, glm::vec3(0.01f, 0.01f, 0.01f));  //initial scaling
		model3 = glm::translate(model3, glm::vec3(-1400.0172, -108.2528, 1722.1118));

		glUniformMatrix4fv(myShader->getUnifromModel(), 1, GL_FALSE, glm::value_ptr(model3));
		glUniformMatrix4fv(myShader->getUniformProjectionModel(), 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(myShader->getCameraViewLoc(), 1, GL_FALSE, glm::value_ptr(myCamera.calculateCameraViewMatrix()));

		myTexture3.applyTexture();
		shinyObject.UseMaterialProperty(myShader->GetSpecularIntensity(), myShader->GetShininess());
		XWingModel->RenderModel();


		myWindow.swapBuffers(); //Swap buffers, OpenGL main tains two Buffers, One is displayed, one is getting prepared
		
	}

	return 0;

}