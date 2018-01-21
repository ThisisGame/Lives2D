#pragma once
#include"GLProgram_Texture.h"

class GLProgram_Texture_ReceiveLightEffect :public GLProgram_Texture
{
public:

	//传入shader中的值;
	GLuint m_position_Light;
	GLuint m_color_Light;

	GLuint m_model_matrix;

public:
	GLProgram_Texture_ReceiveLightEffect()
	{
		m_position_Light = -1;
		m_color_Light = -1;
		m_model_matrix = -1;
	}

	~GLProgram_Texture_ReceiveLightEffect()
	{}

	GLuint getPositionLight() const
	{
		return m_position_Light;
	}

	GLuint getColorLight() const
	{
		return m_color_Light;
	}

	//attribute:只能在Vertexshader中使用;
	//Unifrom:在Vertex和Fragment中共享使用,且不能被修改;
	//Varying:从Vertex传递数据到Fragment中使用,经过插值的;
	virtual bool Initialize()
	{
		const char* vertexShader =
		{
			"precision lowp float;"

			"uniform mat4 m_mvp;"
			"attribute vec3 m_position;"
			"attribute vec4 m_color;"
			"attribute vec2 m_uv;"


			"varying vec4 m_outColor;"
			"varying lowp vec2 m_outUV;"
			"uniform mat4 m_model_matrix;"
			"varying vec3 out_fragpos;"

			"void main()"
			"{"
			"	vec4 pos=vec4(m_position,1);"
			"	gl_Position=m_mvp*pos;"
			"	m_outUV=m_uv;"
			"   out_fragpos=vec3(m_model_matrix*pos);"
			"}"
		};

		const char* fragmentShader =
		{

			"precision lowp float;"
			"uniform sampler2D m_texture;"
			"uniform vec3 m_position_Light;"
			"uniform vec4 m_color_Light;"

			"varying lowp vec2 m_outUV;"
			"varying vec3 out_fragpos;"

			"void main()"
			"{"
			"	  vec3 lightdir=normalize(m_position_Light-out_fragpos);"
			"    vec3 out_normal=vec3(0.0,0.0,10.0);"
			"    vec3 out_normal_normalized=normalize(out_normal);"
			"     float cosvalue=max(dot(out_normal_normalized,lightdir),0.0);"
			"    gl_FragColor=texture2D(m_texture,m_outUV) *(m_color_Light*cosvalue+vec4(1.0,1.0,1.0,1.0));"
			//"gl_FragColor=m_color_Light;"
			//"gl_FragColor=vec4(1.0,1.0,1.0,1.0);"
			//"    gl_FragColor=texture2D(m_texture,m_outUV) *(m_color_Light);"
			//"    gl_FragColor=texture2D(m_texture,m_outUV) *(m_color_Light*cosvalue);"
			"}"
		};

		bool ret = createProgram(vertexShader, fragmentShader);
		if (ret)
		{
			m_position = glGetAttribLocation(m_programId, "m_position");
			m_color = glGetAttribLocation(m_programId, "m_color");
			m_mvp = glGetUniformLocation(m_programId, "m_mvp");

			m_uv = glGetAttribLocation(m_programId, "m_uv");
			m_texture = glGetUniformLocation(m_programId, "m_texture");

			m_position_Light= glGetUniformLocation(m_programId, "m_position_Light");
			m_color_Light = glGetUniformLocation(m_programId, "m_color_Light");

			m_model_matrix = glGetUniformLocation(m_programId, "m_model_matrix");
		}
		return ret;
	}

};
