#pragma once

#include"freetype\ftglyph.h"

#include FT_GLYPH_H
#include FT_TRUETYPE_TABLES_H
#include FT_BITMAP_H
#include FT_WINFONTS_H

#include"../GLProgram/GLProgram_Font.h"


#include<assert.h>

#include<glm\glm.hpp>
#include<glm\gtc\matrix_transform.hpp>

#include"FreeImage.h"

#include<iostream>
#include<fstream>

class RGBA_4_BYTE
{
public:
	RGBA_4_BYTE(unsigned char r = 255, unsigned char g = 255, unsigned char b = 255, unsigned char a = 255)
	{
		R = r;
		G = g;
		B = b;
		A = a;
	}
	
	~RGBA_4_BYTE(){}

public:
	unsigned char R;
	unsigned char G;
	unsigned char B;
	unsigned char A;
};

struct  UIVertex
{
	float x, y, z;
	float u, v, w;
	RGBA_4_BYTE color;
};


class Character
{
public:
	Character()
	{
		x0 = 0;
		y0 = 0;
		x1 = 0;
		y1 = 0;
		offsetX = 0;
		offsetY = 0;
	}

public:
	//存储当前字符在Font纹理上的坐标位置，采用1024的纹理，可以存常用汉字;
	unsigned int x0 : 10;
	unsigned int y0 : 10;
	unsigned int x1 : 10;
	unsigned int y1 : 10;
	//字体偏移X;类似于gb，g是Y轴向下偏移的.
	unsigned int offsetX : 8;
	//字体偏移Y;
	unsigned int offsetY : 8;
	//所有的纹理,最大256个,2的8次方;
	unsigned int index : 8;
};

class Font
{

public:
	//字体使用GL_ALPHA格式;
	unsigned int m_fontTexture;//字体Texutre;
	Character m_character[1 << 16];//存储2的16次方个字;

	FT_Library m_FTLibrary;
	FT_Face m_FTFace;

	char* m_fontBuffer;

	int m_textureWidth; //字体纹理的宽度;
	int m_textureHeight;//字体纹理的高度;

	int m_yStart;
	int m_xStart;

	int m_fontSize;

	int m_fontPixelX;
	int m_fontPixelY;

	GLProgram_Font m_GLProgram_Font;

public:
	Font()
	{
		memset(m_character, 0, sizeof(m_character));
		m_fontPixelX = 0;
		m_fontPixelY = 0;
		m_yStart = 0;
		m_xStart = 0;
		m_textureWidth = 1024;
		m_textureHeight = 1024;

		m_fontBuffer = 0;
		m_FTLibrary = 0;
		m_FTFace = 0;

		FT_Init_FreeType(&m_FTLibrary);//FreeType初始化;
	}

	virtual ~Font()
	{

	}

	char* readFontFile(const char* filepath, unsigned int& length)
	{
		FILE *pFile = fopen(filepath, "rb");
		if (pFile)
		{
			//读取文件;
			fseek(pFile, 0, SEEK_END);
			length = ftell(pFile);
			fseek(pFile, 0, SEEK_SET);

			//建立buffer;
			char* buffer = new char[length + 1];

			//填充buffer;
			fread(buffer, 1, length, pFile);

			//buffer最后是0代表结束;
			buffer[length] = 0;

			//关闭文件;
			fclose(pFile);
			return buffer;
		}
		else
		{
			char buffer[1024];
			sprintf(buffer, "read %s failed", filepath);
			assert(pFile != 0 && buffer);
		}
		return 0;
	}

	void buildSystemFont(const char* font, int fontsize)
	{
		m_GLProgram_Font.Initialize();

		unsigned int length = 0;
		m_fontBuffer = readFontFile(font, length); //返回的是文件大小;

		//保存字体的大小;
		m_fontSize = fontsize;

		//如果已经创建，就先销毁;
		if (m_FTFace)
		{
			FT_Done_Face(m_FTFace);
			m_xStart = 0;
			m_yStart = 0;
			//清空m_character;
			memset(m_character, 0, sizeof(m_character));
		}

		//字体已创建，就先销毁;
		if (m_fontTexture != -1)
		{
			glDeleteTextures(1, &m_fontTexture);
		}

		//首次调用，生成一个GLTexture，然后绑定使用;
		glGenTextures(1, &m_fontTexture);

		glBindTexture(GL_TEXTURE_2D, m_fontTexture);

		//指定放大缩小滤波，使用线性方式，即图片放大时插值方式;
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

		//产生Texture2d;
		glTexImage2D(
			GL_TEXTURE_2D,
			0,
			GL_ALPHA,
			m_textureWidth,
			m_textureHeight,
			0,
			GL_ALPHA,
			GL_UNSIGNED_BYTE,
			0);

		FT_Error error = FT_New_Memory_Face(m_FTLibrary, (const FT_Byte*)m_fontBuffer, length, 0, &m_FTFace);
		if (error != 0)
		{
			return;
		}
		FT_Face ftFace = m_FTFace;
		FT_Select_Charmap(ftFace, FT_ENCODING_UNICODE);

		FT_F26Dot6 ftSize = (FT_F26Dot6)(fontsize*(1 << 6));

		FT_Set_Char_Size(m_FTFace, ftSize, 0, 72, 72);

		assert(m_FTFace != 0);
	}


