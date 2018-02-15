#version 400

in vec4 Vertex_Normal;
in vec4 Vertex_Position;

in vec4 Light_Position;

layout(location = 0) out vec4 fragmentColor;

void main()
{
	vec4 Vertex_Color = vec4(0.4f,0.4f,0.4f,1.f);

	float bias = 0.005;

	float visibility = 1.0f;

	vec3 L = normalize(Light_Position.xyz - Vertex_Position.xyz);
	vec3 E = normalize(-Vertex_Position.xyz);
	vec3 R = normalize(-reflect(L, Vertex_Normal.xyz));

	vec4 ambient = vec4(0.1f, 0.1f, 0.1f, 1.0f);

	ambient = clamp(ambient, 0.0f, 1.0f);

	vec4 diffuse = vec4(1.0f, 1.0f, 1.0f, 1.0f) * max(dot(Vertex_Normal.xyz, L), 0.0f);

	diffuse = clamp(diffuse, 0.0f, 1.0f);

	float shininess = 0.0f;

	vec4 specular = vec4(0.1f, 0.1f, 0.1f, 1.0f) * pow(max(dot(R, E), 0.0f), 0.1f * shininess);
	specular = clamp(specular, 0.0f, 1.0f);


	vec3 colorGammaCorrected = Vertex_Color.xyz *(ambient.xyz + diffuse.xyz + specular.xyz);


	fragmentColor = vec4(colorGammaCorrected, 1.0f);

	fragmentColor = clamp(fragmentColor, 0.0f, 1.0f);

	fragmentColor = vec4(visibility * fragmentColor.xyz, 1.0f);
}