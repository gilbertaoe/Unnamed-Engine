#pragma once
#include "Shader.h"

class Square
{
public:
	Square();
	Square(const char* src);
	Square::Square(const char* src, int a);
	~Square();

	void Run();

private:
	Shader *shader;
	GLuint tex_2d;
	unsigned int VBO, VAO, EBO;
	bool isTexture;
	bool isStatic;
};