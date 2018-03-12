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

class ShaderPropertyValueType
{
public:
    static const char* TYPE_FLOAT;
    static const char* TYPE_INT;
    static const char* TYPE_VERTEXATTRIBPOINT;
    static const char* TYPE_TEXTURE;
};



class ShaderProperty
{
public:
	const char* mName; //ÊShaderPropertyName in vertex shader or fragment shader
	GLint mID;
	const char* mValueType;
};

class ShaderPropertyFloat:public ShaderProperty
{
public:
    ShaderPropertyFloat()
    {
        mValueType=ShaderPropertyValueType::TYPE_FLOAT;
    }
    
public:
	float mValue;
};


class ShaderPropertyInt:public ShaderProperty
{
public:
    ShaderPropertyInt()
    {
        mValueType=ShaderPropertyValueType::TYPE_INT;
    }
    
public:
    int mValue;
};


//to glVertexAttribPoint
class ShaderPropertyVertexAttribPointer:public ShaderProperty
{
public:
    ShaderPropertyVertexAttribPointer()
    {
        mValueType=ShaderPropertyValueType::TYPE_VERTEXATTRIBPOINT;
    }
    
public:
    int mSize;
    int mStride;
    void* mMemoryData;
};

class ShaderPropertyTexture:public ShaderProperty
{
public:
    ShaderPropertyTexture()
    {
        mValueType=ShaderPropertyValueType::TYPE_TEXTURE;
    }
    
public:
    const char* mTexturePath;//Texture file short path
    int mActiveTextureIndex;//GL_TEXTURE0+n,get from xml,first is 0,second is 1
    int mTextureID;
};


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
	
	bool CreateProgram(const char *vertex, const char *fragment)
	{
		bool error = false;
		do
		{
			if (vertex)
			{
				
				mVertexShader = glCreateShader(GL_VERTEX_SHADER);
				
				glShaderSource(mVertexShader, 1, &vertex, 0);
				
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
				
				mFragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
				
				glShaderSource(mFragmentShader, 1, &fragment, 0);
				
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

			
			mProgram = glCreateProgram();

			
			if (mVertexShader)
			{
				glAttachShader(mProgram, mVertexShader);
			}
			if (mFragmentShader)
			{
				glAttachShader(mProgram, mFragmentShader);
			}

			
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
