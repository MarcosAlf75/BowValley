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

int main()
{
	Assimp::Importer a;
	GLWindow myWindow = GLWindow(1500, 1500);
	myWindow.InitGLWindow();
	Shader* myShader = new Shader();

	//MeshModel* myShape = new MeshModel();
	//TetrahedronModel* myShape = new TetrahedronModel();

	DiceModel* myLandscape = new DiceModel();

	//Rectangle2DModel* myShape = new Rectangle2DModel();
	//TetrahedronModel* myShape3 = new TetrahedronModel();

	MaterialProperty shinyLamp = MaterialProperty(0.2f, 40);
	MaterialProperty shinyMoon = MaterialProperty(1.0f, 100);
	MaterialProperty dullObject = MaterialProperty(0.2f, 2);

	ImportedModel* XWingModel = new ImportedModel();
	XWingModel->LoadModel("3DModels/x-wing.obj");

	ImportedModel* CottageModel = new ImportedModel();
	//CarModel->LoadModel("3DModels/Datsun_280Z.obj");
	CottageModel->LoadModel("3DModels/CottageOBJ.obj");
	
	ImportedModel* AuxiliarModel = new ImportedModel();
	AuxiliarModel->LoadModel("3DModels/soccer-ball.obj");

	ImportedModel* moonModel = new ImportedModel();
	moonModel->LoadModel("3DModels/moon.obj");

	ImportedModel* lampModel = new ImportedModel();
	lampModel->LoadModel("3DModels/StreetLamp.obj");

	ImportedModel* ufoModel = new ImportedModel();
	ufoModel->LoadModel("3DModels/UFO_Empty.obj");

	ImportedModel* ufoModelParking = new ImportedModel();
	ufoModelParking->LoadModel("3DModels/UFO_Empty.obj");
	


	RandomMode* rotateXwing = new RandomMode(0.0f, 2 * 3.14159f, 0.0001f, true);

	DirectionalLight ambientDiffuseLight = DirectionalLight(1.0f, 1.0f, 1.0f, 0.6f, 0.5f, 0.0f, -1.0f, 0.0f); //color+ambient intensity

	PointLight pointLights[MAX_POINT_LIGHTS];
	unsigned int pointLightCount = 0;

	pointLights[0] = PointLight(3.0f, 0.0f, 0.0f,
		1.0f, 5.6f,
		3.0f, -5.0f, -20.0f,
		0.9f, 0.3f, 0.3f);
	pointLightCount++;

	pointLights[1] = PointLight(1.0f, 1.0f, 0.0f,
		0.5f, 3.6f,
		2.0f, 7.0f, -20.0f,
		0.3f, 0.2f, 0.1f);
	pointLightCount++;

	//pointLights[2] = PointLight(0.0f, 1.0f, 0.0f,
	//	0.5f, 3.6f,
	//	-5.0f, 0.0f, -10.0f,
	//	0.3f, 0.2f, 0.1f);
	//pointLightCount++;

	TextureMapping texttureField = TextureMapping((char*)"Textures/space04.png");
	texttureField.LoadTextureImage();

	TextureMapping texttureMoon = TextureMapping((char*)"Textures/mooncolor.jpg");
	texttureMoon.LoadTextureImage();

	TextureMapping texttureLamp = TextureMapping((char*)"Textures/Brake_lamp_Color.png");
	texttureLamp.LoadTextureImage();

	TextureMapping texttureUfo = TextureMapping((char*)"Textures/ufo-Texture.jpg");
	texttureUfo.LoadTextureImage();


	TextureMapping texttureLampLight = TextureMapping((char*)"Textures/lightlamp.jpeg");
	texttureLampLight.LoadTextureImage();


	GLfloat deltaTime, prevTime;
	deltaTime = prevTime = 0;

	//Camera_Control myCamera = Camera_Control(glm::vec3(0.0f, -14.0f, 8.0f), glm::vec3(0.0f, 1.0f, 0.0f), -90.0f, 0.0f, 0.06f);
	Camera_Control myCamera = Camera_Control(glm::vec3(0.0f, 0.0f, 5.0f), glm::vec3(0.0f, 1.0f, 0.0f), -90.0f, 0.0f, 0.06f);

	RandomMode* xMovement = new RandomMode(0, 1, 0.001, true);
	RandomMode* yMovement = new RandomMode(0, 1, 0.003);

	RandomMode* rotate = new RandomMode(0, 2 * 3.14159, 0.0005, true);

	//variable for degree to radian
	GLfloat toRadian = 3.141592654 / 180.0f;

	glm::mat4 projection = glm::perspective(toRadian * 45.0f, (float)myWindow.getBufferWidth() / (float)myWindow.getBufferHeight(), 0.1f, 100.0f);

	while (!myWindow.isWindowClosed()) 	// Loop until main window is closed
	{
		myShader->UseGpu();
		myShader->SetDirectionalLight(&ambientDiffuseLight);
		myShader->SetPointLights(pointLights, pointLightCount);
		ambientDiffuseLight.UseLight(myShader->GetAmbientIntensity(), myShader->GetColour(), myShader->GetDiffuseIntensity(), myShader->GetDirection());
		myCamera.keyboardControl(myWindow.getsKeybordKeys(), deltaTime);
		myCamera.mouseClickControl(myWindow.getsMouseClick());
		myCamera.mouseClickControl(myWindow.getsMouseClick());

		//Adjusted Hardware Speed
		GLfloat currentTime = glfwGetTime();
		deltaTime = currentTime - prevTime;
		prevTime = currentTime;

		/*********************************************************************************************************** */
		//Dice -- Landscape
		glm::mat4 model;
		model = glm::translate(model, glm::vec3(0.0, 0.0, -12.0)); //translation to bring the view on the projection plane
		//model = glm::rotate(model, rotate->genCurrentValue(), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(90.0f), glm::vec3(-1.0f, 0.0f, 0.0f));
		model = glm::scale(model, glm::vec3(20.0f, 20.0f, 20.0f));  //initial scaling
		glUniformMatrix4fv(myShader->getUnifromModel(), 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(myShader->getUniformProjectionModel(), 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(myShader->getCameraViewLoc(), 1, GL_FALSE, glm::value_ptr(myCamera.calculateCameraViewMatrix()));

		texttureField.applyTexture();
		myLandscape->RenderMeshModel();

		/*********************************************************************************************************** */
		//Falcon Model
		glm::mat4 model2;
		model2 = glm::translate(model2, glm::vec3(5.0, 4.0, -20.0)); //translation to bring the view on the projection plane
		model2 = glm::rotate(model2, rotate->genCurrentValue(), glm::vec3(0.0f, -1.0f, 0.0f));
		model2 = glm::translate(model2, glm::vec3(6.0, 0.0, 0.0));
		model2 = glm::scale(model2, glm::vec3(0.003f, 0.003f, 0.003f));  //initial scaling
		model2 = glm::translate(model2, glm::vec3(-1400.0172, -108.2528, 1722.1118));

		glUniformMatrix4fv(myShader->getUnifromModel(), 1, GL_FALSE, glm::value_ptr(model2));
		glUniformMatrix4fv(myShader->getUniformProjectionModel(), 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(myShader->getCameraViewLoc(), 1, GL_FALSE, glm::value_ptr(myCamera.calculateCameraViewMatrix()));
		//myTexture3.applyTexture();
		//shinyObject.UseMaterialProperty(myShader->GetSpecularIntensity(), myShader->GetShininess());
		XWingModel->RenderModel();

		/*********************************************************************************************************** */
		//Cottage Model

		glm::mat4 cotModel;
		cotModel = glm::translate(cotModel, glm::vec3(-2.5, -5.5, -18.0));
		cotModel = glm::rotate(cotModel, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		cotModel = glm::scale(cotModel, glm::vec3(0.02f, 0.02f, 0.02f));
		cotModel = glm::translate(cotModel, glm::vec3(27.744078, 0.809079, -45.828236)); //cottage v -27.744078 -0.809079 45.828236

		glUniformMatrix4fv(myShader->getUnifromModel(), 1, GL_FALSE, glm::value_ptr(cotModel));
		glUniformMatrix4fv(myShader->getUniformProjectionModel(), 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(myShader->getCameraViewLoc(), 1, GL_FALSE, glm::value_ptr(myCamera.calculateCameraViewMatrix()));

		dullObject.UseMaterialProperty(myShader->GetSpecularIntensity(), myShader->GetShininess());
		CottageModel->RenderModel();

		/*********************************************************************************************************** */
		//Moon Model

		glm::mat4 moonMatrix;
		moonMatrix = glm::translate(moonMatrix, glm::vec3(2.0, 7.0, -25.0)); //Moon
		//moonMatrix = glm::rotate(moonMatrix, glm::radians(-45.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		moonMatrix = glm::scale(moonMatrix, glm::vec3(0.8f, 0.8f, 0.8f));  //Moon
		moonMatrix = glm::translate(moonMatrix, glm::vec3(0.0, -0.973792, -0.199755)); //moon v 0.000000 0.973792 -0.199755

		glm::vec4 posMoon = moonMatrix * glm::vec4(1.0f, 1.0f, 1.0f, 1.0);
		myCamera.SetMoonObjectPosition(glm::vec3(posMoon.x, posMoon.y, posMoon.z));

		glUniformMatrix4fv(myShader->getUnifromModel(), 1, GL_FALSE, glm::value_ptr(moonMatrix));
		glUniformMatrix4fv(myShader->getUniformProjectionModel(), 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(myShader->getCameraViewLoc(), 1, GL_FALSE, glm::value_ptr(myCamera.calculateCameraViewMatrix()));

		texttureMoon.applyTexture();
		shinyMoon.UseMaterialProperty(myShader->GetSpecularIntensity(), myShader->GetShininess());
		moonModel->RenderModel();

		/*********************************************************************************************************** */
		//Lamp Model

		glm::mat4 lampModel1;
		lampModel1 = glm::translate(lampModel1, glm::vec3(0.0, -3.0, -20.0)); 
		//lampModel1 = glm::rotate(lampModel1, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		lampModel1 = glm::scale(lampModel1, glm::vec3(0.2f, 0.2f, 0.2f)); 
		lampModel1 = glm::translate(lampModel1, glm::vec3(0.157999, -14.459006, 0.000000)); //v -0.157999 14.459006 0.000000

		//glm::vec4 posMoon = moonMatrix * glm::vec4(1.0f, 1.0f, 1.0f, 1.0);
		//myCamera.SetStaticObjectPosition(glm::vec3(posMoon.x, posMoon.y, posMoon.z));

		glUniformMatrix4fv(myShader->getUnifromModel(), 1, GL_FALSE, glm::value_ptr(lampModel1));
		glUniformMatrix4fv(myShader->getUniformProjectionModel(), 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(myShader->getCameraViewLoc(), 1, GL_FALSE, glm::value_ptr(myCamera.calculateCameraViewMatrix()));

		texttureLamp.applyTexture();
		//shinyObject.UseMaterialProperty(myShader->GetSpecularIntensity(), myShader->GetShininess());
		lampModel->RenderModel();

		/*********************************************************************************************************** */
		//Ufo Model

		glm::mat4 ufoModel1;
		ufoModel1 = glm::translate(ufoModel1, glm::vec3(4.0, 7.5, -20.0));
		ufoModel1 = glm::rotate(ufoModel1, rotate->genCurrentValue(), glm::vec3(0.0f, 1.5f, 0.0f));
		ufoModel1 = glm::translate(ufoModel1, glm::vec3(6.0, 0.0, 0.0));
		ufoModel1 = glm::scale(ufoModel1, glm::vec3(0.3f, 0.3f, 0.3f));  //datsun
		ufoModel1 = glm::rotate(ufoModel1, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));

		//glm::vec4 worldCL1 = ufoModel1 * glm::vec4(0.5f, 1.0f, 0.5f, 1.0);
		//myCamera.SetMovingObjectPosition(glm::vec3(worldCL1.x, worldCL1.y, worldCL1.z));
		
		glUniformMatrix4fv(myShader->getUnifromModel(), 1, GL_FALSE, glm::value_ptr(ufoModel1));
		glUniformMatrix4fv(myShader->getUniformProjectionModel(), 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(myShader->getCameraViewLoc(), 1, GL_FALSE, glm::value_ptr(myCamera.calculateCameraViewMatrix()));

		texttureUfo.applyTexture();
		ufoModel->RenderModel();

		/*********************************************************************************************************** */
		//Auxiliar Model(to see from the ufo to the cottage)
		glm::mat4 model4;
		model4 = glm::translate(model4, glm::vec3(3.5, 9.0, -20.0)); //translation to bring the view on the projection plane
		model4 = glm::rotate(model4, rotate->genCurrentValue(), glm::vec3(0.0f, 1.5f, 0.0f));
		model4 = glm::translate(model4, glm::vec3(6.0, 0.0, 0.0));
		model4 = glm::scale(model4, glm::vec3(0.001f, 0.001f, 0.001f));  //initial scaling
		//model4 = glm::translate(model4, glm::vec3(-1.606969, 4.698463, 0.5848889)); // Model 1.606969 -4.698463 -0.5848889

		glUniformMatrix4fv(myShader->getUnifromModel(), 1, GL_FALSE, glm::value_ptr(model4));
		glUniformMatrix4fv(myShader->getUniformProjectionModel(), 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(myShader->getCameraViewLoc(), 1, GL_FALSE, glm::value_ptr(myCamera.calculateCameraViewMatrix()));

		glm::vec4 worldCL1 = model4 * glm::vec4(0.5f, 1.0f, 0.5f, 1.0);
		myCamera.SetMovingObjectPosition(glm::vec3(worldCL1.x, worldCL1.y, worldCL1.z));

		/*********************************************************************************************************** */
		//Ufo Model parking

		glm::mat4 ufoModelP;
		ufoModelP = glm::translate(ufoModelP, glm::vec3(0.5, -5.5, -21.0));
		//ufoModelP = glm::rotate(ufoModelP, rotate->genCurrentValue(), glm::vec3(0.0f, 1.5f, 0.0f));
		//ufoModelP = glm::translate(ufoModelP, glm::vec3(6.0, 0.0, 0.0));
		ufoModelP = glm::scale(ufoModelP, glm::vec3(0.3f, 0.3f, 0.3f));  //datsun
		ufoModelP = glm::rotate(ufoModelP, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));

		glm::vec4 worldCL = ufoModelP * glm::vec4(1.0f, 1.0f, 1.0f, 1.0);
		myCamera.SetStaticObjectPosition(glm::vec3(worldCL.x, worldCL.y + 1, worldCL.z));

		glUniformMatrix4fv(myShader->getUnifromModel(), 1, GL_FALSE, glm::value_ptr(ufoModelP));
		glUniformMatrix4fv(myShader->getUniformProjectionModel(), 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(myShader->getCameraViewLoc(), 1, GL_FALSE, glm::value_ptr(myCamera.calculateCameraViewMatrix()));

		texttureUfo.applyTexture();
		ufoModelParking->RenderModel();

		myWindow.swapBuffers(); //Swap buffers, OpenGL main tains two Buffers, One is displayed, one is getting prepared
	}

	return 0;
}