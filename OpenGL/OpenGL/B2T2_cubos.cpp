//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//
//#include <learnopengl/shader.h>
//#include <learnopengl/camera.h>
//
//#define STB_IMAGE_IMPLEMENTATION 
//#include <learnopengl/stb_image.h>
//
//#include <iostream>
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void mouse_callback(GLFWwindow* window, double xpos, double ypos);
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
//void processInput(GLFWwindow* window);
//
//// settings
//const unsigned int SCR_WIDTH = 800;
//const unsigned int SCR_HEIGHT = 600;
//
//// camera
//Camera camera(glm::vec3(0.0f, 0.0f, 5.0f));
//float lastX = SCR_WIDTH / 2.0f;
//float lastY = SCR_HEIGHT / 2.0f;
//bool firstMouse = true;
//
//// timing
//float deltaTime = 0.0f;	// time between current frame and last frame
//float lastFrame = 0.0f;
//
//
//glm::vec3 lightPos(1.0f, 4.0f, 3.0f);
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
//    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Issac de la Cadena 1500958069", NULL, NULL);
//    if (window == NULL)
//    {
//        std::cout << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//        return -1;
//    }
//    glfwMakeContextCurrent(window);
//    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//    glfwSetCursorPosCallback(window, mouse_callback);
//    glfwSetScrollCallback(window, scroll_callback);
//
//    // tell GLFW to capture our mouse
//    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
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
//    // configure global opengl state
//    // -----------------------------
//    glEnable(GL_DEPTH_TEST);
//
//    // build and compile our shader zprogram
//    // ------------------------------------
//    Shader ourShader("shaders/vertexshader_cubos.vs", "shaders/fragmentshader_cubos.fs");
//    Shader lightingShader("shaders/shader_exercise14t4_materials.vs", "shaders/shader_exercise14t4_materials.fs");
//    Shader lightCubeShader("shaders/shader_exercise14_lightcube.vs", "shaders/shader_exercise14_lightcube.fs");
//
//
//    // set up vertex data (and buffer(s)) and configure vertex attributes
//    // ------------------------------------------------------------------
//    float vertices[] = {
//        // positions          // texture coords
//        //FRENTE
//     -0.5f, -0.5f,  0.5f,  0.534f, 0.498f,
//      0.5f, -0.5f,  0.5f,  0.731f, 0.498f,
//      0.5f,  0.5f,  0.5f,  0.731f, 0.673f,
//      0.5f,  0.5f,  0.5f,  0.731f, 0.673f,
//     -0.5f,  0.5f,  0.5f,  0.534f, 0.673f,
//     -0.5f, -0.5f,  0.5f,  0.534f, 0.498f,
//     ////ABAJO
//     -0.5f, -0.5f, -0.5f,  0.534f, 0.254f,
//      0.5f, -0.5f, -0.5f,  0.731f, 0.254f,
//      0.5f, -0.5f,  0.5f,  0.731f, 0.498f,
//      0.5f, -0.5f,  0.5f,  0.731f, 0.498f,
//     -0.5f, -0.5f,  0.5f,  0.534f, 0.498f,
//     -0.5f, -0.5f, -0.5f,  0.534f, 0.254f,
//     ////ARRIBA
//     -0.5f,  0.5f, -0.5f,  0.534f, 0.673f,
//      0.5f,  0.5f, -0.5f,  0.731f, 0.673f,
//      0.5f,  0.5f,  0.5f,  0.731f, 0.922f,
//      0.5f,  0.5f,  0.5f,  0.731f, 0.922f,
//     -0.5f,  0.5f,  0.5f,  0.534f, 0.922f,
//     -0.5f,  0.5f, -0.5f,  0.534f, 0.673f,
//     ////LADOS
//     -0.5f, -0.5f, -0.5f,  0.143f, 0.498f,
//      0.5f, -0.5f, -0.5f,  0.339f, 0.498f,
//      0.5f,  0.5f, -0.5f,  0.339f, 0.673f,
//      0.5f,  0.5f, -0.5f,  0.339f, 0.673f,
//     -0.5f,  0.5f, -0.5f,  0.143f, 0.673f,
//     -0.5f, -0.5f, -0.5f,  0.143f, 0.498f,
//     //lado derecho   
//     -0.5f, -0.5f, -0.5f,  0.927f, 0.498f,
//     -0.5f, -0.5f,  0.5f,  0.731f, 0.498f,
//     -0.5f,  0.5f,  0.5f,  0.731f, 0.673f,
//     -0.5f,  0.5f,  0.5f,  0.731f, 0.673f,
//     -0.5f,  0.5f, -0.5f,  0.927f, 0.673f,
//     -0.5f, -0.5f, -0.5f,  0.927f, 0.498f,
//     //lado izquierdo
//      0.5f, -0.5f, -0.5f,  0.339f, 0.498f,
//      0.5f, -0.5f,  0.5f,  0.534f, 0.498f,
//      0.5f,  0.5f,  0.5f,  0.534f, 0.673f,
//      0.5f,  0.5f,  0.5f,  0.534f, 0.673f,
//      0.5f,  0.5f, -0.5f,  0.339f, 0.673f,
//      0.5f, -0.5f, -0.5f,  0.339f, 0.498f,
//    };
//
//    // world space positions of our cubes
//    glm::vec3 cubePositions1[] = {
//        glm::vec3(0.0f,  0.0f,  0.0f),
//        glm::vec3(1.5f,  0.0f,  1.5f),
//        
//    };
//
//    glm::vec3 cubePositions2[] = {
//        glm::vec3(1.5f,  1.5f, -1.5f),
//        glm::vec3(-1.5f, 1.5f, 1.5f),
//    };
//
//    glm::vec3 cubePositions3[] = {
//        glm::vec3(-1.5f, 0.0f, -1.5f),
//        glm::vec3(-0.5f, -1.5f, -1.5f),
//    };
//    
//    glm::vec3 cubePositions4[] = {
//        glm::vec3(0.5f, 2.0f, 0.5f),
//        glm::vec3(1.5f, -2.5f, 1.5f),
//    };
//    unsigned int VBO1, VAO1;
//    glGenVertexArrays(1, &VAO1);
//    glGenBuffers(1, &VBO1);
//
//    glBindVertexArray(VAO1);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO1);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//    // position attribute
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//    // texture coord attribute
//    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//    glEnableVertexAttribArray(1);
//
//    //// second, configure the light's VAO (VBO stays the same; the vertices are the same for the light object which is also a 3D cube)
//    //unsigned int lightCubeVAO;
//    //glGenVertexArrays(1, &lightCubeVAO);
//    //glBindVertexArray(lightCubeVAO);
//
//    //glBindBuffer(GL_ARRAY_BUFFER, VBO1);
//    //// note that we update the lamp's position attribute's stride to reflect the updated buffer data
//    //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//    //glEnableVertexAttribArray(0);
//
//    // Agregar VAO y VBO para la luz
//    unsigned int lightCubeVAO, lightCubeVBO;
//    glGenVertexArrays(1, &lightCubeVAO);
//    glGenBuffers(1, &lightCubeVBO);
//    glBindVertexArray(lightCubeVAO);
//    glBindBuffer(GL_ARRAY_BUFFER, lightCubeVBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//
//
//    // load and create a texture 
//    // -------------------------
//    unsigned int texture1, texture2, texture3, texture4;
//    // texture 1
//    // ---------
//    glGenTextures(1, &texture1);
//    glBindTexture(GL_TEXTURE_2D, texture1);
//    // set the texture wrapping parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    // set texture filtering parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    // load image, create texture and generate mipmaps
//    int width, height, nrChannels;
//    stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
//    unsigned char* data = stbi_load("textures/Texture1.png", &width, &height, &nrChannels, 0);    if (data)
//        if (data)
//        {
//            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
//            glGenerateMipmap(GL_TEXTURE_2D);
//        }
//        else
//        {
//            std::cout << "Failed to load texture" << std::endl;
//        }
//    stbi_image_free(data);
//    // texture 2
//    // ---------
//    glGenTextures(1, &texture2);
//    glBindTexture(GL_TEXTURE_2D, texture2);
//    // set the texture wrapping parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    // set texture filtering parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    // load image, create texture and generate mipmaps
//    data = stbi_load("textures/Lanza.png", &width, &height, &nrChannels, 0);    if (data)
//        if (data)
//        {
//            // Modifica el formato interno de la textura según el número de componentes de color
//            GLenum internalFormat = GL_RGB;  // Por defecto
//            if (nrChannels == 1)
//                internalFormat = GL_RED;
//            else if (nrChannels == 3)
//                internalFormat = GL_RGB;
//            else if (nrChannels == 4)
//                internalFormat = GL_RGBA;
//
//            // Carga la textura con el formato interno especificado
//            glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, internalFormat, GL_UNSIGNED_BYTE, data);
//            glGenerateMipmap(GL_TEXTURE_2D);
//        }
//        else
//        {
//            std::cout << "Failed to load texture" << std::endl;
//        }
//    stbi_image_free(data);
//
//    //texture 3
//    glGenTextures(1, &texture3);
//    glBindTexture(GL_TEXTURE_2D, texture3);
//    // set the texture wrapping parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    // set texture filtering parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    // load image, create texture and generate mipmaps
//    data = stbi_load("textures/Hizoka.jpg", &width, &height, &nrChannels, 0);    if (data)
//        if (data)
//        {
//            // Modifica el formato interno de la textura según el número de componentes de color
//            GLenum internalFormat = GL_RGB;  // Por defecto
//            if (nrChannels == 1)
//                internalFormat = GL_RED;
//            else if (nrChannels == 3)
//                internalFormat = GL_RGB;
//            else if (nrChannels == 4)
//                internalFormat = GL_RGBA;
//
//            // Carga la textura con el formato interno especificado
//            glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, internalFormat, GL_UNSIGNED_BYTE, data);
//            glGenerateMipmap(GL_TEXTURE_2D);
//        }
//        else
//        {
//            std::cout << "Failed to load texture" << std::endl;
//        }
//    stbi_image_free(data);
//
//    //texture 4
//    glGenTextures(1, &texture4);
//    glBindTexture(GL_TEXTURE_2D, texture4);
//    // set the texture wrapping parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    // set texture filtering parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    // load image, create texture and generate mipmaps
//    data = stbi_load("textures/patada.png", &width, &height, &nrChannels, 0);    if (data)
//        if (data)
//        {
//            // Modifica el formato interno de la textura según el número de componentes de color
//            GLenum internalFormat = GL_RGB;  // Por defecto
//            if (nrChannels == 1)
//                internalFormat = GL_RED;
//            else if (nrChannels == 3)
//                internalFormat = GL_RGB;
//            else if (nrChannels == 4)
//                internalFormat = GL_RGBA;
//
//            // Carga la textura con el formato interno especificado
//            glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, internalFormat, GL_UNSIGNED_BYTE, data);
//            glGenerateMipmap(GL_TEXTURE_2D);
//        }
//        else
//        {
//            std::cout << "Failed to load texture" << std::endl;
//        }
//    stbi_image_free(data);
//
//    // tell opengl for each sampler to which texture unit it belongs to (only has to be done once)
//    // -------------------------------------------------------------------------------------------
//    ourShader.use();
//    ourShader.setInt("texture1", 0);
//    ourShader.setInt("texture2", 1);
//    ourShader.setInt("texture3", 2);
//    ourShader.setInt("texture4", 3);
//
//    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//    // shader configuration
//    // --------------------
//    lightingShader.use();
//    lightingShader.setInt("material.diffuse", 0);
//    lightingShader.setInt("material.specular", 1);
//    lightingShader.setInt("material.emission", 2);
//
//    // render loop
//    // -----------
//    while (!glfwWindowShouldClose(window))
//    {
//        // per-frame time logic
//       // --------------------
//        float currentFrame = glfwGetTime();
//        deltaTime = currentFrame - lastFrame;
//        lastFrame = currentFrame;
//
//        // input
//        // -----
//        processInput(window);
//
//        // render
//        // ------
//        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//
//        //glClear(GL_COLOR_BUFFER_BIT);
//
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//        //lightingShader.use();
//        //lightingShader.setVec3("light.position", lightPos);
//        //lightingShader.setVec3("viewPos", camera.Position);
//
//        //// light properties
//        //lightingShader.setVec3("light.ambient", 0.2f, 0.2f, 0.2f);
//        //lightingShader.setVec3("light.diffuse", 0.5f, 0.5f, 0.5f);
//        //lightingShader.setVec3("light.specular", 1.0f, 1.0f, 1.0f);
//
//        //// material properties
//        ////lightingShader.setVec3("material.specular", 0.5f, 0.5f, 0.5f);
//        //lightingShader.setFloat("material.shininess", 64.0f);
//
//        lightCubeShader.use();
//
//        // Calcula la posición de la luz en función del tiempo
//        lightPos.x = 2.0f + sin(glfwGetTime()) * 2.0f; // Puedes ajustar la amplitud y velocidad del movimiento
//        lightPos.y = 2.0f + cos(glfwGetTime()) * 2.0f;
//
//        // Pasa la posición de la luz al shader de la luz
//        lightCubeShader.setVec3("lightColor", glm::vec3(1.0f, 1.0f, 1.0f)); // Color de la luz
//        lightCubeShader.setVec3("lightPos", lightPos);
//
//        // Renderiza la luz
//        glBindVertexArray(lightCubeVAO);
//        glm::mat4 lightModel = glm::mat4(1.0f);
//        lightModel = glm::translate(lightModel, lightPos);
//        lightModel = glm::scale(lightModel, glm::vec3(0.2f)); // Ajusta el tamaño de la luz según sea necesario
//        lightCubeShader.setMat4("model", lightModel);
//        glDrawArrays(GL_TRIANGLES, 0, 36);
//
//
//
//        // bind textures on corresponding texture units
//        glActiveTexture(GL_TEXTURE0);
//        glActiveTexture(GL_TEXTURE1);
//        //glActiveTexture()
//
//        // activate shader
//        ourShader.use();
//
//        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
//        ourShader.setMat4("projection", projection);
//
//        // camera/view transformation
//        glm::mat4 view = camera.GetViewMatrix();
//        ourShader.setMat4("view", view);
//
//        // render boxes
//        glBindVertexArray(VAO1);
//
//        for (int i = 0; i < 8; i++)
//        {
//            // Determine el índice del conjunto de datos y la textura correspondiente
//            int dataSetIndex = i / 2;
//            unsigned int currentTexture;
//
//            switch (dataSetIndex) {
//            case 0: currentTexture = texture1; break;
//            case 1: currentTexture = texture2; break;
//            case 2: currentTexture = texture3; break;
//            case 3: currentTexture = texture4; break;
//            default: currentTexture = texture1; break;
//            }
//
//            // Determina el conjunto de posiciones según el conjunto de datos
//            glm::vec3* currentCubePositions;
//            switch (dataSetIndex) {
//            case 0: currentCubePositions = cubePositions1; break;
//            case 1: currentCubePositions = cubePositions2; break;
//            case 2: currentCubePositions = cubePositions3; break;
//            case 3: currentCubePositions = cubePositions4; break;
//            default: currentCubePositions = cubePositions1; break;
//            }
//
//            // calculate the model matrix for each object and pass it to shader before drawing
//            glm::mat4 model = glm::mat4(1.0f);
//            model = glm::translate(model, currentCubePositions[i % 2]);
//
//            if (i % 2 == 0) {
//                float angle = glfwGetTime() * 25.0f;
//                model = glm::rotate(model, glm::radians(angle), glm::vec3(-1.0f, -0.3f, 0.5f));
//            }
//            else {
//                float scale = 0.5f + 0.5f * sin(glfwGetTime());
//                model = glm::scale(model, glm::vec3(scale, scale, scale));
//            }
//
//            ourShader.setMat4("model", model);
//            glBindTexture(GL_TEXTURE_2D, currentTexture);
//            glDrawArrays(GL_TRIANGLES, 0, 36);
//        }
//
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
//
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
//
//    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//        camera.ProcessKeyboard(FORWARD, deltaTime);
//    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//        camera.ProcessKeyboard(BACKWARD, deltaTime);
//    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//        camera.ProcessKeyboard(LEFT, deltaTime);
//    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//        camera.ProcessKeyboard(RIGHT, deltaTime);
//
//    //If I want to stay in ground level (xz plane)
//    //camera.Position.y = 0.0f;
//
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
//
//// glfw: whenever the mouse moves, this callback is called
//// -------------------------------------------------------
//void mouse_callback(GLFWwindow* window, double xpos, double ypos)
//{
//    if (firstMouse)
//    {
//        lastX = xpos;
//        lastY = ypos;
//        firstMouse = false;
//    }
//
//    float xoffset = xpos - lastX;
//    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top
//    lastX = xpos;
//    lastY = ypos;
//
//    camera.ProcessMouseMovement(xoffset, yoffset);
//}
//
//// glfw: whenever the mouse scroll wheel scrolls, this callback is called
//// ----------------------------------------------------------------------
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
//{
//    camera.ProcessMouseScroll(yoffset);
//}