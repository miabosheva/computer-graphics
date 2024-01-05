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
//const std::string program_name = ("FINKI LOGO");
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
//
//    // Drawing I
//        
//    float vertices2[] = {
//
//        // front and back
//
//        -0.8125f, -0.5f, -0.1f, // 1
//        -0.5625f, -0.5f, -0.1f, // 2
//        -0.5625f,  0.5f, -0.1f, // 3  
//        -0.5625f,  0.5f, -0.1f, // 4
//        -0.8125f,  0.5f, -0.1f, // 5
//        -0.8125f, -0.5f, -0.1f, // 6
//
//        -0.8125f, -0.5f, 0.1f,
//        -0.5625f, -0.5f, 0.1f,
//        -0.5625f,  0.5f, 0.1f,
//        -0.5625f,  0.5f, 0.1f,
//        -0.8125f,  0.5f, 0.1f,
//        -0.8125f, -0.5f, 0.1f,
//
//        // sides x 2
//
//        -0.8125f, -0.5f, 0.1f,
//        -0.8125f, -0.5f, -0.1f,
//        -0.8125f,  0.5f, -0.1f,
//        -0.8125f,  0.5f, -0.1f,
//        -0.8125f,  0.5f, 0.1f,
//        -0.8125f, -0.5f, 0.1f,
//
//        -0.5625f, -0.5f, 0.1f,
//        -0.5625f, -0.5f, -0.1f,
//        -0.5625f,  0.5f, -0.1f,
//        -0.5625f,  0.5f, -0.1f,
//        -0.5625f,  0.5f, 0.1f,
//        -0.5625f, -0.5f, 0.1f,
//
//        // top x 2
//
//        -0.8125f,  0.5f, 0.1f,
//        -0.8125f,  0.5f, -0.1f,
//        -0.5625f,  0.5f, -0.1f,
//        -0.5625f,  0.5f, -0.1f,
//        -0.5625f,  0.5f, 0.1f,
//        -0.8125f,  0.5f, 0.1f,
//
//        -0.8125f,  -0.5f, 0.1f,
//        -0.8125f,  -0.5f, -0.1f,
//        -0.5625f,  -0.5f, -0.1f,
//        -0.5625f,  -0.5f, -0.1f,
//        -0.5625f,  -0.5f, 0.1f,
//        -0.8125f,  -0.5f, 0.1f,
//    };
//
//
//    std::vector<float> vertices;
//
//    for (int i = 0; i < 36*3; i++) {
//        vertices.push_back(vertices2[i]);
//    }
//
//    //================================//
//    
//    //float sides;
//
//    float x_c = -0.8125f;
//    float y_c = -0.5f;
//    
//
//    //O vertices
//
//    float r_L = 0.65f;
//    float r_S = 0.4f;
//
//    x_c = 0.2f;
//    y_c = 0.0f;
//
//    float sides = 50;
//
//    float angle = 0.0f;
//    float angle_inc = 2 * M_PI / sides;
//
//
//    float z_c = 0.1f;
//
//    for (int j = 0; j < 2; j++) {
//        for (int i = 0; i < sides + 1; i++) {
//            vertices.push_back(x_c + r_S * sin(angle));
//            vertices.push_back(y_c + r_S * cos(angle));
//            vertices.push_back(z_c);
//
//            vertices.push_back(x_c + r_L * sin(angle));
//            vertices.push_back(y_c + r_L * cos(angle));
//            vertices.push_back(z_c);
//
//            angle += angle_inc;
//        }
//        z_c = -0.1f;
//    }
//
//    float radius = 0.4f;
//    for (int j = 0; j < 2; j++) {
//        for (int i = 0; i < sides + 1; i++) {
//            vertices.push_back(x_c + radius * sin(angle));
//            vertices.push_back(y_c + radius * cos(angle));
//            vertices.push_back(z_c);
//
//            z_c = -0.1f;
//
//            vertices.push_back(x_c + radius * sin(angle));
//            vertices.push_back(y_c + radius * cos(angle));
//            vertices.push_back(z_c);
//            
//            z_c = 0.1f;
//
//            angle += angle_inc;
//        }
//        radius = 0.65f;
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
//        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
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
//                glm::vec3(0.0f, 1.0f, 0.0f));
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
//        for (int i = 0; i < 1; i++) {
//
//            float r = 0.18f;
//            float g = 0.19f;
//            float b = 0.5f;
//
//            unsigned int unifromLocation = glGetUniformLocation(ourShader.ID, "ourColor");
//            glUniform4f(unifromLocation, r, g, b, 1.0f);
//            
//            glDrawArrays(GL_TRIANGLES, 0, 12);
//          
//            r = 0.1f;
//            g = 0.1f;
//            b = 0.2f;
//            glUniform4f(unifromLocation, r, g, b, 1.0f);
//
//            glDrawArrays(GL_TRIANGLES, 0, 24);
//
//            r = 0.16f;
//            g = 0.5f;
//            b = 0.82f;
//            glUniform4f(unifromLocation, r, g, b, 1.0f);
//
//            glDrawArrays(GL_TRIANGLE_STRIP, 36, sides * 2 + 2 );
//            glDrawArrays(GL_TRIANGLE_STRIP, 36 + sides * 2 + 2 , sides * 2 + 2);
//
//            r = 0.09f;
//            g = 0.4f;
//            b = 0.68f;
//            glUniform4f(unifromLocation, r, g, b, 1.0f);
//
//            glDrawArrays(GL_TRIANGLE_STRIP,  36 + ( sides * 2 + 2 ) * 2, sides * 2 + 2);
//            glDrawArrays(GL_TRIANGLE_STRIP, 36 + ( sides * 2 + 2 ) * 3, sides * 2 + 2);
//            
//        }
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
