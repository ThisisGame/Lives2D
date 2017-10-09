#pragma once

#include"GLProgram.h"

class GLProgram_Font :public GLProgram
{
public:

	//传入shader中的值;
	GLint m_position;
	GLint m_color;
	GLint m_mvp;

	GLint m_texture;
	GLint m_uv;

public:
	GLProgram_Font()
	{
		m_position = -1;
		m_color = -1;
		m_mvp = -1;

		m_texture = -1;
		m_uv = -1;
	}

	~GLProgram_Font()
	{}

	GLint getPositionAttribute() const
	{
		return m_position;
	}

	GLint getColorAttribute() const
	{
		return m_color;
	}

	GLint getUVAttribute() const
	{
		return m_uv;
	}

	GLint getMVPUniform() const
	{
		return m_mvp;
	}

	GLint getTextureUniform() const
	{
		return m_texture;
	}

	//attribute:只能在Vertexshader中使用;
	//Unifrom:在Vertex和Fragment中共享使用,且不能被修改;
	//Varying:从Vertex传递数据到Fragment中使用;
	virtual bool Initialize()
	{
		const char* vertexShader =
		{
			"precision lowp float;"
			"uniform mat4 m_mvp;"
			"attribute vec3 m_position;"
			"attribute vec3 m_uv;"
			"attribute vec4 m_color;"

			"varying vec3 m_outUV;"
			"varying vec4 m_outColor;"

			"void main()"
			"{"
			"	vec4 pos=vec4(m_position.x,m_position.y,m_position.z,1);"
			"	gl_Position=m_mvp*pos;"
			"	m_outUV=m_uv;"
			"	m_outColor=m_color;"
			"}"
		};

		const char* fragmentShader =
		{
			"precision lowp float;"
			"uniform sampler2D m_texture;"
			"varying vec3 m_outUV;"
			"varying vec4 m_outColor;"


			"void main()"
			"{"
			"	vec4 color=texture2D(m_texture,vec2(m_outUV.x,m_outUV.y));"
			"	if(m_outUV.z>0.0)"
			"	{"
			"		gl_FragColor = vec4(m_outColor.x,m_outColor.y,m_outColor.z,color.w*m_outColor.w);"
			"	}"
			"	else"
			"	{"
			"		gl_FragColor=color*m_outColor;"
			"	}"
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
		}
		return ret;
	}

	virtual void begin()
	{
		glUseProgram(m_programId);
		glEnableVertexAttribArray(m_position);
		glEnableVertexAttribArray(m_color);
		glEnableVertexAttribArray(m_uv);
	}

	virtual void end()
	{
		glDisableVertexAttribArray(m_position);
		glDisableVertexAttribArray(m_color);
		glDisableVertexAttribArray(m_uv);
		glUseProgram(0);
	}
};