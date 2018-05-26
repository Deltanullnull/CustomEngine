#version 400

in vec4 Vertex_Normal;
in vec3 Vertex_UV;
in vec4 Vertex_Position;


uniform samplerCube tex0;

layout(location = 0) out vec4 fragmentColor;

void main()
{

	fragmentColor = texture(tex0, Vertex_UV);
	
}