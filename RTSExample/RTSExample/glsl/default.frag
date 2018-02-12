#version 400

in vec4 shadowCoord;

uniform sampler2D tex;
uniform sampler2DShadow shadowMap;

out vec4 fragmentColor;
 
void main()
{
	
	fragmentColor = vec4(0.4f,0.4f,0.4f,1.f);


}