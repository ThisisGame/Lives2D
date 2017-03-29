#include <jni.h>
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <android/log.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<iostream>
#include<string>

#include"png.h"

#include "../../Win32/xGame/xNativeEvent.h"

using namespace std;

#define LOG_TAG "xGame-GLES"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

GLuint g_GLProgram;  //
GLuint g_VertexShaderPositionHandle;//Vertex Shader中vPosition变量的Handle
GLuint g_VertexShaderTexCoordHande; //纹理坐标
GLuint g_FragShaderTexSamplerHandel; //纹理

GLuint g_TextureID; //纹理 ，这里举例单一纹理


char g_SavePath[1024]={0};

jobject g_JavaObject;

//输出GL的变量的值
static void PrintGLString(const char* name,GLenum s)
{
	const char *v=(const char *)glGetString(s);
	LOGI("GL %s = %s\n",name,v); //LOGI格式化字符串然后打LOG
}

//检查GL错误
static void CheckGLError(const char* op)
{
	for(GLint error=glGetError();error;error=glGetError())
	{
		LOGI("after %s() glError (0x%x) \n",op,error);
	}
}

//顶点Shader
static const char g_VertexShader[]=
"attribute vec4 vPosition;\n" //顶点坐标
"attribute vec2 textureCoords;\n" //纹理坐标
"varying vec2 frag_textureCoords;\n" //纹理坐标传给片元着色器
"void main(){\n"
"frag_textureCoords=textureCoords;\n" //把代码中传过来的纹理坐标传到片元着色器中
"	gl_Position=vPosition;\n"
"}\n";

//片元着色器
static const char g_FragmentShader[]=
              "precision mediump float;                            \n"
                        "varying vec2 frag_textureCoords;                            \n"
                        "uniform sampler2D s_texture;                        \n"
                        "void main()                                         \n"
                        "{                                                   \n"
                        "  gl_FragColor = texture2D( s_texture, frag_textureCoords );\n"
                        "}\n";

//加载Shader
GLuint CreateShaderProgram(GLenum shaderType,const char* pSource)
{
	GLuint shader=glCreateShader(shaderType); //创建指定的shader程序
	if(shader)
	{
		glShaderSource(shader,1,&pSource,NULL); //将着色器程序源代码字符数组绑定到对应的着色器对象
		glCompileShader(shader);//编译shader
		GLint compiled=0;
		glGetShaderiv(shader,GL_COMPILE_STATUS,&compiled); //编译shader
		if(!compiled)
		{
			GLint infoLen=0;
			glGetShaderiv(shader,GL_INFO_LOG_LENGTH,&infoLen);
			if(infoLen)
			{
				char* buf=(char*)malloc(infoLen);
				if(buf)
				{
					glGetShaderInfoLog(shader,infoLen,NULL,buf);
					LOGE("Could not compile shader %d:\n%s\n",shaderType,buf); //输出错误信息
					free(buf);
				}
				glDeleteShader(shader); //编译Shader失败了，删除shader程序
				shader=0;
			}
		}
	}
	return shader;
}

//创建GL程序
GLuint CreateGLProgram(const char* pVertexSource,const char* pFragmentSource)
{
	LOGI("CreateGLProgram 1");
	GLuint vertexShader=CreateShaderProgram(GL_VERTEX_SHADER,pVertexSource);
	if(!vertexShader)
	{
		return 0;
	}
	LOGI("CreateGLProgram 2");
	GLuint fragmentShader=CreateShaderProgram(GL_FRAGMENT_SHADER,pFragmentSource);
	if(!fragmentShader)
	{
		return 0;
	}
	LOGI("CreateGLProgram 3");
	GLuint program=glCreateProgram();
	if(program)
	{
		glAttachShader(program,vertexShader);
		CheckGLError("glAttachShader");
		
		glAttachShader(program,fragmentShader);
		CheckGLError("glAttachShader");
		
		glLinkProgram(program);
		GLint linkStatus=GL_FALSE;
		
		LOGI("CreateGLProgram 4");
		glGetProgramiv(program,GL_LINK_STATUS,&linkStatus); //获取结果
		if(linkStatus!=GL_TRUE) //如果失败
		{
			GLint bufLength=0;
			glGetProgramiv(program,GL_INFO_LOG_LENGTH,&bufLength); //获取失败信息长度
			if(bufLength)
			{
				char* buf=(char*)malloc(bufLength); 
				if(buf)
				{
					glGetProgramInfoLog(program,bufLength,NULL,buf); //获取失败信息
					LOGE("could not link program:\n%s\n",buf);
					free(buf);
				}
			}
			glDeleteProgram(program);
			program=0;
		}
	}
	LOGI("CreateGLProgram 5");
	return program;
}


