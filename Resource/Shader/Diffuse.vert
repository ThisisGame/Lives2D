precision lowp float;

uniform mat4 m_mvp;
attribute vec3 m_position;
attribute vec2 m_uv;
attribute vec3 m_normal;

uniform mat4 m_model;
uniform mat4 m_modelofnormal;


varying vec2 m_outUV;
varying vec3 out_normal;
varying vec3 out_fragpos;

void main()
{
	vec4 pos=vec4(m_position,1);
	gl_Position=m_mvp*pos;
	
	out_normal=mat3( m_modelofnormal) * m_normal ;
	
	m_outUV=m_uv;
	out_fragpos=vec3(m_model*vec4(m_position,1));
}
