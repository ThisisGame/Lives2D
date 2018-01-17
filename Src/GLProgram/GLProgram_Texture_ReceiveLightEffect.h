#pragma once
#include"GLProgram_Texture.h"

class GLProgram_Texture_ReceiveLightEffect :public GLProgram_Texture
{
public:

	//传入shader中的值;
	GLuint m_position;
	GLuint m_color;
	GLuint m_mvp;

	GLuint m_texture;
	GLuint m_uv;

	GLuint m_position_Light;
	GLuint m_color_Light;

public:
	GLProgram_Texture_ReceiveLightEffect()
	{
		m_position = -1;
		m_color = -1;
		m_mvp = -1;

		m_texture = -1;
		m_uv = -1;

		m_position_Light = -1;
		m_color_Light = -1;
	}

	~GLProgram_Texture_ReceiveLightEffect()
	{}

	GLuint getPositionAttribute() const
	{
		return m_position;
	}

	GLuint getColorAttribute() const
	{
		return m_color;
	}

	GLuint getMVP() const
	{
		return m_mvp;
	}

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
			"uniform mat4 m_mvp;"
			"attribute vec3 m_position;"
			"attribute vec4 m_color;"
			"attribute vec2 m_uv;"
			"uniform vec3 m_position_Light;"
			"uniform vec4 m_color_Light;"

			"varying vec4 m_outColor;"
			"varying lowp vec2 m_outUV;"

			"void main()"
			"{"
			"	vec4 pos=vec4(m_position,1);"
			"	gl_Position=m_mvp*pos;"
			"	m_outUV=m_uv;"
			"}"
		};

		const char* fragmentShader =
		{
			"uniform sampler2D m_texture;"

			"varying lowp vec2 m_outUV;"

			"void main()"
			"{"
            "    gl_FragColor=texture2D(m_texture,m_outUV);"
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
		}
		return ret;
	}

	virtual void begin()
	{
		glUseProgram(m_programId);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glEnableVertexAttribArray(m_position);
		glEnableVertexAttribArray(m_color);
		glEnableVertexAttribArray(m_uv);
	}

	virtual void end()
	{
		glDisable(GL_BLEND);

		glDisableVertexAttribArray(m_position);
		glDisableVertexAttribArray(m_color);
		glDisableVertexAttribArray(m_uv);
		glUseProgram(0);
	}
};
