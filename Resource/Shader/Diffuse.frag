precision lowp float;

uniform sampler2D m_texture;
uniform vec3 m_lightcolor;
uniform vec3 m_lightpos;

varying vec2 m_outUV;
varying vec3 out_normal;
varying vec3 out_fragpos;

void main()
{
	vec3 normal=normalize(out_normal);
	vec3 lightdir=normalize(m_lightpos-out_fragpos);
	float cosvalue=max( dot(normal,lightdir),0.0);
	vec3 diffuse=cosvalue * m_lightcolor;
	float ambientStrength=0.1;
	vec3 ambient=ambientStrength * m_lightcolor;
	
	vec4 colorTexture=texture2D(m_texture,m_outUV);
	vec3 colorVec3=vec3(colorTexture.x,colorTexture.y,colorTexture.z);
	
	vec3 colorResult=(ambient+diffuse) * colorVec3;

	gl_FragColor=vec4(colorResult,1.0);
}
