#pragma once
#include<assert.h>

#if IOS
#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>
#else
#include<egl\egl.h>
#include<gles2\gl2.h>
#endif
#include"../Tools/Helper.h"	

class ShaderProperty
{
public:
	const char* mName; //属性
	GLint mID;
	const char* mValueType;
};

class ShaderPropertyFloat:public ShaderProperty
{
public:
	float mValue;
};


//封装OpenGL 的glProgram的一些信息;
class Shader
{
public:
	int mProgram;
	GLuint mVertexShader;
	GLuint mFragmentShader;


public:
	Shader()
	{
		mProgram = -1;
	}

public:
	//加载shader并且创建glProgram;
	bool CreateProgram(const char *vertex, const char *fragment)
	{
		bool error = false;
		do
		{
			if (vertex)
			{
				//创建Shader;
				mVertexShader = glCreateShader(GL_VERTEX_SHADER);
				//源码;
				glShaderSource(mVertexShader, 1, &vertex, 0);
				//编译;
				glCompileShader(mVertexShader);

				GLint compileStatus;
				glGetShaderiv(mVertexShader, GL_COMPILE_STATUS, &compileStatus);

				error = (compileStatus == GL_FALSE);
				if (error)
				{
					GLchar message[256];
					glGetShaderInfoLog(mVertexShader, sizeof(message), 0, message);

					LOGI("message %s", message);
					assert((message && 0) != 0);
					break;
				}
			}

			if (fragment)
			{
				//创建Shader;
				mFragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
				//源码;
				glShaderSource(mFragmentShader, 1, &fragment, 0);
				//编译;
				glCompileShader(mFragmentShader);

				GLint compileStatus;
				glGetShaderiv(mFragmentShader, GL_COMPILE_STATUS, &compileStatus);

				error = (compileStatus == GL_FALSE);
				if (error)
				{
					GLchar message[256];
					glGetShaderInfoLog(mFragmentShader, sizeof(message), 0, message);
					assert((message && 0) != 0);
					break;
				}
			}

			//创建gl程序;
			mProgram = glCreateProgram();

			//代码添加到program中;
			if (mVertexShader)
			{
				glAttachShader(mProgram, mVertexShader);
			}
			if (mFragmentShader)
			{
				glAttachShader(mProgram, mFragmentShader);
			}

			//链接;
			glLinkProgram(mProgram);

			GLint linkStatus;
			glGetProgramiv(mProgram, GL_LINK_STATUS, &linkStatus);

			if (linkStatus == GL_FALSE)
			{
				GLchar message[256];
				glGetProgramInfoLog(mProgram, sizeof(message), 0, message);
				assert((message && 0) != 0);
				break;
			}

			//使用program;
			//glUseProgram(mProgram);

		} while (false);
		
		if (error)
		{
			if (mFragmentShader)
			{
				glDeleteShader(mFragmentShader);
				mFragmentShader = 0;
			}

			if (mVertexShader)
			{
				glDeleteShader(mVertexShader);
				mVertexShader = 0;
			}

			if (mProgram)
			{
				glDeleteProgram(mProgram);
				mProgram = 0;
			}
		}

		return true;
	}

	virtual void begin()
	{
		glUseProgram(mProgram);
	}

	virtual void end()
	{
		glUseProgram(0);
	}
};
