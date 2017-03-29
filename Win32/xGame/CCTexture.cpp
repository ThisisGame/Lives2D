#include "CCTexture.h"


using namespace std;

#ifdef WIN32
#pragma comment(lib,"libpng16.lib")
#endif

CCTexture::CCTexture(void)
{
}

///从Png文件创建Texture
GLuint CCTexture::CreateTextureFromPng(const char* filename)
{
	unsigned char header[8]; //头部信息
	int k; //循环
	GLuint textureID; //纹理名字
	int width,height;
	png_byte color_type; //图片类型
	png_byte bit_depth; //字节深度
	png_structp png_ptr; //图片
	png_infop info_ptr; //图片信息
	int number_of_passes; //隔行扫描
	png_bytep *row_pointers; //图片数据内容
	int row,col,pos; //用于改变png像素排列的问题
	GLubyte *rgba;
	FILE *fp=fopen(filename,"rb"); //只读打开png图片
	if(!fp) //读取失败
	{
		//fclose(fp);
		return 0;
	}
	//LOGI("CreateTextureFromPng 22 \n");
	fread(header,1,8,fp); //读取8个字节
	//LOGI("CreateTextureFromPng 23 \n");
	if(png_sig_cmp(header,0,8)) //不是png图片
	{
		//LOGI("CreateTextureFromPng 24 \n");
		fclose(fp);
		return 0;
	}
	//初始化png_structp png_infop
	//LOGI("CreateTextureFromPng 3 \n");
	png_ptr=png_create_read_struct(PNG_LIBPNG_VER_STRING,NULL,NULL,NULL); //后三个参数设置错误回调
	if(!png_ptr)  //初始化失败
	{
		fclose(fp);
		return 0;
	}

	//根据初始化的png_ptr初始化png_info
	info_ptr=png_create_info_struct(png_ptr);
	if(!info_ptr)
	{
		png_destroy_read_struct(&png_ptr,(png_infopp)NULL,(png_infopp)NULL);
		fclose(fp);
		return 0;
	}
	//LOGI("CreateTextureFromPng 4 \n");
	if(setjmp(png_jmpbuf(png_ptr)))
	{
		//释放内存，关闭文件，返回一个贴图ID，此处应调用一个生成默认贴图返回ID的函数
		png_destroy_read_struct(&png_ptr,(png_infopp)NULL,(png_infopp)NULL);
		fclose(fp);
		return 0;
	}

	//通过2进制打开文件，通过i/o定制函数png_init_io
	png_init_io(png_ptr,fp);

	png_set_sig_bytes(png_ptr,8); //png标志头 跳过

	png_read_info(png_ptr,info_ptr); //实际读取图片信息

	width=png_get_image_width(png_ptr,info_ptr); //获取图片宽度

	height=png_get_image_height(png_ptr,info_ptr); //获取图片高度

	color_type=png_get_color_type(png_ptr,info_ptr); //获取图片字节深度 位深度http://t.cn/8suqDV1

	//如果图片带有alpha通道
	//if(color_type==PNG_COLOR_TYPE_RGBA)
	//{
	//	png_set_swap_alpha(png_ptr);
	//}
	//LOGI("CreateTextureFromPng 5 \n");
	bit_depth=png_get_bit_depth(png_ptr,info_ptr);

	number_of_passes=png_set_interlace_handling(png_ptr); //隔行扫描;

	png_read_update_info(png_ptr,info_ptr); //将读取到的信息更新到info_ptr;

	if(setjmp(png_jmpbuf(png_ptr))) //读文件
	{
		fclose(fp);
		return 0;
	}

	rgba=(GLubyte*)malloc(width * height *4);

	//使用动态数组 设置长度
	row_pointers=(png_bytep*) malloc (sizeof(png_bytep)*height);
	//LOGI("CreateTextureFromPng 6 \n");
	for (k = 0; k < height; k++)
	{
		row_pointers[k]=NULL;
	}

	//通过扫描流里面的每一行将得到的数据赋值给动态数组
	for(k=0;k<height;k++)
	{
		row_pointers[k]=(png_bytep)png_malloc(png_ptr,png_get_rowbytes(png_ptr,info_ptr));
	}
	//LOGI("CreateTextureFromPng 7 \n");
	//Png是从左到右 从顶到底  而贴图需要的像素是 从左到右 从底到顶 所以这里需要重新排列
	png_read_image(png_ptr,row_pointers);
	pos=(width*height*4)-(4*width);
	for (row = 0; row < height; row++)
	{
		for (col= 0; col< (4*width); col+=4)
		{
			rgba[pos++]=row_pointers[row][col]; //red
			rgba[pos++]=row_pointers[row][col+1]; //green
			rgba[pos++]=row_pointers[row][col+2]; //blue
			rgba[pos++]=row_pointers[row][col+3]; //alpha
		}
		pos=(pos-(width*4)*2);
	}
	//LOGI("CreateTextureFromPng 8 \n");
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
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,width,height,0,GL_RGBA,GL_UNSIGNED_BYTE,rgba);
	//LOGI("CreateTextureFromPng 84 \n");
	Helper::CheckGLError("glTexImage2D");

	//glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	Helper::CheckGLError("glTexParameteri");
	//LOGI("CreateTextureFromPng 9 \n");
	free(row_pointers);
	fclose(fp);
	return textureID;
}


CCTexture::~CCTexture(void)
{
}
