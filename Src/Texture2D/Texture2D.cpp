#include "Texture2D.h"
#include"./Tools/Helper.h"


Texture2D::Texture2D():m_textureId(-1),m_imageFilePath("")
{
	
}

void Texture2D::LoadTexture(const char* varFilePath)
{
	Helper::LOG("Texture2D::LoadTexture %s", varFilePath);

	m_imageFilePath = std::string(varFilePath);

	//1、获取图片格式;
	FREE_IMAGE_FORMAT imageformat = FreeImage_GetFileType(varFilePath, 0);

	Helper::LOG("Texture2D::LoadTexture imageformat %d", imageformat);

	//2、根据获取到的格式来加载图片;
	FIBITMAP *bitmap = FreeImage_Load(imageformat, varFilePath, 0);

	if (bitmap == nullptr)
	{
		LOGI("Error %s not exist or other error ",varFilePath);
		return;
	}

	//3、转化为rag 24色;
	bitmap = FreeImage_ConvertTo32Bits(bitmap);

	//4、获取数据指针;
	BYTE *pixels = (BYTE*)FreeImage_GetBits(bitmap);

	//5、使用;
	mTextureWidth = FreeImage_GetWidth(bitmap);
	mTextureHeight = FreeImage_GetHeight(bitmap);

	//6、交换数据，获得正确的颜色 交换1和3 RGB 原来存储的是 BGR?;
	for (int i = 0; i < mTextureWidth * mTextureHeight * 4; i += 4)
	{
		BYTE r = pixels[i];
		pixels[i] = pixels[i + 2];
		pixels[i + 2] = r;
	}

	//1、产生一个纹理ID;
	glGenTextures(1, &m_textureId);

	//2、关联绑定这个纹理ID;
	glBindTexture(GL_TEXTURE_2D, m_textureId);

	//3、指定放大，缩小滤波方式，线性滤波，即放大缩小的插值方式;
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	//将图片rgb数据上传到OpenGL,在这一步才把数据从内存Copy到显存;
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mTextureWidth, mTextureHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);

	//释放内存;
	FreeImage_Unload(bitmap);
}


Texture2D::~Texture2D()
{
}
