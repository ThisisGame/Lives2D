//
//  Font.h
//  lives2d
//
//  Created by captain on 2017/12/30.
//  Copyright © 2017年 macmini. All rights reserved.
//

#ifndef Font_h
#define Font_h

#include "freetype.h"
#include"ftglyph.h"
#include"ftbitmap.h"

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
        //LOGI("Font FT_Init_FreeType m_FTLibrary=%d",(int)&m_FTLibrary);
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
            
            //LOGI("read %s failed", filepath);
        }
        return 0;
    }
    
    void buildSystemFont(const char* font, int fontsize)
    {
        unsigned int length = 0;
        m_fontBuffer = readFontFile(font, length); //返回的是文件大小;
        
        NSLog(@"buildSystemFont length:%d",length);
        //保存字体的大小;
        m_fontSize = fontsize;
        
        //如果已经创建，就先销毁;
        if (m_FTFace)
        {
            NSLog(@"buildSystemFont m_FTFace Clear");
            FT_Done_Face(m_FTFace);
            m_xStart = 0;
            m_yStart = 0;
            //清空m_character;
            memset(m_character, 0, sizeof(m_character));
        }
        
        if(m_FTLibrary==NULL)
        {
            NSLog(@"buildSystemFont m_FTLibrary==NULL");
            return;
        }
        NSLog(@"buildSystemFont m_FTLibrary ok");
        
        if(m_fontBuffer==NULL)
        {
            NSLog(@"m_fontBuffer==NULL");
            return;
        }
        
        FT_Error error = FT_New_Memory_Face(m_FTLibrary, (const FT_Byte*)m_fontBuffer, length, 0, &m_FTFace);
        NSLog(@"buildSystemFont FT_New_Memory_Face error %d",error);
        if (error != 0)
        {
            
            return;
        }
        
        NSLog(@"buildSystemFont FT_New_Memory_Face ok");
        FT_Face ftFace = m_FTFace;
        FT_Select_Charmap(ftFace, FT_ENCODING_UNICODE);
        
        FT_F26Dot6 ftSize = (FT_F26Dot6)(fontsize*(1 << 6));
        
        FT_Set_Char_Size(m_FTFace, ftSize, 0, 72, 72);
        
        if(m_FTFace== 0)
        {
            NSLog(@"m_FTFace== 0");
        }
        
    }
    
    //读取一个字，创建Character;
    bool getCharacter(wchar_t ch)
    {
        if (m_character[ch].x0 == 0 &&
            m_character[ch].y0 == 0 &&
            m_character[ch].x1 == 0 &&
            m_character[ch].y1 == 0)
        {
            //Glyph：字形，图形字符 [glif];
            //加载这个字的字形,加载到 m_FTFace上面去;
            
            int index=FT_Get_Char_Index(m_FTFace, ch);
            NSLog(@"FT_Get_Char_Index %d",index);
            
            FT_Load_Glyph(m_FTFace, index, FT_LOAD_DEFAULT);
            
            //从 m_FTFace上面读取这个字形  到 glyph 变量;
            FT_Glyph glyph;
            FT_Get_Glyph(m_FTFace->glyph, &glyph);
            
            //根据字体大小决定是否启用反锯齿;
            //字体较小建议使用FT_Render_Mode_Mono;
            //>12建议使用FT_Render_Mode_Normal;
            if (!(ch >= L'0' && ch <= L'9'))
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
            
            NSLog(@"bitmap.width %d,bitmap.rows %d",bitmap.width,bitmap.rows);
            
            //如果没有数据;
            if (bitmap.width == 0 || bitmap.rows == 0)
            {
                
                return false;
            }
            else
            {
                
                return true;
            }
        }
        return false;
    }
};

#endif /* Font_h */
