#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <iostream>
#include <cmath>
#include <stb.h>
#include<OpenGLPrj.hpp>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);



const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"uniform vec3 myPos;"
"void main()\n"
"{\n"
"   gl_Position = vec4(myPos.x + aPos.x, myPos.y + aPos.y, myPos.z + aPos.z, 1.0);\n"
"}\0";
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.5f, 1.0f, 1.0f, 1.0f);\n"
"}\n\0";

const char* fragmentShaderSource2 = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);\n"
"}\n\0";

static float x_coord, y_coord;

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif
    // settings 
    const unsigned int SCR_WIDTH = 800;
    const unsigned int SCR_HEIGHT = 800;

    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    int fragmentShader2 = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader2, 1, &fragmentShaderSource2, NULL);
    glCompileShader(fragmentShader2);
    glGetShaderiv(fragmentShader2, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader2, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    int shaderProgram2 = glCreateProgram();
    glAttachShader(shaderProgram2, vertexShader);
    glAttachShader(shaderProgram2, fragmentShader2);
    glLinkProgram(shaderProgram2);
    glGetProgramiv(shaderProgram2, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram2, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    glDeleteShader(fragmentShader2);
    //Draw vertices around circle perimeter

    std::vector<float> vertices;

    //drawing ghosty

    //vertices head
    float res = 10;
    float radius = 0.3f;
    float angle = 0.0f;
    float angle_inc = M_PI / 10.0f;

    vertices.push_back(0.0f);
    vertices.push_back(0.0f);
    vertices.push_back(0.0f);

    for (int i = 0; i <= 10; i++) {
        vertices.push_back(radius * cos(angle));
        vertices.push_back(radius * sin(angle));
        vertices.push_back(0.0f);
        angle += angle_inc;
    }

    //drawing body
    vertices.push_back(radius);
    vertices.push_back(0.0f);
    vertices.push_back(0.0f);

    vertices.push_back(-radius);
    vertices.push_back(0.0f);
    vertices.push_back(0.0f);

    vertices.push_back(-radius);
    vertices.push_back(-radius);
    vertices.push_back(0.0f);

    //second triangle
    vertices.push_back(-radius);
    vertices.push_back(0.0f);
    vertices.push_back(0.0f);

    vertices.push_back(radius);
    vertices.push_back(0.0f);
    vertices.push_back(0.0f);

    vertices.push_back(radius);
    vertices.push_back(-radius);
    vertices.push_back(0.0f);

    //third triangle
    vertices.push_back(-radius);
    vertices.push_back(0.0f);
    vertices.push_back(0.0f);

    vertices.push_back(radius);
    vertices.push_back(0.0f);
    vertices.push_back(0.0f);

    vertices.push_back(radius / 2.8);
    vertices.push_back(-radius);
    vertices.push_back(0.0f);

    //fourth leg
    vertices.push_back(radius);
    vertices.push_back(0.0f);
    vertices.push_back(0.0f);

    vertices.push_back(-radius);
    vertices.push_back(0.0f);
    vertices.push_back(0.0f);

    vertices.push_back(-radius / 2.8);
    vertices.push_back(-radius);
    vertices.push_back(0.0f);

    //eyes

    float radius_eyes_W = 0.08f;
    float radius_eyes_H = 0.15f;
    angle = 0.0f;
    angle_inc = M_PI / res;
    float xc, yc;
    xc = -radius / 2;
    yc = 0.0f;


    for (int j = 0; j < 2; j++) {
        vertices.push_back(xc);
        vertices.push_back(yc);
        vertices.push_back(0.0f);

        for (int i = 0; i <= res * 2; i++) {
            vertices.push_back(xc + radius_eyes_W * cos(angle));
            vertices.push_back(yc + radius_eyes_H * sin(angle));
            vertices.push_back(0.0f);
            angle += angle_inc;
        }
        xc = radius / 2;
    }

    x_coord = 0.0f;
    y_coord = 0.0f;

    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices[0], GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);

        //draw ghosty
        //draw head
        glDrawArrays(GL_TRIANGLE_FAN, 0, res + 2);

        //glUseProgram(shaderProgram2);
        //draw body
        for (int i = 0; i < 4; i++) {
            glDrawArrays(GL_TRIANGLES, (res + 2) + (i * 3), 3);
        }
        float vector_size = (res + 2) + 12;
        //draw eyes
        glUseProgram(shaderProgram2);
        for (int i = 0; i < 2; i++) {
            glDrawArrays(GL_TRIANGLE_FAN, vector_size + i * (res * 2 + 2), res * 2 + 2);
        }

        int myPosLocation = glGetUniformLocation(shaderProgram, "myPos");
        glUniform3f(myPosLocation, x_coord, y_coord, 0.0f);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
        y_coord += 0.001f;
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
        y_coord -= 0.001f;
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
        x_coord -= 0.001f;
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
        x_coord += 0.001f;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}