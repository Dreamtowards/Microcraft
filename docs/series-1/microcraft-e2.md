
# Microcraft E1. <small>_Window Init. OpenGL Setup._</small>

Hello everyone. I am so glad can have the qualification can engage to the 
Microcraft Development Series.

In this series, we'll gonna to trying implementing the Basic Technology 
Aspect of Minecraft.

Obviously, no one wants to cause the possible of offense, I am genuine
attitude. Minecraft Classic is kind of Decent, almost no one can get the 
height of its even 1% in some aspect for actually even no one need to say
but people knows it who really understand 1% of mc or little bit more.

However, we're really gotta go, so lets begin.

## 1. New Directory of the Projekt

It's simple, but not trivial. I'd like to create the directory by my self 
manually instead of create it by IDE.

I don't want overstated, but something, the project, needed to be tight,
not pile of crap which loosen mess, but have a well control.

```shell
$ mkdir ~/YouResponsitory/Microcraft    # or use Finder/Explorer..
```

Then just used CLion, open the empty directory.

### 1.1. Hello Word™

Check it out, whether it's really working.

```cpp
#include <iostream>

int main() {

    std::cout << "Hello Word.\n";
    return 0;
}
```

## 2. GLFW Init.

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

> Note: In OSX platform, building dependencies "-framework Cocoa -framework OpenGL -framework IOKit" are required. [[see]](https://www.glfw.org/docs/latest/build.html#build_link_osx)


## 3. GLAD Init.

GLAD is helping for us to use OpenGL properly.





> Post: https://microcraft.edwardrolinsen.com/series-1/microcraft-e1/  
> Video: https://www.youtube.com/watch?v=7sF6YGN4PTM  
> hint: the video contains literally all the details, include step by step
> improvement modifications progressively. 