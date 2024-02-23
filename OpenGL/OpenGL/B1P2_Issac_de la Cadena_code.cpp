//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//
//#include <learnopengl/shader_s.h>
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
//int main()
//{
//    // glfw: initialize and configure
//    // ------------------------------
//    glfwInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//#ifdef __APPLE__
//    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
//#endif
//
//    // glfw window creation
//    // --------------------
//    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "1500958069 Issac de la Cadena", NULL, NULL);
//    if (window == NULL)
//    {
//        std::cout << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//        return -1;
//    }
//    glfwMakeContextCurrent(window);
//    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//    // glad: load all OpenGL function pointers
//    // ---------------------------------------
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//    {
//        std::cout << "Failed to initialize GLAD" << std::endl;
//        return -1;
//    }
//
//
//    Shader ourShader("shaders/shader_B1p2.vs", "shaders/shader_B1p2.fs"); // you can name your shader files however you like
//
    //float vertices[] = {
    //    //posiciones              colores
    //    
    //    //cintura
    //    -0.02f,  0.36f, 0.0f, 0.2f,  0.8f, 0.4f,    //0  
    //    -0.30f, -0.02f, 0.0f, 0.2f,  0.8f, 0.4f,    //1 
    //    0.30f,  0.02f, 0.0f,  0.2f,  0.8f, 0.4f,    //2 

    //    //pecho
    //    -0.14f,  0.2f, 0.0f, 1.0f,  0.8f, 0.0f,      //3 
    //    -0.52f,  0.6f, 0.0f, 1.0f,  0.8f, 0.0f,      //4  
    //    0.16f,  0.62f, 0.0f, 1.0f,  0.8f, 0.0f,     //5 
    //    //cabeza
    //    -0.10f,  0.61f, 0.0f, 1.0f,  0.4f, 0.4f,     //6  
    //    -0.40f,  0.68f, 0.0f, 1.0f,  0.4f, 0.4f,     //7 
    //    -0.34f,  0.97f, 0.0f, 1.0f,  0.4f, 0.4f,     //8 
    //    -0.04f,  0.90f, 0.0f, 1.0f,  0.4f, 0.4f,     //9 
    //    //pierna izquierda
    //    0.00f, 0.00f, 0.0f,  0.6f,  0.8f, 0.2f,       //10
    //    -0.27f,  -0.33f, 0.0f,  0.6f,  0.8f, 0.2f,   //11
    //    -0.30f, -0.02f, 0.0f, 0.6f,  0.8f, 0.2f,     //12
    //    //pierna derecha
    //    0.50f,  -0.26f, 0.0f, 0.4f,  0.4f, 0.8f,     //13
    //    0.30f,  -0.28f, 0.0f, 0.4f,  0.4f, 0.8f,     //14
    //    0.05f,  0.00f, 0.0f, 0.4f,  0.4f, 0.8f,      //15
    //    0.30f,  0.02f, 0.0f, 0.4f,  0.4f, 0.8f,      //16
    //            
    //    //pie derecho
    //    0.45f,  -0.20f, 0.0f, 1.0f,  0.6f, 0.2f,     //17
    //    0.60f,  -0.20f, 0.0f, 1.0f,  0.6f, 0.2f,     //18
    //    0.60f,  -0.35f, 0.0f, 1.0f,  0.6f, 0.2f,     //19
    //    //pie izquierdo
    //    -0.27f,  -0.33f, 0.0f, 0.2f,  0.6f, 1.0f,     //20
    //    -0.30f,  -0.60f, 0.0f,  0.2f,  0.6f, 1.0f,     //21
    //    -0.57f, -0.57f, 0.0f,  0.2f,  0.6f, 1.0f,     //22
    //};
//
//    //EBO_ADD
//    unsigned int indices[] = {  // note that we start from 0!
//      
//      //cintura
//      0, 1, 2,
//
//      //pecho
//      3, 4, 5,
//
//      //cabeza
//      6, 7, 8,
//      6, 8, 9,
//
//      //pierna izquierda
//      10, 11, 12,
//
//      //pierna derecha
//      13, 14, 15,
//      13, 15, 16,
//
//      //pie derecho
//      17, 18, 19,
//
//      //pie izquierdo
//      20, 21, 22
//    };
//
//    //EBO_MODIFY
//    //unsigned int VBO, VAO;
//    unsigned int VBO, VAO, EBO;
//    //
//
//    glGenVertexArrays(1, &VAO);
//    glGenBuffers(1, &VBO);
//
//    //EBO_ADD
//    glGenBuffers(1, &EBO);
//    //
//
//    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
//    glBindVertexArray(VAO);
//
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//    //EBO_ADD
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//    //
//
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
//    glEnableVertexAttribArray(1);
//
//    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
//    glBindBuffer(GL_ARRAY_BUFFER, 0);
//
//    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
//    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
//    glBindVertexArray(0);
//
//
//    // uncomment this call to draw in wireframe polygons.
//    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//
//    // render loop
//    // -----------
//    while (!glfwWindowShouldClose(window))
//    {
//        // input
//        // -----
//        processInput(window);
//
//        // render
//        // ------
//        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT);
//
//
//        // draw our first triangle
//        ourShader.use();
//        float time = glfwGetTime();
//        ourShader.setFloat("time", time);
//        glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
//
//        //EBO_MODIFY
//        //glDrawArrays(GL_TRIANGLES, 0, 3);
//        glDrawElements(GL_TRIANGLES, 27, GL_UNSIGNED_INT, 0);
//
//        // glBindVertexArray(0); // no need to unbind it every time 
//
//        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
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
//    //EBO_ADD
//    glDeleteBuffers(1, &EBO);
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