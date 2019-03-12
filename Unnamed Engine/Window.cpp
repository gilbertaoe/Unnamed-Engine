#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <soil.h>

#include "Camera.h"
#include "Shader.h"
#include "Window.h"
#include "Square.h"
#include "Triangle.h"

Camera *camera;


void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void myKeyCallbackFunc(GLFWwindow* window, int key, int scancode, int action, int mods)
{

}

void scrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
	camera->scroll += yoffset;
}

Window::Window()
{
	if (!glfwInit()) return;

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif

	window = glfwCreateWindow(640, 480, "Unnamed Engine", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
	glfwSetKeyCallback(window, myKeyCallbackFunc);
	glfwSetScrollCallback(window, scrollCallback);

	if (glewInit() != GLEW_OK)
	{
		std::cout << "Error" << std::endl;
		return;
	}

	glEnable(GL_DEPTH_TEST);
}

Window::~Window()
{
	glfwTerminate();
}

void Window::Run()
{
	camera = &Camera();

	Square squareMoving = Square();
	Square squareTextured = Square("a");
	Square squareTexturedBack = Square("a", 1);

	Triangle triangle = Triangle();
	Triangle triangleRed = Triangle(" ");

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//triangle.Run();
		//triangleRed.Run();


		squareMoving.Run();
		camera->Run();

		squareTextured.Run();
		camera->Run();

		squareTexturedBack.Run();
		camera->Run();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

void Window::ReturnVersion()
{
	std::cout << glGetString(GL_VERSION) << std::endl;

	return;
}