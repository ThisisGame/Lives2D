#include "CCImage.h"
#include "CCOGL.h"


extern unsigned int ShaderGLPrograms[SHADER_GL_PROGRAM_COUNT]; //每一个Shader生成一个GL Program

CCImage::CCImage(void)
{
	m_imageFileName="";
	m_textureId=0;
}


//设置图片路径
void CCImage::SetImageFile(const string filename)
{
	m_imageFileName=filename;
	LOGI("m_imageFileName = %s\n",m_imageFileName.c_str());
}

GLfloat g_PositionVertices[12]=
{
	0.0f,1.0f,0.0f, //Position 0
	0.0f,0.0f,0.0f, //Position 1
	1.0f,0.0f,0.0f, //Position 2
	1.0f,1.0f,0.0f //Position 3
};

GLfloat g_TexCoordVertices[8]=
{
	0.0f,1.0f, //TexCoord 0
	0.0f,0.0f, //TexCoord1
	1.0f,0.0f, //TexCoord 2
	1.0f,1.0f //TexCoord3
};


const GLushort indices[]={0,1,2,0,2,3};  //三角形绘制方式 triangle_strip

GLsizei stride1=5*sizeof(GLfloat); //间隔5  坐标顶点3  纹理顶点2

GLuint g_VertexShaderPositionHandle;//Vertex Shader中vPosition变量的Handle
GLuint g_VertexShaderTexCoordHandel; //纹理坐标
GLuint g_FragShaderTexSamplerHandel; //纹理

void CCImage::DrawImage(float x,float y,float w,float h)
{
	DrawImage(x,y,w,h,0);
}

void CCImage::DrawImage(float x,float y,float w,float h,int z)
{
	//生成Texture
	if(m_textureId==0)
	{
		m_textureId=CCTexture::CreateTextureFromPng(m_imageFileName.c_str());

		LOGI("textureId = %d \n",m_textureId);
	}

	//设置位置
	g_PositionVertices[0]=x;
	g_PositionVertices[1]=y+h;
	g_PositionVertices[2]=z;

	g_PositionVertices[3]=x;
	g_PositionVertices[4]=y;
	g_PositionVertices[5]=z;

	g_PositionVertices[6]=x+w;
	g_PositionVertices[7]=y;
	g_PositionVertices[8]=z;

	g_PositionVertices[9]=x+w;
	g_PositionVertices[10]=y+h;
	g_PositionVertices[11]=z;

	
    

	//获取VertexShader中的vPosition
	g_VertexShaderPositionHandle=glGetAttribLocation(ShaderGLPrograms[SHADER_GL_PROGRAM_NORMAL],"vPosition");
	Helper::CheckGLError("glGetAttribLocation");

	//获取纹理坐标
	g_VertexShaderTexCoordHandel=glGetAttribLocation(ShaderGLPrograms[SHADER_GL_PROGRAM_NORMAL],"textureCoords");
	Helper::CheckGLError("glGetAttribLocation");
	//LOGI("g_VertexShaderTexCoordHandel\n");

	//传递纹理
	g_FragShaderTexSamplerHandel=glGetAttribLocation(ShaderGLPrograms[SHADER_GL_PROGRAM_NORMAL],"s_texture");
	Helper::CheckGLError("glGetAttribLocation");
	//LOGI("g_FragShaderTexSamplerHandel\n");


	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//加载顶点坐标
	glVertexAttribPointer(g_VertexShaderPositionHandle,3,GL_FLOAT,GL_FALSE,3*sizeof(GLfloat),&g_PositionVertices);
	Helper::CheckGLError("glVertexAttribPointer");

	//加载纹理坐标
	glVertexAttribPointer(g_VertexShaderTexCoordHandel,2,GL_FLOAT,GL_FALSE,2*sizeof(GLfloat),&g_TexCoordVertices);

	glEnableVertexAttribArray(g_VertexShaderPositionHandle);
	glEnableVertexAttribArray(g_VertexShaderTexCoordHandel);
	Helper::CheckGLError("glEnableVertexAttribArray");

	//透明
	glEnable (GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

	glActiveTexture(GL_TEXTURE0);
	Helper::CheckGLError("glActiveTexture");
	glBindTexture(GL_TEXTURE_2D,m_textureId);
	Helper::CheckGLError("glBindTexture");

	//设置纹理 为0 ,没有用到多纹理
	glUniform1i(g_FragShaderTexSamplerHandel,0);
	Helper::CheckGLError("glUniform1i");

	glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_SHORT,indices);
	Helper::CheckGLError("glDrawElements");

}


CCImage::~CCImage(void)
{
}
