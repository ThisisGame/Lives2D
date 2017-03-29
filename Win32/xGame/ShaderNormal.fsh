//Æ¬Ôª×ÅÉ«Æ÷
varying vec2 frag_textureCoords;
uniform sampler2D s_texture;

void main()
{
  gl_FragColor = texture2D( s_texture, frag_textureCoords );
}