#version 400
 
layout(location = 0) in vec3 position;

uniform mat4 projModelViewMatrix;

void main()
{
    gl_Position = projModelViewMatrix * vec4(position, 1.0);
}