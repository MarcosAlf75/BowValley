#include "GLWindow.h"

GLWindow::GLWindow()
{
	width = 1000;
	height = 1000;
}

GLWindow::GLWindow(GLint windowWidth, GLint windowHeight)
{
	width = windowWidth;
	height = windowHeight;
}

GLWindow::~GLWindow()
{
	glfwDestroyWindow(mainWindow);
	glfwTerminate();
}

void GLWindow::offMouseClick(GLFWwindow* window)
{
	GLWindow* curWindow = static_cast<GLWindow*>(glfwGetWindowUserPointer(window));

	curWindow->mouseClick[0] = false;
	curWindow->mouseClick[1] = false;
}

//Allow to use keyboard to change the object
void GLWindow::handleKeyboardKeys(GLFWwindow* window, int key, int code, int action, int mode)
{
	GLWindow* curWindow = static_cast<GLWindow*>(glfwGetWindowUserPointer(window));

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}

	if (key >= 0 && key < 512)
	{
		if (action == GLFW_PRESS)
		{
			curWindow->kkeys[key] = true;
			cout << "Keyboard key: (" << key << ") is pressed, mode is: " << mode << "." << endl;
		}
		else if (action == GLFW_RELEASE)
		{
			curWindow->kkeys[key] = false;
			cout << "Keyboard key: (" << key << ") is released" << endl;
		}

	}
}

//Allow to use mouse into the screen
void GLWindow::handleMouseMovements(GLFWwindow* window, double xPos, double yPos)
{
	GLWindow* curWindow = static_cast<GLWindow*>(glfwGetWindowUserPointer(window));

	if (curWindow->initMouse)
	{
		curWindow->prevX = xPos;
		curWindow->prevY = yPos;
		curWindow->initMouse = false;
	}

	curWindow->xChange = xPos - curWindow->prevX;
	curWindow->yChange = curWindow->prevY - yPos;

	curWindow->prevX = xPos;
	curWindow->prevY = yPos;

	cout << "Mouse Movement(" << curWindow->xChange << "," << curWindow->yChange << ")" << endl;

}
// Print the button mouse click side, press and release
void GLWindow::handleMouseClicks(GLFWwindow* window, int button, int action, int mods)
{
	GLWindow* curWindow = static_cast<GLWindow*>(glfwGetWindowUserPointer(window));

	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
	{
		cout << "Right Mouse Button Clicked!" << endl;
		curWindow->mouseClick[1] = true;
	}
	else if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE)
	{
		cout << "Right Mouse Button Released!" << endl;
		curWindow->mouseClick[1] = false;  //Disable to watch the camera while keep pressed
	}

	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		cout << "Left Mouse Button Clicked!" << endl;
		curWindow->mouseClick[0] = true;
	}
	else if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
	{
		cout << "Left Mouse Button Released!" << endl;
		curWindow->mouseClick[0] = false; //Disable to watch the camera while keep pressed
	}
}

//Handle the mouse scroll
void GLWindow::handleMouseScroll(GLFWwindow* window, double xoffset, double yoffset)
{
	GLWindow* curWindow = static_cast<GLWindow*>(glfwGetWindowUserPointer(window));

	curWindow->setAngle(curWindow->getAngle() + yoffset);

	if (curWindow->getAngle() < curWindow->minAngle)
		curWindow->setAngle(curWindow->minAngle);
	if (curWindow->getAngle() > curWindow->maxAngle)
		curWindow->setAngle(curWindow->maxAngle);


	cout << "Current angle => " << curWindow->getAngle() << endl;
	cout << "Scroll Movement (" << yoffset << ")" << endl;
}

void GLWindow::setAngle(GLfloat setValue)
{
	perspectiveAngle = setValue;
}

int GLWindow::InitGLWindow()
{
	// Initialise GLFW
	if (!glfwInit())  //initializes OpenGL Window System
	{
		printf("GLFW initialisation failed!");
		glfwTerminate(); //terminate due to error
		return 1;
	}

	// Setup GLFW window properties and version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);  // Major and minor version is 3.X
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);  //
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // Core Profile means No Backwards Compatibility
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); 	// Allow Forward Compatbility

	// Create the window
	mainWindow = glfwCreateWindow(width, height, "Welcome Marcos T. to DESN3306!", NULL, NULL); // Create Main Window

	if (!mainWindow)
	{
		printf("GLFW window creation failed!");
		glfwTerminate(); //terminate due to error
		return 1;
	}
	// Get Buffer Size information
	//int bufferWidth, bufferHeight;
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight); //bufferwidth and bufferHeight is system dependent so, load them.
	glfwMakeContextCurrent(mainWindow); // Set mainWindow as context for GLEW
	glewExperimental = GL_TRUE; 	// Allow modern features

	if (glewInit() != GLEW_OK)
	{
		printf("GLEW initialisation failed!");
		glfwDestroyWindow(mainWindow);  //clear resources already allocated
		glfwTerminate();  //terminate due to error
		return 1;
	}

	glEnable(GL_DEPTH_TEST);
	glViewport(0, 0, bufferWidth, bufferHeight); // Setup the Viewport dimension

	// Handle Keyboard keys 
	glfwSetKeyCallback(mainWindow, handleKeyboardKeys);

	// Handle Mouse Movement
	glfwSetCursorPosCallback(mainWindow, handleMouseMovements);

	// Handle Mouse Click
	glfwSetMouseButtonCallback(mainWindow, handleMouseClicks);

	// Handle Mouse Scroll
	glfwSetScrollCallback(mainWindow, handleMouseScroll);

	glfwSetWindowUserPointer(mainWindow, this);

	return 0;
}


