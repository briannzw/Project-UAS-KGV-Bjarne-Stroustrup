#pragma once

#include "glm.hpp";
#include "Shape.h";

class Circle : public Shape {

public:
    static unsigned int vertexArray;
    static unsigned int vertexBuffer;
    static unsigned int indexBuffer;

    Circle();
    void draw();

private:
    float pi = 2 * acos(0.0);
    float vertices[3000];
    int index = 2;
    float x, y;

    unsigned int indexArr[3000 * 3];
};