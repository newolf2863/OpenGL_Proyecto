//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//#include <learnopengl/shader_s.h>
//
//#define STB_IMAGE_IMPLEMENTATION 
//#include <learnopengl/stb_image.h>
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
////variables
//float visibilyFactor = 0.0f;
//int i = 0;
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
//    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//#endif
//
//    // glfw window creation
//    // --------------------
//    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Issac de la Caena, 1500958069", NULL, NULL);
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
//    // build and compile our shader zprogram
//    // ------------------------------------
//    Shader ourShader("shaders/shader_B2T5.vs", "shaders/shader_B2T5.fs");
//
//    // set up vertex data (and buffer(s)) and configure vertex attributes
//    // ------------------------------------------------------------------
//    float vertices[] = {
//        //posiciones              colores                       texturas
//
//        //cintura
//        -0.02f,  0.36f, 0.0f,   0.2f,  0.8f, 0.4f,     0.49f, 0.68f,   //0  
//        -0.30f, -0.02f, 0.0f,   0.2f,  0.8f, 0.4f,     0.35f, 0.49f,   //1 
//        0.30f,  0.02f, 0.0f,    0.2f,  0.8f, 0.4f,     0.65f, 0.51f,   //2 
//        //pecho
//        -0.14f,  0.2f, 0.0f,    1.0f,  0.8f, 0.0f,     0.43f, 0.6f,   //3 
//        -0.52f,  0.6f, 0.0f,    1.0f,  0.8f, 0.0f,     0.24f, 0.8f,   //4  
//        0.16f,  0.62f, 0.0f,    1.0f,  0.8f, 0.0f,     0.58f, 0.81f,   //5 
//        //cabeza
//        -0.10f,  0.61f, 0.0f,   1.0f,  0.4f, 0.4f,     0.45f, 0.805f,   //6  
//        -0.40f,  0.68f, 0.0f,   1.0f,  0.4f, 0.4f,     0.3f, 0.84f,   //7 
//        -0.34f,  0.97f, 0.0f,   1.0f,  0.4f, 0.4f,     0.33f, 0.985f,   //8 
//        -0.04f,  0.90f, 0.0f,   1.0f,  0.4f, 0.4f,     0.48f, 0.95f,   //9 
//        //pierna izquierda
//        0.00f, 0.00f, 0.0f,     0.6f,  0.8f, 0.2f,     0.50f, 0.50f,   //10
//        -0.27f,  -0.33f, 0.0f,  0.6f,  0.8f, 0.2f,     0.365f, 0.335f,   //11
//        -0.30f, -0.02f, 0.0f,   0.6f,  0.8f, 0.2f,     0.35f, 0.49f,   //12
//        //pierna derecha
//        0.50f,  -0.26f, 0.0f,   0.4f,  0.4f, 0.8f,     0.75f, 0.37f,   //13
//        0.30f,  -0.28f, 0.0f,   0.4f,  0.4f, 0.8f,     0.65f, 0.36f,   //14
//        0.05f,  0.00f, 0.0f,    0.4f,  0.4f, 0.8f,     0.525f, 0.5f,   //15
//        0.30f,  0.02f, 0.0f,    0.4f,  0.4f, 0.8f,     0.65f, 0.51f,   //16
//        //pie derecho
//        0.45f,  -0.20f, 0.0f,   1.0f,  0.6f, 0.2f,     0.725f, 0.4f,   //17
//        0.60f,  -0.20f, 0.0f,   1.0f,  0.6f, 0.2f,     0.8f, 0.4f,   //18
//        0.60f,  -0.35f, 0.0f,   1.0f,  0.6f, 0.2f,     0.8f, 0.325f,   //19
//        //pie izquierdo
//        -0.27f,  -0.33f, 0.0f,  0.2f,  0.6f, 1.0f,     0.365f, 0.335f,   //20
//        -0.30f,  -0.60f, 0.0f,  0.2f,  0.6f, 1.0f,     0.35f, 0.2f,   //21
//        -0.57f, -0.57f, 0.0f,   0.2f,  0.6f, 1.0f,     0.215f, 0.215f,   //22
//
//    };
//
//
//
//    unsigned int indices1[] = {  // 
//        //cintura
//         0, 1, 2,
//         //pecho
//         3, 4, 5,
//         //cabeza
//         6, 7, 8,
//         6, 8, 9,
//         //pierna izquierda
//         10, 11, 12,
//         //pierna derecha
//         13, 14, 15,
//         13, 15, 16,
//         //pie derecho
//         17, 18, 19,
//        // //pie izquierdo
//         20, 21, 22
//
//    };
//
//
//
//    unsigned int VBO1, VAO1, EBO1;
//    glGenVertexArrays(1, &VAO1);
//    glGenBuffers(1, &VBO1);
//    glGenBuffers(1, &EBO1);
//
//    glBindVertexArray(VAO1);
//
//    glBindBuffer(GL_ARRAY_BUFFER, VBO1);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO1);
//    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices1), indices1, GL_STATIC_DRAW);
//
//
//    // position attribute
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//    // color attribute
//    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
//    glEnableVertexAttribArray(1);
//    // texture coord attribute
//    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
//    glEnableVertexAttribArray(2);
//
//
//    // load and create a texture 
//    // -------------------------
//    unsigned int texture1, texture2;
//    // texture 1
//    // ---------
//    glGenTextures(1, &texture1);
//    glBindTexture(GL_TEXTURE_2D, texture1);
//    // set the texture wrapping parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_CLAMP_TO_EDGE (default wrapping method)
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//
//    // set texture filtering parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    // load image, create texture and generate mipmaps
//    int width, height, nrChannels;
//    stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
//    // The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
//    unsigned char* data = stbi_load("textures/texture1.jpg", &width, &height, &nrChannels, 0);
//    if (data)
//    {
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//        glGenerateMipmap(GL_TEXTURE_2D);
//    }
//    else
//    {
//        std::cout << "Failed to load texture" << std::endl;
//    }
//    stbi_image_free(data);
//    // texture 2
//        // ---------
//    glGenTextures(1, &texture2);
//    glBindTexture(GL_TEXTURE_2D, texture2);
//    // set the texture wrapping parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_CLAMP_TO_EDGE (default wrapping method)
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//
//    // set texture filtering parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    // load image, create texture and generate mipmaps
//
//    stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
//    // The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
//    data = stbi_load("textures/texture2.jpg", &width, &height, &nrChannels, 0);
//    if (data)
//    {
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//        glGenerateMipmap(GL_TEXTURE_2D);
//    }
//    else
//    {
//        std::cout << "Failed to load texture" << std::endl;
//    }
//    stbi_image_free(data);
//
//    // tell opengl for each sampler to which texture unit it belongs to (only has to be done once)
//    // -------------------------------------------------------------------------------------------
//    ourShader.use(); // don't forget to activate/use the shader before setting uniforms!
//    // either set it manually like so:
//    glUniform1i(glGetUniformLocation(ourShader.ID, "texture1"), 0);
//    // or set it via the texture class
//    ourShader.setInt("texture2", 1);
//
//
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
//        // bind textures on corresponding texture units
//        glActiveTexture(GL_TEXTURE0);
//        glBindTexture(GL_TEXTURE_2D, texture1);
//        glActiveTexture(GL_TEXTURE1);
//        glBindTexture(GL_TEXTURE_2D, texture2);
//
//        visibilyFactor = 0.5 + (sin(i * 0.01) / 2);
//        i++;
//
//        // set the texture mix value in the shader
//        ourShader.setFloat("visible", visibilyFactor);
//
//        // render container
//        ourShader.use();
//        glBindVertexArray(VAO1);
//        glDrawElements(GL_TRIANGLES, 27, GL_UNSIGNED_INT, 0);
//
//        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
//        // -------------------------------------------------------------------------------
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//
//    // optional: de-allocate all resources once they've outlived their purpose:
//    // ------------------------------------------------------------------------
//    glDeleteVertexArrays(1, &VAO1);
//    glDeleteBuffers(1, &VBO1);
//    glDeleteBuffers(1, &EBO1);
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