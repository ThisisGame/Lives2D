uniform sampler2D m_texture;
uniform sampler2D m_texture_Gray;
varying lowp vec2 m_outUV;

void main()
{
    gl_FragColor=texture2D(m_texture,m_outUV) * texture2D(m_texture_Gray,m_outUV);
}
