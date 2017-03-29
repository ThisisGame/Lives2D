#include "CCTexture.h"
#include"FreeImage.h"


using namespace std;


CCTexture::CCTexture(void)
{
}

///从Png文件创建Texture
GLuint CCTexture::CreateTextureFromPng(const char* filename)
{
	GLuint textureID; //纹理名字

	// 1、获取图片格式;
	FREE_IMAGE_FORMAT imageformat = FreeImage_GetFileType(filename, 0);

	//2、根据获取到的格式来加载图片;
	FIBITMAP *bitmap = FreeImage_Load(imageformat, filename, 0);

	//3、转化为rag 24色;
	bitmap = FreeImage_ConvertTo32Bits(bitmap);

	//4、获取数据指针;
	BYTE *pixels = (BYTE*)FreeImage_GetBits(bitmap);
	//5、使用;
	int width = FreeImage_GetWidth(bitmap);
	int height = FreeImage_GetHeight(bitmap);

	for (int i = 0; i < width* height * 4; i += 4)
	{
		BYTE r = pixels[i];
		pixels[i] = pixels[i + 2];
		pixels[i + 2] = r;
	}

	
	//开启纹理贴图 OpenGL ES2.0 不需要？开启了会报错 invalid_enum
	//glEnable(GL_TEXTURE_2D);
	//LOGI("CreateTextureFromPng 81 \n");

	//创建纹理
	glGenTextures(1,&textureID);
	//LOGI("CreateTextureFromPng 82 \n");
	Helper::CheckGLError("glGenTextures");
	//绑定纹理
	glBindTexture(GL_TEXTURE_2D,textureID);
	//LOGI("CreateTextureFromPng 83 \n");
	Helper::CheckGLError("glBindTexture");

	 //设置贴图和纹理的混合效果这里是默认只用纹理
    //glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

	//设置纹理所用的图片数据
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,width,height,0,GL_RGBA,GL_UNSIGNED_BYTE, pixels);
	//LOGI("CreateTextureFromPng 84 \n");
	Helper::CheckGLError("glTexImage2D");

	//glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	Helper::CheckGLError("glTexParameteri");

	//LOGI("CreateTextureFromPng 9 \n");
	//释放内存;
	FreeImage_Unload(bitmap);

	return textureID;
}


CCTexture::~CCTexture(void)
{
}
