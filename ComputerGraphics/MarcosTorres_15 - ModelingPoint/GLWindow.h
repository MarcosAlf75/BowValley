#pragma once
#pragma once
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include<iostream>

using namespace std;

class GLWindow
{
public:
	GLWindow();
	GLWindow(GLint windowWidth, GLint windowHeight);
	int InitGLWindow();
	GLint getBufferWidth() { return bufferWidth; }
	GLint getBufferHeight() { return bufferHeight; }
	bool isWindowClosed() { return glfwWindowShouldClose(mainWindow); }
	void swapBuffers() { glUseProgram(0); glfwSwapBuffers(mainWindow); }
	static void handleKeyboardKeys(GLFWwindow* window, int key, int code, int action, int mode);
	static void handleMouseMovements(GLFWwindow* window, double xPos, double yPos);
	static void handleMouseClicks(GLFWwindow* window, int button, int action, int mods);
	static void handleMouseScroll(GLFWwindow* window, double xoffset, double yoffset);
	bool* getsKeybordKeys() { return kkeys; }
	GLfloat getXChange();
	GLfloat getYChange();
	~GLWindow();

	//Define initial default angles and methods
	GLfloat getAngle() { return perspectiveAngle; }
	void setAngle(GLfloat setAngle);
	GLfloat minAngle = 0;
	GLfloat maxAngle = 359;

private:
	GLFWwindow* mainWindow;
	GLint width, height;
	GLint bufferWidth, bufferHeight;

	//NewAddition
	bool kkeys[512];

	//NewAdditionForMouse
	bool initMouse = true;
	GLfloat prevX;
	GLfloat prevY;
	GLfloat xChange;
	GLfloat yChange;

	//AdditionForScroll
	GLfloat perspectiveAngle = 50;
};