//读取png图片
GLuint CreateTextureFromPng(const char* filename)
{
	LOGI("CreateTextureFromPng 1");
	LOGI(filename);
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
	LOGI("CreateTextureFromPng 2");
	if(!fp) //读取失败
	{
		LOGI("CreateTextureFromPng 21");
		//fclose(fp);
		return 0;
	}
	LOGI("CreateTextureFromPng 22");
	fread(header,1,8,fp); //读取8个字节
	LOGI("CreateTextureFromPng 23");
	if(png_sig_cmp(header,0,8)) //不是png图片
	{
		LOGI("CreateTextureFromPng 24");
		fclose(fp);
		return 0;
	}
	//初始化png_structp png_infop
	LOGI("CreateTextureFromPng 3");
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
	LOGI("CreateTextureFromPng 4");
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
	//if(color_type==PNG_COLOR_TYPE_RGB_ALPHA)
	//{
	//	png_set_swap_alpha(png_ptr);
	//}
	LOGI("CreateTextureFromPng 5");
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
	LOGI("CreateTextureFromPng 6");
	for (k = 0; k < height; k++)
	{
		row_pointers[k]=NULL;
	}

	//通过扫描流里面的每一行将得到的数据赋值给动态数组
	for(k=0;k<height;k++)
	{
		row_pointers[k]=(png_bytep)png_malloc(png_ptr,png_get_rowbytes(png_ptr,info_ptr));
	}
	LOGI("CreateTextureFromPng 7");
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
	LOGI("CreateTextureFromPng 8");
	//开启纹理贴图 OpenGL ES2.0 不需要？开启了会报错 invalid_enum
	//glEnable(GL_TEXTURE_2D);
	LOGI("CreateTextureFromPng 81");

	//创建纹理
	glGenTextures(1,&textureID);
	LOGI("CreateTextureFromPng 82");
	CheckGLError("glGenTextures");
	//绑定纹理
	glBindTexture(GL_TEXTURE_2D,textureID);
	LOGI("CreateTextureFromPng 83");
	CheckGLError("glBindTexture");
	
	 //设置贴图和纹理的混合效果这里是默认只用纹理
    //glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	
	//设置纹理所用的图片数据
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,width,height,0,GL_RGBA,GL_UNSIGNED_BYTE,rgba);
	LOGI("CreateTextureFromPng 84");
	CheckGLError("glTexImage2D");

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
	CheckGLError("glTexParameteri");
	LOGI("CreateTextureFromPng 9");
	free(row_pointers);
	fclose(fp);
	return textureID;
}


//初始化程序
bool NativeInit(int width,int height)
{
	PrintGLString("Version",GL_VERSION);
	PrintGLString("Vendor",GL_VENDOR);//GL_VENDOR
	PrintGLString("Renderer",GL_RENDERER);
	PrintGLString("Extensions",GL_EXTENSIONS);
	
	LOGI("NativeInit(%d,%d)",width,height);
	
	//透明
	glEnable (GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	
	g_GLProgram=CreateGLProgram(g_VertexShader,g_FragmentShader);
	if(!g_GLProgram)
	{
		LOGE("Could not create program");
		return false;
	}
	//获取VertexShader中的vPosition
	g_VertexShaderPositionHandle=glGetAttribLocation(g_GLProgram,"vPosition");
	CheckGLError("glGetAttribLocation");

	//获取纹理坐标
	g_VertexShaderTexCoordHande=glGetAttribLocation(g_GLProgram,"textureCoords");
	CheckGLError("glGetAttribLocation");
	LOGI("g_VertexShaderTexCoordHande");

	//传递纹理
	g_FragShaderTexSamplerHandel=glGetAttribLocation(g_GLProgram,"s_texture");
	CheckGLError("glGetAttribLocation");
	LOGI("g_FragShaderTexSamplerHandel");

	//设置像素存储模式
	glPixelStorei(GL_UNPACK_ALIGNMENT,1);
	CheckGLError("glPixelStorei");
	LOGI("glPixelStorei");

	//生成纹理
	string savepath=g_SavePath;
	string filename=savepath+"/test.png";
	g_TextureID=CreateTextureFromPng(filename.c_str());
	LOGI("CreateTextureFromPng");


	LOGI("glGetAttribLocation(\"vPosition\")=%d\n",g_VertexShaderPositionHandle);
	glViewport(0,0,width,height);//设置视口
	LOGI("glViewport width=%d,height=%d",width,height);
	CheckGLError("glViewport");

	return true;
}

const GLfloat g_Vertices[]=
{
	-0.75f,1.0f,0.0f, //Position 0
	0.0f,0.0f, //TexCoord 0
	-0.75f,-1.0f,0.0f, //Position 1
	0.0f,1.0f, //TexCoord1
	0.75f,-1.0f,0.0f, //Position 2
	1.0f,1.0f, //TexCoord 2
	0.75f,1.0f,0.0f, //Position 3
	1.0f,0.0f //TexCoord3
};

const GLushort indices[]={0,1,2,0,2,3};  //三角形绘制方式 triangle_strip

GLsizei stride=5*sizeof(GLfloat); //间隔5  坐标顶点3  纹理顶点2


void NativeDraw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(g_GLProgram);
	CheckGLError("glUseProgram");

	//加载顶点坐标
	glVertexAttribPointer(g_VertexShaderPositionHandle,3,GL_FLOAT,GL_FALSE,stride,g_Vertices);
	CheckGLError("glVertexAttribPointer");

	//加载纹理坐标
	glVertexAttribPointer(g_VertexShaderTexCoordHande,2,GL_FLOAT,GL_FALSE,stride,&g_Vertices[3]);

	glEnableVertexAttribArray(g_VertexShaderPositionHandle);
	glEnableVertexAttribArray(g_VertexShaderTexCoordHande);
	CheckGLError("glEnableVertexAttribArray");


	glActiveTexture(GL_TEXTURE0);
	CheckGLError("glActiveTexture");
	glBindTexture(GL_TEXTURE_2D,g_TextureID);
	CheckGLError("glBindTexture");

	//设置纹理 为0
	glUniform1i(g_FragShaderTexSamplerHandel,0);
	CheckGLError("glUniform1i");

	glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_SHORT,indices);
	CheckGLError("glDrawElements");
}


