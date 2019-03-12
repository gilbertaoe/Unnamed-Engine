#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Camera.h"
#include "Shader.h"

Camera::Camera()
{
	shader = new Shader("Shaders/Vertex/VertexCamera.shader", "Shaders/Fragment/BasicFragment.shader");
	model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
	view = glm::mat4(1.0f);
	projection = glm::mat4(1.0f);
}

Camera::~Camera()
{

}

void Camera::Run()
{
	// create transformations
	model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
	view = glm::mat4(1.0f);
	projection = glm::mat4(1.0f);

	model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(0.0f, 0.0f, 1.0f));

	view = glm::translate(view, glm::vec3(0.0f, 0.0f, scroll));

	projection = glm::perspective(glm::radians(45.0f), (float)640 / (float)480, 0.1f, 100.0f);

	// retrieve the matrix uniform locations
	modelLoc = glGetUniformLocation(shader->ID, "model");
	viewLoc = glGetUniformLocation(shader->ID, "view");

	// pass them to the shaders (3 different ways)
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);

	// note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
	shader->setMat4("projection", projection);
}