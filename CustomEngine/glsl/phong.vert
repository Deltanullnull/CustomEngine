#version 400

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 uv;
layout(location = 2) in vec3 normal;

uniform mat4 mvp;
uniform mat4 model;
uniform mat4 view;
uniform mat4 modelView;
uniform mat4 mvpDepth;

uniform vec3 lightPosition;

out vec4 Vertex_Normal;
out vec4 Vertex_Position;
out vec4 Light_Position;
out vec2 Vertex_UV;

mat4 biasMatrix = mat4(
	0.5, 0.0, 0.0, 0.0,
	0.0, 0.5, 0.0, 0.0,
	0.0, 0.0, 0.5, 0.0,
	0.5, 0.5, 0.5, 1.0
);

void main()
{
	// Transform the vertex into eye space.

	Vertex_Position = modelView * vec4(position, 1.f);

	// Transform the normal's orientation into eye space.
	Vertex_Normal = normalize(modelView * vec4(normal, 0.0f));

	gl_Position = mvp * vec4(position, 1.0);

	Light_Position = view * vec4(lightPosition, 1.0f);

	Vertex_UV = uv;

}