
# Microcraft E1. <small>_Init Window. OpenGL Setup._</small>

Hello everyone. I am so glad can have the qualification can engage to the 
Microcraft Development Series.

In this series, we'll gonna to trying implementing the Basic Technology 
Aspect of Minecraft.

Obviously, no one wants to cause the possible of offense, I am genuine
attitude. Minecraft Classic is kind of Decent, almost no one can get the 
height of its even 1% in some aspect for actually even no one need to say
but people knows it who really understand 1% of mc or little bit more.

However, we're really gotta go, so lets begin.

## init Project.

It's simple, but not trivial. I'd like to create the directory by my self 
manually instead of create it by IDE.  
for something, needed to be tight, prevents lost control, jus keep it, as we can.

```shell
$ mkdir ~/YouResponsitory/Microcraft    # or use Finder/Explorer..
```

then just used CLion, open the empty directory.

### Hello Word™

Check it out, whether it's really working.

```cpp
#include <iostream>

int main() {

    std::cout << "Hello Word.\n";
    return 0;
}
```
```shell
$ g++ main.cpp -o test && ./test
```

## GLFW <small>library initialization. window init.</small>

It's time to setup the Window etc. 

GLFW is a crossing-platform framework that Handling Common OS Interface, such as
Window, Mouse, Keyboard, Joystick etc.. and, give programmers little initiative
power e.g. the main loop is controlled by us instead of as a callback (in e.g. glut).
_(GLFW site: www.glfw.org)_

Get the site, download lib, setup includes, the precompiled binary. after all, the 
example code are provided by the 
[glfw docs example](https://www.glfw.org/documentation.html#example-code), 
[learnopengl](https://learnopengl.com/Getting-started/Hello-Window).

```cpp
#include <iostream>
#include <GLFW/glfw3.h>

int main() {

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION, MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);  // OSX Required.
    
    GLFWwindow* window = glfwCreateWindow(600, 420, "Dysplay", nullptr, nullptr);
    if (!window) {
        std::cout << "Failed to init Window." << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    
    
    while (!glfwWindowShouldClose(window)) {
    
        
        glfwPollEvents();
        glfwSwapBuffers(window);
    }
    
    glfwTerminate();
    return 0;
}
```
```shell
$ gcc src/main.cpp lib/libglfw3.a lib/glad.c -o test -Iinclude   # OSX required also: -framework Cocoa -framework OpenGL -framework IOKit
$ ./test
```
> Note: In OSX platform, building dependencies "-framework Cocoa -framework OpenGL -framework IOKit" are required. [[see]](https://www.glfw.org/docs/latest/build.html#build_link_osx)


## GLAD <small>linker initialization. GL functions loadup.</small>

GLAD is helping for us to use OpenGL properly. it links OpenGL functions to real implementations. 
_(GLAD site: https://glad.dav1d.de)_

Get the site, generate/download for OpenGL CoreProfile 3.3 & language C/Cpp, setup the headers, sources.  
after all, load it in initialize phase.

```cpp
#include <glad/glad.h>
#include <GLFW/glfw3.h>

...glfw init

if (!gladLoadGlLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to init GLAD." << std::endl;   
}

while (..) {  // the mainloop.

    glClearColor(0, 1, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    ...
}
...
```

now we can see GL functions working properly.





---

Video: [VID](https://www.youtube.com/watch?v=7sF6YGN4PTM)  
Post: [https://microcraft.edwardrolinsen.com/series-1/microcraft-e1/](https://microcraft.edwardrolinsen.com/series-1/microcraft-e1/)  
Fullcode: [Microcraft-E1-220111.zip](https://github.com/Dreamtowards/Microcraft/blob/main/archives/Microcraft-E1-220111.zip)  

<!--
<style>
h1,h2,h3,h4 { font-weight: bold; }
</style> 
-->