
#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main() {

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);  // OSX Required.

    GLFWwindow* window = glfwCreateWindow(600, 420, "Dysplay", nullptr, nullptr);
    if (!window) {
        std::cout << "Failed to init GLFW window." << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed init GLAD." << std::endl;
        glfwTerminate();
        return -1;
    }


    while (!glfwWindowShouldClose(window)) {

        glClearColor(0, 1, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT);


        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}