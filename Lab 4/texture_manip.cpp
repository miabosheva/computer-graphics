//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//
//#include <iostream>
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void processInput(GLFWwindow* window);
//
//// settings
//const unsigned int SCR_WIDTH = 800;
//const unsigned int SCR_HEIGHT = 800;
//
//
//
//static const char* vertexShaderSource = "#version 330 core\n"
//"layout (location = 0) in vec3 aPos;\n"
//
//"out vec2 TexCoord;\n"
//
//"void main()\n"
//"{\n"
//"gl_Position = vec4(aPos, 1.0);\n"
//"gl_Position = sign(gl_Position);\n"
//
//"TexCoord = (vec2(gl_Position.x, gl_Position.y)+ vec2(1.0)) / vec2(2.0);\n"
//"}\0";
//
//
//static const char* fragmentShaderSource =
//"#version 330 core\n"
//"out vec4 FragColor;\n"
//"in vec2 TexCoord;\n"
//
//"uniform int rowNum;\n"
//"uniform int colNum;\n"
//
//"float checker(vec2 uv)\n"
//"{\n"
//"float cx = floor(colNum * uv.x);\n"
//"float cy = floor(rowNum * uv.y);\n"
//"float result = mod(cx + cy, 2.0);\n"
//"return sign(result);\n"
//"}\n"
//"void main()\n"
//"{\n"
//"   vec2 uv = TexCoord.xy;\n"
//"float c = mix(1.0, 0.0, checker(uv));\n"
//"FragColor = vec4(c, c, c, 1.0);  \n"
//"}\n\0";
//
//int row = 4;
//int col = 4;
//
//int main()
//{
//    glfwInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//#ifdef __APPLE__
//    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
//#endif
//
//    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", nullptr, nullptr);
//    if (window == nullptr)
//    {
//        std::cout << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//        return -1;
//    }
//    glfwMakeContextCurrent(window);
//    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//    if (!gladLoadGLLoader(GLADloadproc(glfwGetProcAddress)))
//    {
//        std::cout << "Failed to initialize GLAD" << std::endl;
//        return -1;
//    }
//
//
//    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
//    glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
//    glCompileShader(vertexShader);
//
//    int success;
//    char infoLog[512];
//    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//    if (!success)
//    {
//        glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
//        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//    }
//    // fragment shader
//    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
//    glCompileShader(fragmentShader);
//    // check for shader compile errors
//    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
//    if (!success)
//    {
//        glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
//        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
//    }
//    // link shaders
//    GLuint shaderProgram = glCreateProgram();
//    glAttachShader(shaderProgram, vertexShader);
//    glAttachShader(shaderProgram, fragmentShader);
//    glLinkProgram(shaderProgram);
//    // check for linking errors
//    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//    if (!success) {
//        glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
//        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
//    }
//    glDeleteShader(vertexShader);
//    glDeleteShader(fragmentShader);
//
//    float vertices[] = {
//        -0.5f, -0.5f, 0.0f, // lower left
//        0.5f, -0.5f, 0.0f, // lower right
//        -0.5f, 0.5f, 0.0f, // top left
//
//        -0.5f, 0.5f, 0.0f, // top left
//        0.5f, -0.5f, 0.0f, // lower right
//        0.5f,  0.5f, 0.0f  // top right
//    };
//
//    unsigned int VBO, VAO;
//    glGenVertexArrays(1, &VAO);
//    glGenBuffers(1, &VBO);
//    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
//    glBindVertexArray(VAO);
//
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
//    glEnableVertexAttribArray(0);
//
//
//    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's
//    // bound vertex buffer object so afterwards we can safely unbind
//    glBindBuffer(GL_ARRAY_BUFFER, 0);
//
//    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO,
//    // but this rarely happens. Modifying other VAOs requires a call to glBindVertexArray anyways
//    // so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
//    glBindVertexArray(VAO);
//
//
//    // uncomment this call to draw in wireframe polygons.
//    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//
//    // render loop
//    // -----------
//
//
//
//    while (!glfwWindowShouldClose(window))
//    {
//        // input
//        // -----
//        processInput(window);
//
//        // render
//        // ------
//        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT);
//
//
//        int vertexColorLocation = glGetUniformLocation(shaderProgram, "rowNum");
//        glUseProgram(shaderProgram);
//        glUniform1i(vertexColorLocation, row);
//
//
//        int vertexColorLocation1 = glGetUniformLocation(shaderProgram, "colNum");
//        glUseProgram(shaderProgram);
//        glUniform1i(vertexColorLocation1, col);
//
//        // seeing as we only have a single VAO there's no need to bind it every time,
//        // but we'll do so to keep things a bit more organized
//        //lBindVertexArray(VAO);
//        glDrawArrays(GL_TRIANGLES, 0, 6);
//        // glBindVertexArray(0); // no need to unbind it every time
//
//        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
//        // -------------------------------------------------------------------------------
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//    glBindVertexArray(0);
//    // optional: de-allocate all resources once they've outlived their purpose:
//    // ------------------------------------------------------------------------
//    glDeleteVertexArrays(1, &VAO);
//    glDeleteBuffers(1, &VBO);
//
//    // glfw: terminate, clearing all previously allocated GLFW resources.
//    // ------------------------------------------------------------------
//    glfwTerminate();
//    return 0;
//}
//
//// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
//// ---------------------------------------------------------------------------------------------------------
//void processInput(GLFWwindow* window)
//{
//    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//        glfwSetWindowShouldClose(window, true);
//    if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) {
//        if (row > 0 && row < 50) row++;
//        else row = 2;
//    }
//    if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS) {
//        if (col > 0 && col < 50) col++;
//        else col = 2;
//    }
//}
//
//// glfw: whenever the window size changed (by OS or user resize) this callback function executes
//// ---------------------------------------------------------------------------------------------
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//    // make sure the viewport matches the new window dimensions; note that width and
//    // height will be significantly larger than specified on retina displays.
//    glViewport(0, 0, width, height);
//}