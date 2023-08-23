#pragma once

#include <GL\glew.h>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <GLFW\glfw3.h>

class Camera_Control
{
public:
	Camera_Control();
	Camera_Control(glm::vec3 initialPosition, glm::vec3 initialUp, GLfloat initialYaw, GLfloat initialPitch, GLfloat initialKeyboardMoveSpeed);

	void SetStaticObjectPosition(glm::vec3 objPosition);
	void SetMovingObjectPosition(glm::vec3 objPosition);
	void SetMoonObjectPosition(glm::vec3 objPosition);
	void keyboardControl(bool* kkeys, GLfloat deltaTime);
	void mouseClickControl(bool* mouseClick);
	glm::mat4 calculateCameraViewMatrix();
	~Camera_Control();

private:

	void updateAllPositions();
	void setCameraPosition(glm::vec3 pos);
	void setCameraDirection(glm::vec3 pos);
	glm::vec3 getCameraPosition();
	glm::vec3 getCameraDirection();
	void getFrontPosition();
	void getTopView();
	void getRightView();
	void getMoonView();

	glm::vec3 staticObject;
	glm::vec3 movingObject;
	glm::vec3 moonObject;
	glm::vec3 curPos;
	glm::vec3 goFront;
	glm::vec3 lookUp;
	glm::vec3 lookRight;
	glm::vec3 referenceWorldUp;

	glm::vec3 curPosFront;
	glm::vec3 referenceWorldUpFront;
	GLfloat yawFront;
	GLfloat pitchFront;
	
	glm::vec3 curPosUp;
	glm::vec3 referenceWorldUpUp;
	GLfloat yawUp;
	GLfloat pitchUp;

	glm::vec3 curPosRight;
	glm::vec3 referenceWorldUpRight;
	GLfloat yawRight;
	GLfloat pitchRight;

	GLfloat yaw;
	GLfloat pitch;

	GLfloat keyboardMoveSpeed;
	bool movementCamera = false;
	bool clickRight = false;
	bool clickLeft = false;
};