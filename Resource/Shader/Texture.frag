uniform sampler2D m_texture;

varying lowp vec2 m_outUV;

void main()
{
    gl_FragColor=texture2D(m_texture,m_outUV);
}