#version 400

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 uv;
layout(location = 2) in vec3 normal;
layout(location = 3) in ivec4 boneIds;
layout(location = 4) in vec4 weights;

uniform mat4 mvp;
uniform mat4 model;
uniform mat4 view;
uniform mat4 modelView;
uniform mat4 mvpDepth;

const int MAX_BONES = 100;

uniform vec3 lightPosition;
uniform mat4 bones[MAX_BONES];

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
	mat4 boneTransformation = bones[boneIds[0]] * weights[0];
	boneTransformation += bones[boneIds[1]] * weights[1];
	boneTransformation += bones[boneIds[2]] * weights[2];
	boneTransformation += bones[boneIds[3]] * weights[3];

	// Transform the vertex into eye space.

	Vertex_Position = modelView * boneTransformation * vec4(position, 1.f);

	// Transform the normal's orientation into eye space.
	Vertex_Normal = normalize(modelView * boneTransformation * vec4(normal, 0.0f));

	gl_Position = mvp * boneTransformation *vec4(position, 1.0);

	Light_Position = view * boneTransformation * vec4(lightPosition, 1.0f);

	Vertex_UV = uv;

}