#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <cmath>
#include <math.h>
#include <iostream>
#include <stb.h>
#include <glm/fwd.hpp>
#include <glm/ext/vector_float4.hpp>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 800;

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"uniform vec4 ourColor;\n"
"void main()\n"
"{\n"
"   FragColor = ourColor;\n"
"}\n\0";
int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }


    // build and compile our shader program
    // ------------------------------------
    // vertex shader
    int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    // check for shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // fragment shader
    int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    // check for shader compile errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // link shaders
    int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    // check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);



    std::vector<float> vertices;
    float x_c = -0.8125f;
    float y_c = -0.5f;
    float z_c = 0.0f;

    //I vertices
    vertices.push_back(x_c);
    vertices.push_back(y_c);
    vertices.push_back(z_c);

    x_c = -0.5625f;

    vertices.push_back(x_c);
    vertices.push_back(y_c);
    vertices.push_back(z_c);

    x_c = -0.8125f;
    y_c = 0.5f;

    vertices.push_back(x_c);
    vertices.push_back(y_c);
    vertices.push_back(z_c);

    x_c = -0.5625f;

    vertices.push_back(x_c);
    vertices.push_back(y_c);
    vertices.push_back(z_c);


    //O vertices

    float r_L = 0.65f;
    float r_S = 0.4f;

    x_c = 0.2f;
    y_c = 0.0f;

    float sides = 50;

    float angle = 0.0f;
    float angle_inc = 2 * M_PI / sides;


    for (int i = 0; i < sides + 1; i++) {
        vertices.push_back(x_c + r_S * sin(angle));
        vertices.push_back(y_c + r_S * cos(angle));
        vertices.push_back(z_c);

        vertices.push_back(x_c + r_L * sin(angle));
        vertices.push_back(y_c + r_L * cos(angle));
        vertices.push_back(z_c);

        angle += angle_inc;
    }

    //float angle_inc_border = 0.1f;
    //float angle_inc_border_L = 0.05f;
    //float angle_inc = 2 * M_PI / res - angle_inc_border_L;
    //float angle_inc_circle = angle_inc / sides;

    //for (int i = 0; i < res; i++) {
    //    //first vertice
    //    vertices.push_back(radius_S* cos(angle_S));
    //    vertices.push_back(radius_S* sin(angle_S));
    //    vertices.push_back(0.0f);
    //    angle_S += angle_inc;

    //    for (int j = 0; j < sides; j++) {
    //        vertices.push_back(radius_L * cos(angle_L));
    //        vertices.push_back(radius_L * sin(angle_L));
    //        vertices.push_back(0.0f);
    //        angle_L += angle_inc_circle;

    //        vertices.push_back(radius_L * cos(angle_L));
    //        vertices.push_back(radius_L * sin(angle_L));
    //        vertices.push_back(0.0f);
    //    }

    //    angle_L += angle_inc_border_L;
    //    angle_S += angle_inc_border;
    //}


    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices[0], GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0);


    // uncomment this call to draw in wireframe polygons.
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // draw our first triangle
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized

        float r = 0.18f;
        float g = 0.19f;
        float b = 0.5f;

        int unifromLocation = glGetUniformLocation(shaderProgram, "ourColor");
        glUniform4f(unifromLocation, r, g, b, 1.0f);

        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

        r = 0.16f;
        g = 0.5f;
        b = 0.82f;
        glUniform4f(unifromLocation, r, g, b, 1.0f);

        glDrawArrays(GL_TRIANGLE_STRIP, 4, sides * 2 + 2);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}
