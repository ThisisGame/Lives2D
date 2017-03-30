#include "CCOGL.h"
#include "CCSceneManager.h"
#include "CCAudioManager.h"



unsigned int ShaderGLPrograms[SHADER_GL_PROGRAM_COUNT]; //每一个Shader生成一个GL Program


GLuint v,f,p;
float lpos[4]={1,0.5,1,0};


GLuint g_GLProgram;  //


GLuint g_TextureID; //纹理 ，这里举例单一纹理

char g_SavePath[1024]={0};


int CCOGL::m_Width;
int CCOGL::m_Height;

CCOGL::CCOGL(void)
{
	m_Width=0;
	m_Height=0;
}

void CCOGL::ChangeSize(int w,int h)
{
	if(h==0)
	{
		h=1;
	}
	float ratio=1.0*w/h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0,0,w,h);
	gluPerspective(45,ratio,1,1000);
	glMatrixMode(GL_MODELVIEW);
}

void CCOGL::NativeRender()
{
	static int begintime=0;
	static int endtime=0;
	if(endtime-begintime>((1/60)*1000))
	{
		begintime=GetTickCount();
		CCSceneManager::SharedInstance()->Draw();
		CCSceneManager::SharedInstance()->Update();
	}
	endtime=GetTickCount();
	Sleep(1);
	
}

void CCOGL::ProcessNormalKeys(unsigned char key,int x,int y)
{
	if(key==27)
	{
		exit(0);
	}
}


bool CCOGL::NativeInit(int argc,char* argv[],int width,int height)
{
	glutInit(&argc,argv);    //初始化glut,必须调用，复制黏贴这句话即可  
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH); //设置显示方式，RGB、单缓冲。当然还有GLUT_INDEX索引颜色 GLUT_DOUBLE双缓冲(Qt中看到过双缓冲)  
	glutInitWindowPosition(100,100);   //位置
	glutInitWindowSize(width,height);//窗口大小
	glutCreateWindow("CCEngine-2D");  //创建窗口，设置标题

	glClearColor(1.0,1.0,1.0,1.0);

	glutDisplayFunc(NativeRender);  // 当绘制窗口时调用myDisplay

	glutIdleFunc(NativeRender);
	glutReshapeFunc(ChangeSize);
	glutKeyboardFunc(ProcessNormalKeys);
	glEnable(GL_DEPTH_TEST);



	
	glewInit();
	if(glewIsSupported("GL_VERSION_2_0"))
	{
		printf("Ready for OpenGL 2.0\n");
	}
	else
	{
		printf("OpenGL 2.0 not supported\n");
		return false;
	}

	//每一个Shader产生一个GLProgram
	CreateShadersGLPrograms();

	//设置像素存储模式
	glPixelStorei(GL_UNPACK_ALIGNMENT,1);
	Helper::CheckGLError("glPixelStorei");
	LOGI("glPixelStorei\n");

	glViewport(0,0,width,height);//设置视口
	LOGI("glViewport width=%d,height=%d",width,height);
	Helper::CheckGLError("glViewport");

	glUseProgram(ShaderGLPrograms[SHADER_GL_PROGRAM_NORMAL]);

	CCSceneManager::SharedInstance()->RegisterAllScene();//注册所有的场景

	CCAudioManager::SharedInstance()->Init(argc,argv);//初始化OpenAL


	glutMainLoop();  //消息循环
	return false;
}


//加载Shader
GLuint CCOGL::CreateShaderProgram(GLenum shaderType,const char* pSource)
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
GLuint CCOGL::CreateGLProgram(const char* pVertexSource,const char* pFragmentSource)
{
	LOGI("CreateGLProgram 1 \n");
	GLuint vertexShader=CreateShaderProgram(GL_VERTEX_SHADER,pVertexSource);
	if(!vertexShader)
	{
		return 0;
	}
	LOGI("CreateGLProgram 2 \n");
	GLuint fragmentShader=CreateShaderProgram(GL_FRAGMENT_SHADER,pFragmentSource);
	if(!fragmentShader)
	{
		return 0;
	}
	LOGI("CreateGLProgram 3 \n");
	GLuint program=glCreateProgram();
	if(program)
	{
		glAttachShader(program,vertexShader);
		Helper::CheckGLError("glAttachShader");
		
		glAttachShader(program,fragmentShader);
		Helper::CheckGLError("glAttachShader");
		
		glLinkProgram(program);
		GLint linkStatus=GL_FALSE;
		
		LOGI("CreateGLProgram 4 \n");
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
	LOGI("CreateGLProgram 5 \n");
	return program;
}


void CCOGL::CreateShadersGLPrograms()
{
	CompileShader(ShaderGLPrograms[SHADER_GL_PROGRAM_NORMAL],"ShaderNormal");
}

void CCOGL::CompileShader(GLuint &shaderprogram,const string &shadername)
{
	if(shaderprogram!=0) //已经编译生成了ShaderProgram
	{
		return;
	}
	if(shadername=="ShaderNormal")
	{
		shaderprogram=CreateGLProgram(g_VertexShaderNormal,g_FragmentShaderNormal);
	}

}


//设置宽高
void CCOGL::SetWidthHeight(int w,int h)
{
	m_Width=w;
	m_Height=h;
}

int CCOGL::GetWindowWidth()
{
	return m_Width;
}

int CCOGL::GetWindowHeight()
{
	return m_Height;
}

CCOGL::~CCOGL(void)
{
}
