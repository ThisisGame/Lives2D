uniform mat4 m_mvp;
attribute vec3 m_position;

void main()
{
	vec4 pos=vec4(m_position,1);
	gl_Position=m_mvp*pos;
}
