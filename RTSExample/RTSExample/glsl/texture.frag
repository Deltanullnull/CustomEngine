#version 400

in vec2 uvFrag;

uniform sampler2D tex;

out vec4 fragmentColor;
 
void main(){
	fragmentColor = texture2D(tex, uvFrag);

	if (fragmentColor == vec4(0,0,0,1))
	{
		fragmentColor.a = 0;
	}
	else
	{
		fragmentColor.a = 1.0f;
	}
	

}