	//读取一个字，创建Character;
	Character getCharacter(wchar_t ch)
	{
		if (m_character[ch].x0 == 0 &&
			m_character[ch].y0 == 0 &&
			m_character[ch].x1 == 0 &&
			m_character[ch].y1 == 0)
		{
			//如果之前还没有生成过这个字的信息，就先生成;
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

			//判断当前字的起始 x 坐标+字体大小 是不是超过了纹理的宽度，超过了就换行;
			if (m_xStart + glm::max(m_fontPixelX, m_fontSize) > m_textureWidth)
			{
				m_xStart = 0;

				//关于 m_fontPixelY 和 m_fontSize取大值，m_fontPixel应该是字体默认大小，m_fontSize是我们自己设置的大小;反正就是文字贴图的宽高大小;
				m_yStart += glm::max(m_fontPixelY, m_fontSize);
			}

			//Glyph：字形，图形字符 [glif];
			//加载这个字的字形,加载到 m_FTFace上面去;
			FT_Load_Glyph(m_FTFace, FT_Get_Char_Index(m_FTFace, ch), FT_LOAD_DEFAULT);

			//从 m_FTFace上面读取这个字形  到 glyph 变量;
			FT_Glyph glyph;
			FT_Get_Glyph(m_FTFace->glyph, &glyph);

			//根据字体大小决定是否启用反锯齿;
			//字体较小建议使用FT_Render_Mode_Mono;
			//>12建议使用FT_Render_Mode_Normal; 
			if (!(ch >= '0' && ch <= '9'))
			{
				FT_Glyph_To_Bitmap(&glyph, ft_render_mode_normal, 0, 1);
			}
			else
			{
				FT_Glyph_To_Bitmap(&glyph, ft_render_mode_mono, 0, 1);
			}

			FT_BitmapGlyph bitmapGlyph = (FT_BitmapGlyph)glyph;

			//返回引用;
			FT_Bitmap& bitmap = bitmapGlyph->bitmap;

			FT_Bitmap targetBitmap;

			//创建了新的 FT_Bitmap;
			FT_Bitmap_New(&targetBitmap);

			if (bitmap.pixel_mode == FT_PIXEL_MODE_MONO)
			{
				//如果Convert成功;
				if (FT_Bitmap_Convert(m_FTLibrary, &bitmap, &targetBitmap, 1) == 0)
				{
					for (unsigned char* p = targetBitmap.buffer, *endP = p + targetBitmap.width*targetBitmap.rows; p != endP;++p)
					{
						*p ^= -*p ^ *p;
					}
					bitmap = targetBitmap;
				}
			}

			//如果没有数据;
			if (bitmap.width == 0 || bitmap.rows == 0)
			{
				char mem[1024 * 32];
				memset(mem, 0, sizeof(mem));

				m_character[ch].x0 = m_xStart;
				m_character[ch].y0 = m_yStart;
				m_character[ch].x1 = m_xStart + m_fontSize / 2;
				m_character[ch].y1 = m_xStart + m_fontSize - 1;
				m_character[ch].offsetY = m_fontSize - 1;
				m_character[ch].offsetX = 0;

				glBindTexture(GL_TEXTURE_2D, m_fontTexture);

				glTexSubImage2D(
					GL_TEXTURE_2D,
					0,
					m_xStart,
					m_yStart,
					m_fontSize / 2,
					m_fontSize,
					GL_ALPHA,
					GL_UNSIGNED_BYTE,
					mem
					);
				m_xStart += m_fontSize / 2;
			}
			else
			{
				glBindTexture(GL_TEXTURE_2D, m_fontTexture);

				m_character[ch].x0 = m_xStart;
				m_character[ch].y0 = m_yStart;
				m_character[ch].x1 = m_xStart + bitmap.width;
				m_character[ch].y1 = m_yStart + bitmap.rows;

				m_character[ch].offsetY = bitmapGlyph->top;
				m_character[ch].offsetX = bitmapGlyph->left;

				glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
				glTexSubImage2D(
					GL_TEXTURE_2D,
					0,
					m_xStart,
					m_yStart,
					glm::max(1, bitmap.width),
					glm::max(1, bitmap.rows),
					GL_ALPHA,
					GL_UNSIGNED_BYTE,
					bitmap.buffer
					);
				m_xStart += (bitmap.width + 1);
				m_fontPixelY = glm::max(m_fontPixelY, bitmap.rows);
				m_fontPixelX = glm::max(m_fontPixelX, bitmap.width);

				
			}
			FT_Bitmap_Done((FT_Library)m_FTLibrary, &targetBitmap);

			
		}

		return m_character[ch];
	}

