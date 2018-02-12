#version 400
 
layout(location = 0) in vec3 position;
layout(location = 1) in vec2 uv;
layout(location = 2) in vec3 normal;

layout(location = 4) in vec4 weights0;
layout(location = 5) in vec4 weights1;
layout(location = 6) in vec4 weights2;
layout(location = 7) in vec4 weights3;
layout(location = 8) in vec4 weights4;
layout(location = 9) in vec4 weights5;
layout(location = 10) in vec4 weights6;
layout(location = 11) in vec4 weights7;

uniform mat4 mvp;
uniform mat4 mvpDepth;
uniform mat4 boneMatList[31];

out vec2 uvFrag;
out float depth;

out vec4 shadowCoord;

vec3 lbs(vec3 inputVertex)
{
	vec3 output = vec3(0,0,0);

	for (int i = 0; i < 31; i++)
	{
		mat4 boneMat = boneMatList[i];
		float weight = 0.f;

		int idx = i / 4;

		vec4 weights;

		if (idx == 0) weights = weights0;
		else if (idx == 1) weights = weights1;
		else if (idx == 2) weights = weights2;
		else if (idx == 3) weights = weights3;
		else if (idx == 4) weights = weights4;
		else if (idx == 5) weights = weights5;
		else if (idx == 6) weights = weights6;
		else if (idx == 7) weights = weights7;

		idx = i % 4;

		weight = weights[idx];
		
		output += (weight * boneMat * vec4(inputVertex, 1.0f)).xyz;

	}

	return output.xyz;

}

void main()
{
	vec3 positionDeformed = lbs(position);
	
    uvFrag = uv;  
	gl_Position = mvp * vec4(positionDeformed, 1.0);
	
	mat4 depthBiasMVP = mvpDepth;

	shadowCoord = depthBiasMVP * vec4(positionDeformed, 1.0);

	depth = gl_Position.z;
}