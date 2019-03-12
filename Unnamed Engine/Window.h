#pragma once
#include <GLFW/glfw3.h>

#include "Camera.h"

class Window
{
public:
	Window();
	~Window();

	void Run();
	void ReturnVersion();

private:
	GLFWwindow *window;
};