void NativeTouch(float x,float y,TOUCH_EVENT event)
{
	LOGI("NativeTouch x = %f y=%f event=%d",x,y,(int)event);
	switch(event)
	{
		case TOUCH_DOWN:
			LOGI("NativeTouch x = %f y=%f event=TOUCH_DOWN",x,y);
			break;
		case TOUCH_UP:
			LOGI("NativeTouch x = %f y=%f event=TOUCH_UP",x,y);
			break;
		case TOUCH_MOVE:
			LOGI("NativeTouch x = %f y=%f event=TOUCH_MOVE",x,y);
			break;
		default:
			break;
	}
}

extern "C"
{
	JNIEXPORT jint JNICALL Java_com_teamtop_xgame_GameNativeInterface_nativeOnCreate(JNIEnv* env,jclass obj,jint width,jint height);
	JNIEXPORT jint JNICALL Java_com_teamtop_xgame_GameNativeInterface_nativeSetDataPath(JNIEnv* env,jclass obj,jstring savepath);
	JNIEXPORT jint JNICALL Java_com_teamtop_xgame_GameNativeInterface_nativeOnUpdate(JNIEnv* env,jclass obj);
	JNIEXPORT jint JNICALL Java_com_teamtop_xgame_GameNativeInterface_nativeOnDraw(JNIEnv *env,jclass obj);
	JNIEXPORT jint JNICALL Java_com_teamtop_xgame_GameNativeInterface_nativeOnTouch(JNIEnv *env,jclass obj,jfloat x,jfloat y,jint touchtype);
}

//创建render
JNIEXPORT jint JNICALL Java_com_teamtop_xgame_GameNativeInterface_nativeOnCreate(JNIEnv* env,jclass obj,jint width,jint height)
{
	NativeInit(width,height);
}

//设置资源存储路径
JNIEXPORT jint JNICALL Java_com_teamtop_xgame_GameNativeInterface_nativeSetDataPath(JNIEnv* env,jclass obj,jstring savepath)
{
	g_JavaObject=obj;

	jboolean bRet;
	const char *savepathCStr=env->GetStringUTFChars(savepath,&bRet); //获取savepath
	memset(g_SavePath,0,1024);
	memcpy(g_SavePath,savepathCStr,strlen(savepathCStr)); //拷贝

	LOGI("g_SavePath = %s",g_SavePath);

	env->ReleaseStringUTFChars(savepath,savepathCStr); //通知虚拟机这块内存不再被访问，需要释放 (*env)->ReleaseStringUTFChars(env, jstring, str);
}

//Update
JNIEXPORT jint JNICALL Java_com_teamtop_xgame_GameNativeInterface_nativeOnUpdate(JNIEnv* env,jclass obj)
{
	
}

//Draw
JNIEXPORT jint JNICALL Java_com_teamtop_xgame_GameNativeInterface_nativeOnDraw(JNIEnv *env,jclass obj)
{
	NativeDraw();
}

//屏幕点击事件
JNIEXPORT jint JNICALL Java_com_teamtop_xgame_GameNativeInterface_nativeOnTouch(JNIEnv *env,jclass obj,jfloat x,jfloat y,jint touchevent)
{
	NativeTouch((float)x,(float)y,(TOUCH_EVENT)touchevent);
}

string NativeJstringToString(JNIEnv *env,jclass obj,jstring jstr)
{
	char charArray[1024]={0};
	jboolean bRet;
	const char *cstr=env->GetStringUTFChars(jstr,&bRet);
	memset(charArray,0,strlen(cstr));
	env->ReleaseStringUTFChars(jstr,cstr);
	return string(charArray);
}
