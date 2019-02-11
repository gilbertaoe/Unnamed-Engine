#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <soil.h>

#include "Shader.h"
#include "Window.h"
#include "Square.h"
#include "Triangle.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
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
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

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
	Square squareMoving = Square();
	Square squareTextured = Square("a");
	Square squareTexturedBack = Square("a", 1);

	Triangle triangle = Triangle();
	Triangle triangleRed = Triangle(" ");

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		triangle.Run();
		triangleRed.Run();
		squareMoving.Run();
		squareTextured.Run();
		squareTexturedBack.Run();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

void Window::ReturnVersion()
{
	std::cout << glGetString(GL_VERSION) << std::endl;

	return;
}