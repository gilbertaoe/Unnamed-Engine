#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Shader.h"

class Window
{
public:
	Window();
	~Window();

	void Run();
	void ReturnVersion();

private:
	Shader *shader;
	GLFWwindow* window;
};