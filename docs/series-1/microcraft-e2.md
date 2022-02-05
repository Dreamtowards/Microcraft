
# Microcraft E2. <small>_The Triangle. Plain Shader._</small>

Hello, welcome bake. today, we're gonna to Do, the Triangle.


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

the Coordinate we're written is NDC which the _Normalized Device Coordinate_.

> **Normalized Device Coordinate, NDC**  
> NDC, a coordinate system that value of x, y, z are between -1.0 and 1.0.  
> OpenGL internal vertex coordinates is NDC (the `gl_Position.xyz`), 
> and it's actually left-hand coordinates. anything out of the [-1.0, 1.0] will be discarded/clipped. see _Clip Space_.  
> <small>(tho most people are using right-hand coords in practice
> e.g. in Minecraft, but the projection matrix just transformed it into 
> left-hand (negating the z) then pass to the gl_Position.)</small>  
> 

## Vertex Buffer, VBO

VBO (or Vertex Buffer Object), a vertex-data storage space in OpenGL.

```cpp
GLuint vbo;
glGenBuffers(1, &vbo);
```

## Shader Program.


Since we are using OpenGL CoreProfile, Shaders & sth like Programmable Rendering Pipeline are required.  

> **Immediate Mode**, Legacy OpenGL (Fixed Function Pipeline)  
> 

----

Video: [VID](https://www.youtube.com/watch?v=)  
Post: [https://microcraft.edwardrolinsen.com/series-1/microcraft-e2/](https://microcraft.edwardrolinsen.com/series-1/microcraft-e2/)    
Fullcode: [Microcraft-E2-.zip]()