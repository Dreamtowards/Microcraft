
# Microcraft E2. <small>_The Triangle. Plain Shader._</small>

Hello, welcome bake. today, we're gonna to Do, the Triangle.

Since we are using OpenGL CoreProfile, Shaders & sth like Programmable Rendering Pipeline are required.
and vertex data are required to be stored into video devices in batches.

> **Immediate Mode**, Legacy OpenGL (Fixed Function Pipeline)  
> In Immediate mode (legacy opengl), rendering pipeline always is fixed functionality, 
> and vertex data always passing from RAM to GPU frame by frame. which might leaks of flexibility & efficiency.
> [[1]](https://www.khronos.org/opengl/wiki/Legacy_OpenGL)
> [[2]](https://www.khronos.org/opengl/wiki/Fixed_Function_Pipeline)
> [[3]](https://www.khronos.org/opengl/wiki/Tessellation)

---

## Prepare the Vertex Data

Let's start by getting the vertices of the triangle.
```
float vts[] = {
    -0.5, -0.5, 0,  // left-down
     0.5, -0.5, 0,  // right-down
     0,    0.5, 0   // middle-up
};
// the 3rd z component might unnecessary for today's 2d exposure, 
// but since we are mainly for 3d, just keep it.
```

the vertices are NDC Coordinate.

> **Normalized Device Coordinate, NDC**  
> NDC, a coordinate system that value of x, y, z are between -1.0 and 1.0.  
> OpenGL internal vertex coordinate system is NDC (the `gl_Position.xyz`), 
> and it's actually left-hand coordinates. anything out of the [-1.0, 1.0] will be discarded/clipped. see _Clip Space_.
> <small>(lot people using right-hand coords in practice (e.g. Minecraft), but always the projection matrix just transformed it into 
> left-hand (negating the z).)</small>

### Vertex Buffer Object, VBO

A Vertex Buffer Object (VBO) is an OpenGL feature that provides methods
for uploading vertex data (e.g. positions, normals, texcoords) to the 
video device for non-immediate-mode rendering. 
<cite>-- Wikipedia VBO.</cite> [[1]](https://en.wikipedia.org/wiki/Vertex_buffer_object)

Let's just put our triangle vertices into a VBO
```cpp
GLuint vbo;
glGenBuffers(1, &vbo);

glBindBuffer(GL_ARRAY_BUFFER, vbo);
glBufferData(GL_ARRAY_BUFFER, sizeof(vts), vts, GL_STATIC_DRAW);  // GL_STATIC_DRAW: store to less-modifies storage area.
```

### Vertex Array Object, VAO
A Vertex Array Object (VAO) represents a 'model' (can be considered as), it stores 'reconfigurations' of a 'model': 
a vertex-data layouts (e.g. positions, normals.. the raw data, VBO(s) and layout info e.g. data type, vertex size.. the glVertexAttribPointer), and a few other states (glEnableVertexAttribArray ..).

it helps us to switch between rendering models conveniently (just one 'glBindVertexArray'), instead of rebinding/reconfigure batch of VBOs/layouts.

```cpp
// Create VAO
GLuint vao;             
glGenVertexArrays(1, &vao);  

// Bind VAO, Configure it.
glBindVertexArray(vao); 

glBindBuffer(vbo);
glVertexAttribPointer(0,  // layout index (layout-0 there)
                      3,  // vertex size (vec3 there)
                      GL_FLOAT, GL_FALSE, 0, 0);
glEnableVertexAttribArray(0);  // enable layout-0
```

Now, our data are already set up, let's see how we do the Rendering.


## Shaders

Shaders (generally) are small programs that run on thousand of small processing cores of 
GPU in parallel, for each step of Graphics Pipeline.

There, shaders are written in GLSL (OpenGL Shading Language).

### Vertex Shader

```cpp
#version 330 core
layout(location = 0) in vec3 in_pos;

void main() {
    
    gl_Position = vec4(in_pos, 1.0);
}
```

shader is done, we have to load it up. 
```cpp
const char* svsh = ..the shader source..;

// Create Shader & Load
GLuint vsh = glCreateShader(GL_VERTEX_SHADER);
glShaderSource(vsh, 1, &svsh, nullptr);
glCompileShader(vsh);

// optical validation.
int succ;
glGetShaderiv(vsh, GL_COMPILE_STATUS, &succ);
if (!succ) {
    char infolog[512];
    glGetShaderInfoLog(vsh, 512, nullptr, infolog);
    std::cout << "Failed to compile vertex shader:\n" << infolog << std::endl;
}
```

### Fragment Shader

```cpp
#version 330 core
out vec4 FragColor;

void main() {
    FragColor = vec4(0.8);
}
```
load up is similar, just with `glCreateShader(GL_FRAGMENT_SHADER)` of creating.

### Link Program
we have to link these shaders, to a whole program.
```cpp
// Create Program, Attach Shaders, Link Program.
GLuint program = glCreateProgram();
glAttachShader(program, vsh);
glAttachShader(program, fsh);
glLinkProgram(program);  // link.

// optical validation
glGetProgramiv(sprogram, GL_LINK_STATUS, &succ);  
if (!succ) {
    char infolog[512];
    glGetProgramInfoLog(sprogram, 512, nullptr, infolog);
    std::cout << "Failed to link shader program:\n" << infolog << std::endl;
}

glDeleteShader(vsh);  // since the program is already linked, shaders can be delete.
glDeleteShader(fsh);
```

## The Triangle
```cpp
// in mainloop:
// ..glClear()

glUseProgram(program);
glBindVertexArray(vao);
glDrawArrays(GL_TRIANGLES, 0, 3);

// ..swapBuffers();
```


for detailed explanation, great article
[LearnOpenGL - HelloTriangle](https://learnopengl.com/Getting-started/Hello-Triangle)
by JoeyDeVriez is available.
----

Video: [VID](https://www.youtube.com/watch?v=)  
Post: [https://microcraft.edwardrolinsen.com/series-1/microcraft-e2/](https://microcraft.edwardrolinsen.com/series-1/microcraft-e2/)    
Fullcode: [Microcraft-E2-220205.zip](https://github.com/Dreamtowards/Microcraft/blob/main/archives/Microcraft-E2-220205.zip)