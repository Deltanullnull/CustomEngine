#version 400

in vec4 Vertex_Normal;
in vec2 Vertex_UV;
in vec4 Vertex_Position;


uniform sampler2D tex0;

layout(location = 0) out vec4 fragmentColor;

void main()
{

	fragmentColor = texture2D(tex0, Vertex_UV);
	
}