	void beginText(const glm::mat4& proj)
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glActiveTexture(GL_TEXTURE0);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, m_fontTexture);

		m_GLProgram_Font.begin();
		/**
		*   绑定程序数据
		*/
		glUniformMatrix4fv(m_GLProgram_Font.getMVPUniform(), 1, false, &proj[0][0]);
		glUniform1i(m_GLProgram_Font.getTextureUniform(), 0);
	}

	void endText()
	{
		m_GLProgram_Font.end();
	}

	glm::vec2 drawText(float x,float y,float z,RGBA_4_BYTE color,const char* text,size_t length)
	{
		static      UIVertex  vert[1024];

		float       texWidth = (float)m_textureWidth;
		float       texHeight = (float)m_textureHeight;
		float       xStart = (float)(int)x;
		float       yStart = (float)(int)y + m_fontSize;
		float       zStart = z;
		unsigned    index = 0;
		unsigned    size = length == -1 ? strlen(text) : length;
		glm::vec2      vSize(0, 0);


		if (size == 0)
		{
			return  vSize;
		}
		for (unsigned i = 0; i < size; ++i)
		{
			Character   ch = getCharacter(text[i]);

			float       h = float(ch.y1 - ch.y0);
			float       w = float(ch.x1 - ch.x0);
			float       offsetY = (float(h) - float(ch.offsetY));
			/**
			*   第一个点
			*/
			vert[index + 0].x = xStart;
			vert[index + 0].y = yStart - h + offsetY;
			vert[index + 0].z = zStart;
			vert[index + 0].u = ch.x0 / texWidth;
			vert[index + 0].v = ch.y0 / texHeight;
			vert[index + 0].w = 1;
			vert[index + 0].color = color;
			/**
			*   第二个点
			*/
			vert[index + 1].x = xStart + w;
			vert[index + 1].y = yStart - h + offsetY;
			vert[index + 1].z = zStart;
			vert[index + 1].u = ch.x1 / texWidth;
			vert[index + 1].v = ch.y0 / texHeight;
			vert[index + 1].w = 1;
			vert[index + 1].color = color;
			/**
			*   第三个点
			*/
			vert[index + 2].x = xStart + w;
			vert[index + 2].y = yStart + offsetY;
			vert[index + 2].z = zStart;
			vert[index + 2].u = ch.x1 / texWidth;
			vert[index + 2].v = ch.y1 / texHeight;
			vert[index + 2].w = 1;
			vert[index + 2].color = color;
			/**
			*   第一个点
			*/
			vert[index + 3].x = xStart;
			vert[index + 3].y = yStart - h + offsetY;
			vert[index + 3].z = zStart;
			vert[index + 3].u = ch.x0 / texWidth;
			vert[index + 3].v = ch.y0 / texHeight;
			vert[index + 3].w = 1;
			vert[index + 3].color = color;
			/**
			*   第三个点
			*/
			vert[index + 4].x = xStart + w;
			vert[index + 4].y = yStart + offsetY;
			vert[index + 4].z = zStart;
			vert[index + 4].u = ch.x1 / texWidth;
			vert[index + 4].v = ch.y1 / texHeight;
			vert[index + 4].w = 1;
			vert[index + 4].color = color;
			/**
			*   第四个点
			*/
			vert[index + 5].x = xStart;
			vert[index + 5].y = yStart + offsetY;
			vert[index + 5].z = zStart;
			vert[index + 5].u = ch.x0 / texWidth;
			vert[index + 5].v = ch.y1 / texHeight;
			vert[index + 5].w = 1;
			vert[index + 5].color = color;

			index += 6;
			xStart += w + (ch.offsetX + 1);

			vSize.x += w + (ch.offsetX + 1);
			vSize.y = glm::max(h + offsetY, vSize.y);

		}
		glVertexAttribPointer(m_GLProgram_Font.getPositionAttribute(), 3, GL_FLOAT, GL_FALSE, sizeof(UIVertex), vert);
		glVertexAttribPointer(m_GLProgram_Font.getUVAttribute(), 3, GL_FLOAT, GL_FALSE, sizeof(UIVertex), &vert[0].u);
		glVertexAttribPointer(m_GLProgram_Font.getColorAttribute(), 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(UIVertex), &vert[0].color);
		glDrawArrays(GL_TRIANGLES, 0, index);

		return  vSize;
	}
};