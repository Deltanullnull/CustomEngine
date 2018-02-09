#version 400
 
layout(location = 0) in vec3 position;
layout(location = 1) in vec2 uv;

uniform mat4 projModelViewMatrix;

out vec2 uvFrag;
out float depth;


void main()
{
    uvFrag = uv;  
	
	gl_Position = projModelViewMatrix * vec4(position, 1.0);

	depth = position.z;
}