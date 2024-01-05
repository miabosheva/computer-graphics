//#include <OpenGLPrj.hpp>
//#include <GLFW/glfw3.h>
//#include <Shader.hpp>
//#include <cmath>
//#include <iostream>
//#include <string>
//#include <vector>
//#include <stb.h>
//
//const std::string program_name = ("Animated Pacman");
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void processInput(GLFWwindow* window);
//
//// settings
//const unsigned int SCR_WIDTH = 800;
//const unsigned int SCR_HEIGHT = 800;
//
//float xc, yc;
//bool open = true;
//float angleRot = 0.0f;
//
//int main() {
//    // glfw: initialize and configure
//    // ------------------------------
//    glfwInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//#ifdef __APPLE__
//    glfwWindowHint(
//        GLFW_OPENGL_FORWARD_COMPAT,
//        GL_TRUE); // uncomment this statement to fix compilation on OS X
//#endif
//
//  // glfw window creation
//  // --------------------
//    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT,
//        program_name.c_str(), nullptr, nullptr);
//    if (window == nullptr) {
//        std::cout << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//        return -1;
//    }
//    glfwMakeContextCurrent(window);
//    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//    // glad: load all OpenGL function pointers
//    // ---------------------------------------
//    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
//        std::cout << "Failed to initialize GLAD" << std::endl;
//        return -1;
//    }
//
//    // build and compile our shader program
//    // ------------------------------------
//
//    std::string shader_location("../res/shaders/");
//
//    std::string used_shaders("shader");
//
//    Shader ourShader(shader_location + used_shaders + std::string(".vert"),
//        shader_location + used_shaders + std::string(".frag"));
//
//    // set up vertex data (and buffer(s)) and configure vertex attributes
//    // ------------------------------------------------------------------
//    std::vector<float> vertices;
//
//    float const PI_OVER_4 = glm::quarter_pi<float>();
//    xc = yc = 0.0f;
//    // Starting angle is not 0, but PI/8
//    float angle = M_PI / 6.0f;
//    float r = 0.2f;
//
//    vertices.push_back(xc);
//    vertices.push_back(yc);
//    vertices.push_back(0.0f);
//
//    int sides = 50;
//
//    for (auto i = 0; i < sides + 10; ++i) {
//        vertices.push_back(xc + r * glm::cos(angle));
//        vertices.push_back(yc + r * glm::sin(angle));
//        vertices.push_back(0.0f);
//
//        angle += 2 * M_PI / sides;
//    }
//
//    unsigned int VBO, VAO;
//    glGenVertexArrays(1, &VAO);
//    glGenBuffers(1, &VBO);
//
//    glBindVertexArray(VAO);
//
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertices), &vertices[0], GL_STATIC_DRAW);
//
//
//    // position attribute
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), static_cast<void*>(nullptr));
//    glEnableVertexAttribArray(0);
//
//    // tell opengl for each sampler to which texture unit it belongs to (only has
//    // to be done once)
//    // -------------------------------------------------------------------------------------------
//    ourShader.use(); // don't forget to activate/use the shader before setting
//                     // uniforms!
//
//    // render loop
//    // -----------
//    while (!glfwWindowShouldClose(window)) {
//        // input
//        // -----
//        processInput(window);
//
//        // render
//        // ------
//        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT);
//
//        // bind textures on corresponding texture units
//
//        // create transformations
//        glm::mat4 transform = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
//        transform = glm::translate(transform, glm::vec3(xc, yc, 0.0f));
//        transform = glm::rotate(transform, angleRot, glm::vec3(0.0f, 0.0f, 1.0f));
//
//
//
//        // get matrix's uniform location and set matrix
//        ourShader.use();
//        unsigned int transformLoc = glGetUniformLocation(ourShader.ID, "transform");
//        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
//
//        // render container
//        glBindVertexArray(VAO);
//        if (open) {
//            glDrawArrays(GL_TRIANGLE_FAN, 0, sides - 7);
//        }
//        else {
//            glDrawArrays(GL_TRIANGLE_FAN, 0, sides + 7);
//        }
//
//        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved
//        // etc.)
//        // -------------------------------------------------------------------------------
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//
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
//// process all input: query GLFW whether relevant keys are pressed/released this
//// frame and react accordingly
//// ---------------------------------------------------------------------------------------------------------
//void processInput(GLFWwindow* window) {
//    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//        glfwSetWindowShouldClose(window, true);
//
//    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
//        if (xc < 1.0f && xc > -1.0f) {
//            xc += 0.001f;
//            angleRot = 0.0f;
//        }
//    }
//    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
//        if (xc < 1.0f && xc > -1.0f) {
//            xc -= 0.001f;
//            angleRot = M_PI;
//        }
//    }
//    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
//        if (yc < 1.0f && yc > -1.0f) {
//            yc += 0.001f;
//            angleRot = M_PI / 2;
//        }
//    }
//    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
//        if (yc < 1.0f && yc > -1.0f) {
//            yc -= 0.001f;
//            angleRot = 3 * M_PI / 2;
//        }
//    }
//    if (glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS) {
//        open = !open;
//    }
//}
//
//// glfw: whenever the window size changed (by OS or user resize) this callback
//// function executes
//// ---------------------------------------------------------------------------------------------
//void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
//    // make sure the viewport matches the new window dimensions; note that width
//    // and height will be significantly larger than specified on retina displays.
//    glViewport(0, 0, width, height);
//}
