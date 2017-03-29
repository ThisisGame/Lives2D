attribute vec4 vPosition; //顶点坐标
attribute vec2 textureCoords; //纹理坐标
varying vec2 frag_textureCoords; //纹理坐标传给片元着色器

void main()
{
	frag_textureCoords=textureCoords; //把代码中传过来的纹理坐标传到片元着色器中
	gl_Position=vPosition;
}