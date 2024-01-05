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
//const std::string program_name = ("SPHERE");
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
//    //std::vector<float> indices;
//
//    int resolution = 50;
//    float x0, y0, z0;
//    x0 = y0 = z0 = 0.0f;
//    float radius = 1.0f;
//
//    float theta = 0.0f;
//    float phi = (-1.0f) * M_PI / 2.0f;
//
//    float thetaIncrement = 2.0f * M_PI / (resolution - 3);
//    float phiIncrement = M_PI / (resolution);
//
//
//
//    for (int i = 0; i < resolution; i++)
//    {
//        theta = 0.0f;
//        for (int j = 0; j < resolution; j++)
//        {
//            //position
//            vertices.push_back(x0 + radius * cos(phi) * cos(theta));
//            vertices.push_back(y0 + radius * cos(phi) * sin(theta));
//            vertices.push_back(z0 + radius * sin(phi));
//
//            phi += phiIncrement;
//
//            //position
//            vertices.push_back(x0 + radius * cos(phi) * cos(theta));
//            vertices.push_back(y0 + radius * cos(phi) * sin(theta));
//            vertices.push_back(z0 + radius * sin(phi));
//
//            phi -= phiIncrement;
//            theta += thetaIncrement;
//
//        }
//        phi += phiIncrement;
//    }
//
//    /////////////////////////////////////////////////////////////////////////////////
//    //// build vertices of sphere with smooth shading using parametric equation
//    //// x = r * cos(u) * cos(v)
//    //// y = r * cos(u) * sin(v)
//    //// z = r * sin(u)
//    //// where u: stack(latitude) angle (-90 <= u <= 90)
//    ////       v: sector(longitude) angle (0 <= v <= 360)
//    /////////////////////////////////////////////////////////////////////////////////
//
//    //const float PI = acos(-1);
//
//    //float radius = 1.0f;
//    //float sectorCount = 20;
//    //float stackCount = 10;
//
//    //float x, y, z, xy;                              // vertex position
//    //float nx, ny, nz, lengthInv = 1.0f / radius;    // normal
//    //float s, t;                                     // texCoord
//
//    //float sectorStep = 2 * PI / sectorCount;
//    //float stackStep = PI / stackCount;
//    //float sectorAngle, stackAngle;
//
//    //for (int i = 0; i <= stackCount; ++i)
//    //{
//    //    stackAngle = PI / 2 - i * stackStep;        // starting from pi/2 to -pi/2
//    //    xy = radius * cosf(stackAngle);             // r * cos(u)
//    //    z = radius * sinf(stackAngle);              // r * sin(u)
//
//    //    // add (sectorCount+1) vertices per stack
//    //    // the first and last vertices have same position and normal, but different tex coords
//    //    for (int j = 0; j <= sectorCount; ++j)
//    //    {
//    //        sectorAngle = j * sectorStep;           // starting from 0 to 2pi
//
//    //        // vertex position
//    //        x = xy * cosf(sectorAngle);             // r * cos(u) * cos(v)
//    //        y = xy * sinf(sectorAngle);             // r * cos(u) * sin(v)
//    //        vertices.push_back(x);
//    //        vertices.push_back(y);
//    //        vertices.push_back(z);
//    //    }
//    //}
//
//    //unsigned int k1, k2;
//    //for (int i = 0; i < stackCount; ++i)
//    //{
//    //    k1 = i * (sectorCount + 1);     // beginning of current stack
//    //    k2 = k1 + sectorCount + 1;      // beginning of next stack
//
//    //    for (int j = 0; j < sectorCount; ++j, ++k1, ++k2)
//    //    {
//    //        // 2 triangles per sector excluding 1st and last stacks
//    //        if (i != 0)
//    //        {
//    //            indices.push_back(k1);
//    //            indices.push_back(k2);
//    //            indices.push_back(k1+1);   // k1---k2---k1+1
//    //        }
//
//    //        if (i != (stackCount - 1))
//    //        {
//    //            indices.push_back(k1 + 1);
//    //            indices.push_back(k2);
//    //            indices.push_back(k2 + 1);  // k1+1---k2---k2+1
//    //        }
//
//    //    }
//    //}
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
//    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
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
//
//        float r, g, b;
//        r = g = 1.0f;
//        b = 0.5f;
//        unsigned int unifromLocation = glGetUniformLocation(ourShader.ID, "ourColor");
//        glUniform4f(unifromLocation, r, g, b, 1.0f);
//        
//        for (int i = 0; i < resolution; i++)
//        {
//            glDrawArrays(GL_TRIANGLE_STRIP, resolution * i * 2, resolution * 2);
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
