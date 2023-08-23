#include "Camera_Control.h"
#include <iostream>
#include "GLWindow.h"

using namespace std;



Camera_Control::Camera_Control()
{
}

Camera_Control::Camera_Control(glm::vec3 initialPosition, glm::vec3 initialUp, GLfloat initialYaw, GLfloat initialPitch, GLfloat initialKeyboardMoveSpeed)
{
	curPos = initialPosition;
	referenceWorldUp = initialUp;
	yaw = initialYaw;
	pitch = initialPitch;
	goFront = glm::vec3(0.0f, 0.0f, -1.0f);

	//Set Front Position
	curPosFront = curPos;
	referenceWorldUpFront = referenceWorldUp;
	yawFront = yaw;
	pitchFront = pitch;

	keyboardMoveSpeed = initialKeyboardMoveSpeed;
	updateAllPositions();
}

void Camera_Control::updateAllPositions()
{
	goFront.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	goFront.y = sin(glm::radians(pitch));
	goFront.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	goFront = glm::normalize(goFront);

	lookRight = glm::normalize(glm::cross(goFront, referenceWorldUp));
	lookUp = glm::normalize(glm::cross(lookRight, goFront));
}
void Camera_Control::keyboardControl(bool* kkeys, GLfloat deltaTime)
{
	GLfloat speed = keyboardMoveSpeed * deltaTime;

	if (kkeys[GLFW_KEY_UP])
	{
		curPos += goFront * keyboardMoveSpeed;
	}

	if (kkeys[GLFW_KEY_DOWN])
	{
		curPos -= goFront * keyboardMoveSpeed;
	}

	if (kkeys[GLFW_KEY_LEFT])
	{
		curPos -= lookRight * keyboardMoveSpeed;
	}

	if (kkeys[GLFW_KEY_RIGHT])
	{
		curPos += lookRight * keyboardMoveSpeed;
	}
	if (kkeys[GLFW_KEY_F2])
	{
		movementCamera = false;
		clickLeft = false;
		clickRight = false;

		getFrontPosition();
	}
	if (kkeys[GLFW_KEY_F3])
	{
		movementCamera = false;
		clickLeft = false;
		clickRight = false;

		getMoonView();
	}
	if (kkeys[GLFW_KEY_F4])
	{
		movementCamera = false;
		clickLeft = false;
		clickRight = false;

		getRightView();
	}

	
}

void Camera_Control::mouseClickControl(bool* mouseClick)
{
	//Mouse click left - static object
	if (mouseClick[0])
	{
		movementCamera = true;
		clickLeft = true;
		clickRight = false;
		yaw = yawFront;
		pitch = pitchFront;
	}
	//Mouse click Right - moving object
	if (mouseClick[1])
	{
		movementCamera = true;
		clickLeft = false;
		clickRight = true;
		yaw = yawFront;
		pitch = pitchFront;
	}

	if (movementCamera && clickLeft)
	{
		setCameraPosition(staticObject);
		setCameraDirection(movingObject - staticObject);
		goFront = getCameraDirection();
	}

	if (movementCamera && clickRight)
	{
		setCameraPosition(movingObject);
		setCameraDirection(staticObject - movingObject);
		goFront = getCameraDirection();
	}
}

void Camera_Control::getFrontPosition()
{
	curPos = curPosFront;
	//referenceWorldUp = referenceWorldUpFront;
	yaw = yawFront;
	pitch = pitchFront;

	updateAllPositions();
}
void Camera_Control::getTopView()
{
	curPos = glm::vec3(staticObject.x, staticObject.y + 18, staticObject.z+1);
	//referenceWorldUp = referenceWorldUpFront;
	yaw = -90;
	pitch = -85;

	updateAllPositions();

}
void Camera_Control::getRightView()
{
	setCameraPosition(staticObject);
	setCameraDirection(moonObject - staticObject);
	goFront = getCameraDirection();
}
void Camera_Control::getMoonView()
{
	setCameraPosition(moonObject);
	setCameraDirection(staticObject - moonObject);
	goFront = getCameraDirection();
}

void Camera_Control::SetStaticObjectPosition(glm::vec3 objPosition)
{
	staticObject = objPosition;
}
void Camera_Control::SetMovingObjectPosition(glm::vec3 objPosition)
{
	movingObject = objPosition;
}
void Camera_Control::SetMoonObjectPosition(glm::vec3 objPosition)
{
	moonObject = objPosition;
}



void Camera_Control::setCameraPosition(glm::vec3 pos)
{
	curPos = pos;
}

void Camera_Control::setCameraDirection(glm::vec3 pos)
{
	goFront = glm::normalize(pos);
}

glm::vec3 Camera_Control::getCameraPosition()
{
	return curPos;
}

glm::vec3 Camera_Control::getCameraDirection()
{
	return glm::normalize(goFront);
}

glm::mat4 Camera_Control::calculateCameraViewMatrix()
{
	return glm::lookAt(curPos, curPos + goFront, lookUp);
}

Camera_Control::~Camera_Control()
{
}












