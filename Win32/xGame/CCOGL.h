#pragma once

#include"Helper.h"
#include"ShaderNormal.h"
#include"CCTexture.h"
#include"ShaderTest.h"
#include"CCEngine.h"

enum SHADER_GL_PROGRAM_ID
{
	SHADER_GL_PROGRAM_NONE=-1,
	SHADER_GL_PROGRAM_NORMAL=0,
	SHADER_GL_PROGRAM_COUNT=1
};

class CCOGL
{
public:
	CCOGL(void);
	~CCOGL(void);

	//初始化
	static bool NativeInit(int argc,char* argv[],int width,int height);

	//渲染
	static void NativeRender();

	static void NativeDraw();

	static void NativeUpdate();

	static void ChangeSize(int w,int h);

	static void ProcessNormalKeys(unsigned char key,int x,int y);

	static void CreateShadersGLPrograms();

	static void CompileShader(GLuint &shaderprogram,const string &shadername);

	//加载Shader
	static GLuint CreateShaderProgram(GLenum shaderType,const char* pSource);

	//创建GL程序
	static GLuint CreateGLProgram(const char* pVertexSource,const char* pFragmentSource);

	//设置宽高
	static void SetWidthHeight(int w,int h);

	static int GetWindowWidth();

	static int GetWindowHeight();

private:
	static int m_Width;
	static int m_Height;

};

