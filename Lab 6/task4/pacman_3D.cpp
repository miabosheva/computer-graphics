//#include <OpenGLPrj.hpp>
//
//#include <GLFW/glfw3.h>
//
//#include <Shader.hpp>
//#include <cmath>
//
//#include <iostream>
//#include <string>
//#include <vector>
//#include <stb.h>
//
//const std::string program_name = ("PACMAN");
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void processInput(GLFWwindow* window);
//
//// settings
//const unsigned int SCR_WIDTH = 800;
//const unsigned int SCR_HEIGHT = 800;
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
//    //Drawing sphere
//    
//    
//    
//    // clear memory of prev arrays
//    std::vector<float> vertices;
//    std::vector<float> vertices2;
//    //std::vector<float> indices;
//
//    int latitude = 50;
//    int longitude = 50;
//    float x0, y0, z0;
//    x0 = y0 = z0 = 0.0f;
//    float radius = 0.5f;
//
//    float theta = 0.0f;
//    float phi = (-1.0f) * M_PI / 2.0f;
//
//    float thetaIncrement = 2.0f * M_PI / (latitude - 3);
//    float phiIncrement = M_PI / (longitude);
//
//
//
//    for (int i = 0; i < longitude; i++)
//    {
//        theta = 0.0f;
//        for (int j = 0; j < latitude - 10; j++)
//        {
//
//                vertices.push_back(x0 + radius * cos(phi) * cos(theta));
//                vertices.push_back(y0 + radius * cos(phi) * sin(theta));
//                vertices.push_back(z0 + radius * sin(phi));
//
//                phi += phiIncrement;
//
//                vertices.push_back(x0 + radius * cos(phi) * cos(theta));
//                vertices.push_back(y0 + radius * cos(phi) * sin(theta));
//                vertices.push_back(z0 + radius * sin(phi));
//
//                phi -= phiIncrement;
//                theta += thetaIncrement;
//
//        }
//        theta += thetaIncrement * 10;
//        phi += phiIncrement;
//    }
//    //=====================================================================//
//    //mouth section
//
//    phi = (-1.0f) * M_PI / 2.0f;
//    theta -= thetaIncrement * 3;
//    for (int i = 0; i < 2; i++)
//    {
//        phi = (-1.0f) * M_PI / 2.0f;
//        
//        vertices.push_back(0.0);
//        vertices.push_back(0.0);
//        vertices.push_back(0.0);
//
//        for (int j = 0; j < latitude; j++)
//        {   
//                vertices.push_back(x0 + radius * cos(phi) * cos(theta));
//                vertices.push_back(y0 + radius * cos(phi) * sin(theta));
//                vertices.push_back(z0 + radius * sin(phi));
//
//                phi += phiIncrement;
//
//                vertices.push_back(x0 + radius * cos(phi) * cos(theta));
//                vertices.push_back(y0 + radius * cos(phi) * sin(theta));
//                vertices.push_back(z0 + radius * sin(phi));
//
//                phi += phiIncrement;
//            
//        }
//
//        theta -= thetaIncrement * 8;
//    }
//
//
//    unsigned int VBO, VAO;
//    glGenVertexArrays(1, &VAO);
//    glGenBuffers(1, &VBO);
//
//    glBindVertexArray(VAO);
//
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices[0], GL_STATIC_DRAW);
//
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//
//    ourShader.use(); // don't forget to activate/use the shader before setting
//                     // uniforms!
//
//    glEnable(GL_DEPTH_TEST);
//
//    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//
//    // render loop
//    // -----------
//    while (!glfwWindowShouldClose(window)) {
//        processInput(window);
//
//        // render
//        // ------
//        glClearColor(1.0f, 0.5f, 1.0f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//        // activate shader
//        ourShader.use();
//
//        // create transformations
//        glm::mat4 model = glm::mat4(1.0f);
//        glm::mat4 view = glm::mat4(1.0f);
//        glm::mat4 projection = glm::mat4(1.0f);
//        model = model =
//            glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f),
//                glm::vec3(0.5f, 1.0f, 0.0f));
//        view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
//        projection =
//            glm::perspective(glm::radians(45.0f),
//                (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
//        // retrieve the matrix uniform locations
//        unsigned int modelLoc = glGetUniformLocation(ourShader.ID, "model");
//        unsigned int viewLoc = glGetUniformLocation(ourShader.ID, "view");
//        // pass them to the shaders (3 different ways)
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);
//        // note: currently we set the projection matrix each frame, but since the
//        // projection matrix rarely changes it's often best practice to set it
//        // outside the main loop only once.
//        ourShader.setMat4("projection", projection);
//
//        // render container
//        glBindVertexArray(VAO);
//
//        float r, g, b;
//        r = g = 1.0f;
//        b = 0.5f;
//        unsigned int unifromLocation = glGetUniformLocation(ourShader.ID, "ourColor");
//        glUniform4f(unifromLocation, r, g, b, 1.0f);
//        
//        for (int i = 0; i < longitude; i++)
//        {
//            glDrawArrays(GL_TRIANGLE_STRIP, (latitude - 10) * 2 * i , (latitude - 10) * 2 );
//        }
//
//        r = g = 0.7f;
//        b = 0.2f;
//        glUniform4f(unifromLocation, r, g, b, 1.0f);
//        for (int i = 0; i < 2; i++) {
//            glDrawArrays(GL_TRIANGLE_FAN, ((latitude - 10) * 2 * longitude) + (longitude * 2 + 2) * i , longitude + 2);
//        }
//
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
//
