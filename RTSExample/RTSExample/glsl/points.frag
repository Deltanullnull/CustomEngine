#version 400

in vec2 uvFrag;
in float depth;

uniform sampler2D tex;

out vec4 fragmentColor;
 
void main()
{
	//fragmentColor = vec4(1.0f);

	fragmentColor = vec4(depth, depth, depth, 1.0f);

}