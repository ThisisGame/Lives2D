//顶点Shader
static const char g_VertexShaderNormal[]=
"attribute vec4 vPosition;\n" //顶点坐标
"attribute vec2 textureCoords;\n" //纹理坐标
"varying vec2 frag_textureCoords;\n" //纹理坐标传给片元着色器
"void main(){\n"
"frag_textureCoords=textureCoords;\n" //把代码中传过来的纹理坐标传到片元着色器中
"	gl_Position=vPosition;\n"
"}\n";



//片元着色器
static const char g_FragmentShaderNormal[]=
                        "varying vec2 frag_textureCoords;                            \n"
                        "uniform sampler2D s_texture;                        \n"
                        "void main()                                         \n"
                        "{                                                   \n"
                        "  gl_FragColor = texture2D( s_texture, frag_textureCoords );\n"
                        "}\n";
