#pragma once
#include<assert.h>
#include<egl\egl.h>
#include<gles2\gl2.h>

class ShaderID
{
public:
	ShaderID()
	{
		m_shaderId = -1;
	}

	int m_shaderId;
};

//封装OpenGL 的glProgram的一些信息;
class GLProgram
{
public:
	int m_programId;
	ShaderID m_vertexShader;
	ShaderID m_fragmentShader;


public:
	GLProgram()
	{
		m_programId = -1;
	}

public:
	//加载shader并且创建glProgram;
	bool createProgram(const char *vertex, const char *fragment)
	{
		bool error = false;
		do
		{
			if (vertex)
			{
				//创建Shader;
				m_vertexShader.m_shaderId = glCreateShader(GL_VERTEX_SHADER);
				//源码;
				glShaderSource(m_vertexShader.m_shaderId, 1, &vertex, 0);
				//编译;
				glCompileShader(m_vertexShader.m_shaderId);

				GLint compileStatus;
				glGetShaderiv(m_vertexShader.m_shaderId, GL_COMPILE_STATUS, &compileStatus);

				error = (compileStatus == GL_FALSE);
				if (error)
				{
					GLchar message[256];
					glGetShaderInfoLog(m_vertexShader.m_shaderId, sizeof(message), 0, message);
					assert((message && 0) != 0);
					break;
				}
			}

			if (fragment)
			{
				//创建Shader;
				m_fragmentShader.m_shaderId = glCreateShader(GL_FRAGMENT_SHADER);
				//源码;
				glShaderSource(m_fragmentShader.m_shaderId, 1, &fragment, 0);
				//编译;
				glCompileShader(m_fragmentShader.m_shaderId);

				GLint compileStatus;
				glGetShaderiv(m_fragmentShader.m_shaderId, GL_COMPILE_STATUS, &compileStatus);

				error = (compileStatus == GL_FALSE);
				if (error)
				{
					GLchar message[256];
					glGetShaderInfoLog(m_fragmentShader.m_shaderId, sizeof(message), 0, message);
					assert((message && 0) != 0);
					break;
				}
			}

			//创建gl程序;
			m_programId = glCreateProgram();

			//代码添加到program中;
			if (m_vertexShader.m_shaderId)
			{
				glAttachShader(m_programId, m_vertexShader.m_shaderId);
			}
			if (m_fragmentShader.m_shaderId)
			{
				glAttachShader(m_programId, m_fragmentShader.m_shaderId);
			}

			//链接;
			glLinkProgram(m_programId);

			GLint linkStatus;
			glGetProgramiv(m_programId, GL_LINK_STATUS, &linkStatus);

			if (linkStatus == GL_FALSE)
			{
				GLchar message[256];
				glGetProgramInfoLog(m_programId, sizeof(message), 0, message);
				assert((message && 0) != 0);
				break;
			}

			//使用program;
			//glUseProgram(m_programId);

		} while (false);
		
		if (error)
		{
			if (m_fragmentShader.m_shaderId)
			{
				glDeleteShader(m_fragmentShader.m_shaderId);
				m_fragmentShader.m_shaderId = 0;
			}

			if (m_vertexShader.m_shaderId)
			{
				glDeleteShader(m_vertexShader.m_shaderId);
				m_vertexShader.m_shaderId = 0;
			}

			if (m_programId)
			{
				glDeleteProgram(m_programId);
				m_programId = 0;
			}
		}

		return true;
	}

	virtual void begin()
	{
		glUseProgram(m_programId);
	}

	virtual void end()
	{
		glUseProgram(0);
	}
};