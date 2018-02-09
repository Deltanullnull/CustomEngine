#version 400
 
layout(location = 0) in vec3 position;
layout(location = 1) in vec2 uv;

uniform mat4 mvp;
uniform mat4 mvpDepth;

out vec2 uvFrag;

out vec4 shadowCoord;


void main()
{
    //uvFrag = uv;  
	gl_Position = mvp * vec4(position, 1.0);
	
	//shadowCoord = mvpDepth * vec4(position, 1.0);
}