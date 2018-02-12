#version 400

out vec4 fragmentColor;

uniform int type;
 
void main()
{
	fragmentColor = vec4(0.2f,0.2f,0.2f,1.0f);

	/*if (type == 0)
		fragmentColor = vec4(1.0, 0.0,0.0,1.0);
	else
		fragmentColor = vec4(0.0, 1.0,0.0,1.0);*/
}