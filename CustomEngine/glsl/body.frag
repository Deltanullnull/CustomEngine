#version 400

in vec2 uvFrag;
in float depth;
in vec4 shadowCoord;

uniform sampler2D tex;
uniform sampler2DShadow shadowMap;

//layout(location = 0) out vec3 fragmentColor;
out vec4 fragmentColor;
 
void main()
{
	float bias = 0.005;

	fragmentColor = texture2D(tex, uvFrag);

	float visibility =  texture( shadowMap, vec3(shadowCoord.xy/shadowCoord.w, (shadowCoord.z - bias)/shadowCoord.w) );

	if (visibility < 0.9f)
	{
		fragmentColor = vec4(0,0,0,1);
	}

	//fragmentColor.a = visibility;

}