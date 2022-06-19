#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

#include "util.h"

#include "Square.h"
#include "Circle.h"
#include "Triangle.h"
#include "Trapezoid.h"

unsigned int program;

float currentTime = 0.0f;
float lastTime = 0.0f;
float deltaTime = 0.0f;

float counter = 0;
float minuteTick = 0, hourTick = 0;
float timeModifier = 1;

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_C && action == GLFW_PRESS) {

    }
    if (key == GLFW_KEY_UP && action == GLFW_PRESS) {
        if(timeModifier > 0.1) timeModifier -= 0.1;
    }
    if (key == GLFW_KEY_DOWN && action == GLFW_PRESS) {
        if(timeModifier < 2.0) timeModifier += 0.1;
    }
}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(720, 720, "Project UAS - Bjarne Stroustrup", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwSetKeyCallback(window, keyCallback);

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    GLenum err = glewInit();

    const float pi = 3.14159265359;
    float degToRad = pi / 180;

    vector<Square> sq;
    vector<Circle> ci;
    vector<Triangle> tr;
    vector<Trapezoid> trp;

    Square s;
    Circle c;
    Triangle t;
    Trapezoid tp;

#pragma region Start Draw
    //Outer Frame
    s = Square();
    s.setTranslation(0, 0.02, 0);
    s.setColor(170, 132, 70, 255);
    s.setScale(0.2, 0.2, 1.0);
    sq.push_back(s);

    //Inner Frame
    s = Square();
    s.setTranslation(0, 0.02, 0);
    s.setScale(0.9, 0.9, 1);
    s.setColor(153, 118, 64, 255);
    s.setScale(0.2, 0.2, 1.0);
    sq.push_back(s);

    //Clock
    c = Circle();
    c.setTranslation(0, 0.02, 0);
    c.setScale(0.8, 0.8, 1.0);
    c.setScale(0.2, 0.2, 1.0);
    ci.push_back(c);

    c = Circle();
    c.setTranslation(0, 0.02, 0);
    c.setScale(0.725, 0.725, 1.0);
    c.setColor(0, 0, 0, 1);
    c.setScale(0.2, 0.2, 1.0);
    ci.push_back(c);

    c = Circle();
    c.setTranslation(0, 0.02, 0);
    c.setScale(0.7, 0.7, 1.0);
    c.setScale(0.2, 0.2, 1.0);
    ci.push_back(c);

    c = Circle();
    c.setTranslation(0, 0.02, 0);
    c.setScale(0.04, 0.04, 1.0);
    c.setColor(0, 0, 0, 1);
    c.setScale(0.2, 0.2, 1.0);
    ci.push_back(c);

    //Minute Tick
    s = Square();
    s.setTranslation(0, 0.02, 0);
    s.setRotation(0 * degToRad, glm::vec3(0, 0, 1));
    s.setTranslation(0, 0.3 * 0.2, 0);
    s.setScale(0.025, 0.3, 1.0);
    s.setColor(0, 0, 0, 1);
    s.setScale(0.2, 0.2, 1.0);
    sq.push_back(s);
    
    //Hour Tick
    s = Square();
    s.setTranslation(0, 0.02, 0);
    s.setRotation(60 * degToRad, glm::vec3(0,0,1));
    s.setTranslation(0, -0.175 * 0.2, 0);
    s.setScale(0.025, 0.2, 1.0);
    s.setColor(0, 0, 0, 1);
    s.setScale(0.2, 0.2, 1.0);
    sq.push_back(s);

    // Atap
    t = Triangle();
    t.setTranslation(0, 0.66, 1);
    t.setScale(0.2, 0.26, 1);
    t.setColor(52, 50, 51, 255);
    t.setScale(0.5, 0.5, 1.0);
    tr.push_back(t);

    s = Square();
    s.setTranslation(0, 0.515, 1);
    s.setScale(0.21, 0.03, 1);
    s.setColor(170, 132, 70, 255);
    s.setScale(0.5, 0.5, 1.0);
    sq.push_back(s);

    s = Square();
    s.setTranslation(0, 0.47, 1);
    s.setScale(0.17, 0.08, 1);
    s.setColor(170, 132, 70, 255);
    s.setScale(0.5, 0.5, 1.0);
    sq.push_back(s);

    c = Circle();
    c.setTranslation(0, 0.8, 1);
    c.setScale(0.03, 0.03, 1);
    c.setColor(52, 50, 51, 255);
    c.setScale(0.5, 0.5, 1.0);
    ci.push_back(c);

    // Atap 2
    //Trapesium
    tp = Trapezoid();
    tp.setColor(52, 50, 53, 255);
    //perbandingan lebar : tinggi = 3:1
    tp.setTranslation(0, 0.4, 1);
    tp.setScale(0.18, 0.06, 1);
    trp.push_back(tp);

    //Square 1
    s = Square();
    s.setTranslation(0, 0.32, 1);
    s.setScale(0.2, 0.02, 1);
    s.setColor(170, 132, 70, 255);
    sq.push_back(s);

    //Square 2
    s = Square();
    s.setTranslation(0, 0.26, 1);
    s.setScale(0.18, 0.04, 1);
    s.setColor(153, 118, 64, 255);
    sq.push_back(s);

#pragma region Pillar
    float offset = -0.45;
    //pillar
    s = Square();
    s.setTranslation(0, -0.11 + offset, 0);
    s.setScale(0.16, 0.38, 1);
    s.setColor(153, 118, 64, 255);
    sq.push_back(s);

    //detailhorizontal1
    s = Square();
    s.setTranslation(0, 0.05 + offset, 0);
    s.setScale(0.16, 0.01, 1);
    s.setColor(122, 89, 37, 255);
    sq.push_back(s);

    //detailvertical1
    s = Square();
    s.setTranslation(0, 0.05 + offset, 0);
    s.setTranslation(-0.1, 0.05, 0);
    s.setScale(0.01, 0.05, 1);
    s.setColor(122, 89, 37, 255);
    sq.push_back(s);

    //detailvertical2
    s = Square();
    s.setTranslation(0, offset, 0);
    s.setTranslation(0, 0.1, 0);
    s.setScale(0.01, 0.05, 1);
    s.setColor(122, 89, 37, 255);
    sq.push_back(s);

    //detailvertical3
    s = Square();
    s.setTranslation(0, offset, 0);
    s.setTranslation(0.1, 0.1, 0);
    s.setScale(0.01, 0.05, 1);
    s.setColor(122, 89, 37, 255);
    sq.push_back(s);

    //detailhorizontal2
    s = Square();
    s.setTranslation(0, offset, 0);
    s.setTranslation(0, 0.01, 0);
    s.setScale(0.16, 0.01, 1);
    s.setColor(122, 89, 37, 255);
    sq.push_back(s);

    //detailhorizontal3
    s = Square();
    s.setTranslation(0, offset, 0);
    s.setTranslation(0, -0.15, 0);
    s.setScale(0.16, 0.01, 1);
    s.setColor(122, 89, 37, 255);
    sq.push_back(s);

    //detailvertical4
    s = Square();
    s.setTranslation(0, offset, 0);
    s.setTranslation(-0.1, -0.1, 0);
    s.setScale(0.01, 0.05, 1);
    s.setColor(122, 89, 37, 255);
    sq.push_back(s);

    //detailvertical5
    s = Square();
    s.setTranslation(0, offset, 0);
    s.setTranslation(0, -0.1, 0);
    s.setScale(0.01, 0.05, 1);
    s.setColor(122, 89, 37, 255);
    sq.push_back(s);

    //detailvertical6
    s = Square();
    s.setTranslation(0, offset, 0);
    s.setTranslation(0.1, -0.1, 0);
    s.setScale(0.01, 0.05, 1);
    s.setColor(122, 89, 37, 255);
    sq.push_back(s);

    //detailhorizontal4
    s = Square();
    s.setTranslation(0, offset, 0);
    s.setTranslation(0, -0.2, 0);
    s.setScale(0.16, 0.01, 1);
    s.setColor(122, 89, 37, 255);
    sq.push_back(s);

    //detailhorizontal5
    s = Square();
    s.setTranslation(0, offset, 0);
    s.setTranslation(0, -0.35, 0);
    s.setScale(0.16, 0.01, 1);
    s.setColor(122, 89, 37, 255);
    sq.push_back(s);

    //detailvertical4
    s = Square();
    s.setTranslation(0, offset, 0);
    s.setTranslation(-0.1, -0.3, 0);
    s.setScale(0.01, 0.05, 1);
    s.setColor(122, 89, 37, 255);
    sq.push_back(s);

    //detailvertical4
    s = Square();
    s.setTranslation(0, offset, 0);
    s.setTranslation(0, -0.3, 0);
    s.setScale(0.01, 0.05, 1);
    s.setColor(122, 89, 37, 255);
    sq.push_back(s);

    //detailvertical4
    s = Square();
    s.setTranslation(0, offset, 0);
    s.setTranslation(0.1, -0.3, 0);
    s.setScale(0.01, 0.05, 1);
    s.setColor(122, 89, 37, 255);
    sq.push_back(s);

    //detailhorizontal5
    s = Square();
    s.setTranslation(0, offset, 0);
    s.setTranslation(0, -0.4, 0);
    s.setScale(0.16, 0.01, 1);
    s.setColor(122, 89, 37, 255);
    sq.push_back(s);

    //bottom pillar
    s = Square();
    s.setTranslation(0, offset, 0);
    s.setTranslation(0, -0.5, 0);
    s.setScale(0.2, 0.05, 1);
    s.setColor(170, 132, 70, 255);
    sq.push_back(s);
#pragma endRegion
#pragma endRegion

    string vertexString = readFile("vertex.vert");
    string fragmentString = readFile("fragment.frag");

    const char* vertexChar = vertexString.c_str();
    const char* fragmentChar = fragmentString.c_str();

    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vertexShader, 1, &vertexChar, NULL);
    glShaderSource(fragmentShader, 1, &fragmentChar, NULL);

    glCompileShader(vertexShader);
    glCompileShader(fragmentShader);

    program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);

    glLinkProgram(program);
    glUseProgram(program);

    GLint uColor = glGetUniformLocation(program, "uColor");
    GLint uTransformationMat4x4 = glGetUniformLocation(program, "uTransformationMatrix");

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.870f, 0.886f, 0.945f, 1.0f);

        for(int i = 0; i < sq.size(); i++)
        {
            glUniform4fv(uColor, 1, &sq[i].getColor()[0]);
            glUniformMatrix4fv(uTransformationMat4x4, 1, GL_FALSE, &sq[i].getTransformationMat4x4()[0][0]);
            sq[i].draw();
        };

        for (int i = 0; i < ci.size(); i++)
        {
            glUniform4fv(uColor, 1, &ci[i].getColor()[0]);
            glUniformMatrix4fv(uTransformationMat4x4, 1, GL_FALSE, &ci[i].getTransformationMat4x4()[0][0]);
            ci[i].draw();
        };

        for (int i = 0; i < tr.size(); i++)
        {
            glUniform4fv(uColor, 1, &tr[i].getColor()[0]);
            glUniformMatrix4fv(uTransformationMat4x4, 1, GL_FALSE, &tr[i].getTransformationMat4x4()[0][0]);
            tr[i].draw();
        };

        for (int i = 0; i < trp.size(); i++)
        {
            glUniform4fv(uColor, 1, &trp[i].getColor()[0]);
            glUniformMatrix4fv(uTransformationMat4x4, 1, GL_FALSE, &trp[i].getTransformationMat4x4()[0][0]);
            trp[i].draw();
        }

        //Dynamic Clock
        currentTime = glfwGetTime();
        deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        counter += deltaTime;
        if (counter >= 1.0f * timeModifier) {
            counter = 0.0f;

            minuteTick++;
            hourTick += (1 / 12.0);

            //Minute Tick
            s = Square();
            s.setTranslation(0, 0.02, 0);
            s.setRotation((0 - (30 * minuteTick)) * degToRad, glm::vec3(0, 0, 1));
            s.setTranslation(0, 0.3 * 0.2, 0);
            s.setScale(0.025, 0.3, 1.0);
            s.setColor(0, 0, 0, 1);
            s.setScale(0.2, 0.2, 1.0);
            sq[2] = s;
            //Hour Tick
            s = Square();
            s.setTranslation(0, 0.02, 0);
            s.setRotation((60 - (30 * hourTick)) * degToRad, glm::vec3(0, 0, 1));
            s.setTranslation(0, -0.175 * 0.2, 0);
            s.setScale(0.025, 0.2, 1.0);
            s.setColor(0, 0, 0, 1);
            s.setScale(0.2, 0.2, 1.0);
            sq[3] = s;
        }

        //Priority
        glUniform4fv(uColor, 1, &sq[2].getColor()[0]);
        glUniformMatrix4fv(uTransformationMat4x4, 1, GL_FALSE, &sq[2].getTransformationMat4x4()[0][0]);
        sq[2].draw();

        //Priority
        glUniform4fv(uColor, 1, &sq[3].getColor()[0]);
        glUniformMatrix4fv(uTransformationMat4x4, 1, GL_FALSE, &sq[3].getTransformationMat4x4()[0][0]);
        sq[3].draw();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}