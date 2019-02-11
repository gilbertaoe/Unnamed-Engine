#pragma once
#include "Shader.h"

class Triangle
{
public:
	Triangle();
	Triangle(char *src);
	~Triangle();

	void Run();

private:
	Shader *shader;
	unsigned int VBO, VAO, EBO;
};