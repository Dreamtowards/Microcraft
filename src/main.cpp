
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

    float vts[] = {
             .5, -.5, 0,
            -.5, -.5, 0,
              0,  .5, 0
    };

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    GLuint vboVerts;
    glGenBuffers(1, &vboVerts);
    glBindBuffer(GL_ARRAY_BUFFER, vboVerts);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vts), vts, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(0);


    const char* svsh =
            "#version 330 core\n"
            "layout (location = 0) in vec3 in_pos;"
            "void main() {"
                "gl_Position = vec4(in_pos.xyz, 1.0);"
            "}";
    GLuint vsh = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vsh, 1, &svsh, nullptr);
    glCompileShader(vsh);

    int succ;
    glGetShaderiv(vsh, GL_COMPILE_STATUS, &succ);
    if (!succ) {
        char infolog[512];
        glGetShaderInfoLog(vsh, 512, nullptr, infolog);
        std::cout << "Failed to compile shader. / VERTEX_SHADER:\n" << infolog << std::endl;
    }

    const char* sfsh =
            "#version 330 core\n"
            "out vec4 FragColor;"
            "void main() {"
                "FragColor = vec4(0.8);"
            "}";
    GLuint fsh = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fsh, 1, &sfsh, nullptr);
    glCompileShader(fsh);

    glGetShaderiv(fsh, GL_COMPILE_STATUS, &succ);
    if (!succ) {
        char infolog[512];
        glGetShaderInfoLog(fsh, 512, nullptr, infolog);
        std::cout << "Failed to compile shader. / FRAGMENT_SHADER:\n" << infolog << std::endl;
    }

    GLuint program = glCreateProgram();
    glAttachShader(program, vsh);
    glAttachShader(program, fsh);
    glLinkProgram(program);

    glGetProgramiv(program, GL_LINK_STATUS, &succ);
    if (!succ) {
        char infolog[512];
        glGetProgramInfoLog(program, 512, nullptr, infolog);
        std::cout << "Failed to link shader program:\n" << infolog << std::endl;
    }

    glDeleteShader(vsh);
    glDeleteShader(fsh);


    while (!glfwWindowShouldClose(window)) {

        glClearColor(0, 1, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(program);
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}