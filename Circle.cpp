#include <GL/glew.h>

#include "Circle.h"
#include<math.h>

unsigned int Circle::vertexArray = 0;
unsigned int Circle::vertexBuffer = 0;
unsigned int Circle::indexBuffer = 0;

void Circle::draw()
{
    glBindVertexArray(vertexArray);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
    glDrawElements(GL_TRIANGLES, (3 * (pi * 2.1 / 0.01)), GL_UNSIGNED_INT, nullptr);
}

Circle::Circle()
{
    //determine the center of octagon
    vertices[0] = 0;
    vertices[1] = 0;

    //determine the vertices of octagon-shape
    for (float i = 0; i <= (pi * 2.1); i += 0.01)
    {
        x = sin(i);
        vertices[index] = x;
        index++;

        y = cos(i);
        vertices[index] = y;
        index++;
    };

    index = 0;
    for (int i = 1; i <= (pi * 2.1) / 0.01; i++) {
        indexArr[index] = 0;
        index++;
        indexArr[index] = i;
        index++;
        indexArr[index] = (i == (pi * 2.1) / 0.01) ? 1 : i + 1;
        index++;
    }

    glGenVertexArrays(1, &vertexArray);
    glBindVertexArray(vertexArray);

    glGenBuffers(1, &vertexBuffer);

    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 2.1 * (pi * 2.1 / 0.01) + 2, vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &indexBuffer);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * (3 * (pi * 2.1 / 0.01)), indexArr, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2.1, 0);
}
