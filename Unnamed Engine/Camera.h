#pragma once
#include "Shader.h"

class Camera
{
public:
	Camera();
	~Camera();

	void Run();

	float scroll = 0.0f;

private:
	Shader *shader;

	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 projection;

	unsigned int modelLoc;
	unsigned int viewLoc;
};