#include "Shape.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

void Shape::setColor(glm::vec4 newColor)
{
    color = glm::vec4(newColor);
}

void Shape::setColor(float red, float green, float blue, float alpha)
{
    return setColor(glm::vec4(red, green, blue, alpha));
}

void Shape::setColor(int red, int green, int blue, int alpha) {
    return setColor(glm::vec4(red / 255.0f, green / 255.0f, blue / 255.0f, alpha / 255.0f));
}

glm::vec4 Shape::getColor()
{
    return color;
}

glm::mat4x4 Shape::getTransformationMat4x4()
{
    return transformationMat4x4;
}

void Shape::setTranslation(glm::vec3 newTranslation)
{
    transformationMat4x4 = glm::translate(transformationMat4x4, newTranslation);
}

void Shape::setTranslation(float transX, float transY, float transZ)
{
    setTranslation(glm::vec3(transX, transY, transZ));
}

void Shape::setRotation(float angle, glm::vec3 axis)
{
    transformationMat4x4 = glm::rotate(transformationMat4x4, angle, axis);
}

void Shape::setScale(glm::vec3 newScale)
{
    transformationMat4x4 = glm::scale(transformationMat4x4, newScale);
}

void Shape::setScale(float scaleX, float scaleY, float scaleZ)
{
    setScale(glm::vec3(scaleX, scaleY, scaleZ));
}