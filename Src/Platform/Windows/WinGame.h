/**********************
*File:Light3dWinAPP.h;
*Author:chenpeng
*Data:2015/07/21;
*/

#pragma once

#include<Windows.h>
#include<tchar.h>
#include<egl\egl.h>
#include<gles2\gl2.h>
#include<glm\glm.hpp>
#include<glm\gtc\matrix_transform.hpp>
#include<glm\gtx\transform2.hpp>
#include<glm\gtx\euler_angles.hpp>

#include"Tools\Application.h"

#include"LuaEngine\LuaEngine.h"
#include"Audio\AudioCard.cpp"

class WinGame
{
public:
	HINSTANCE m_hInstance;	//ʵ�����;

	HWND m_hWnd;	//���ھ��;


	//GL���;
	EGLConfig m_EGLConfig;
	EGLSurface m_EGLSurface;
	EGLContext m_EGLContext;
	EGLDisplay m_EGLDisplay;

public:
	WinGame(HINSTANCE hInstance = 0)
	{
		//��Ҫ����һ�����ڣ�������һ��������;
		WNDCLASSEX winClass;
		//��������;
		winClass.lpszClassName = _T("WinGame");
		winClass.cbSize = sizeof(winClass);

		//��H ˮƽ����V ��ֱ���� ��С�仯���ƶ�ʱ���ػ洰�ڣ�
		//Ϊ�����е�ÿһ�����ڷ���һ��Ψһ���豸������;
		winClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
		winClass.lpfnWndProc = windowProc;
		//ʵ�����;
		winClass.hInstance = hInstance;
		//������С��ͼ��;
		winClass.hIcon = 0;
		winClass.hIconSm = 0;
		//�����;
		winClass.hCursor = LoadCursor(hInstance, IDC_ARROW);
		//���ڱ���ɫ;
		winClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
		//���ڲ˵�;
		winClass.lpszMenuName = nullptr;
		winClass.cbClsExtra = 0;
		winClass.cbWndExtra = 0;
		RegisterClassEx(&winClass);


		m_hWnd = 0;
		m_hInstance = hInstance;

		m_EGLConfig = 0;
		m_EGLSurface = 0;
		m_EGLContext = 0;
		m_EGLDisplay = 0;


		//LuaEngine Start
		LuaEngine::GetSingleton()->DoFile((Application::PersistentDataPath()+ "/Resource/Script/Engine/Lives2D.lua").c_str());
	}



	virtual ~WinGame()
	{
		UnregisterClass(_T("WinGame"), m_hInstance);
	}

	void update(float varDeltaTime)
	{
		//Lives2D::Update(varDeltaTime);
		std::function<void(lua_State*)> tmpFunction = [&](lua_State* var_pLuaState)
		{
			tolua_pushnumber(var_pLuaState, varDeltaTime);
		};
		LuaEngine::GetSingleton()->CallLuaFunction("Update", 1, tmpFunction);
	}

	//��Ⱦ����;
	void render()
	{
		if (Application::ScreenWidth == 0 || Application::ScreenHeight == 0)
		{
			return;
		}

		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

		//���ֻ������ �������� ����ֺڱ�
		float tmpDesignRatio = (float)Application::DesignWidth / Application::DesignHeight;
		float tmpScreenRatio = (float)Application::ScreenWidth / Application::ScreenHeight;
		if (tmpScreenRatio > tmpDesignRatio)//����,ȡheihgt������,width���ڱ�
		{
			Application::RenderWidth = Application::DesignWidth*((float)Application::ScreenHeight/Application::DesignHeight);
			Application::RenderHeight = Application::ScreenHeight;
		}
		else if (tmpScreenRatio < tmpDesignRatio)//����,ȡwidth������,height���ڱ�
		{
			Application::RenderWidth = Application::ScreenWidth;
			Application::RenderHeight = Application::DesignHeight*((float)Application::ScreenWidth/Application::DesignWidth);
		}
		else
		{
			Application::RenderWidth = Application::ScreenWidth;
			Application::RenderHeight = Application::ScreenHeight;
		}
		
		float viewportoffsetWidth = (Application::ScreenWidth - Application::RenderWidth) / 2;
		float viewportoffsetHeight = (Application::ScreenHeight - Application::RenderHeight) / 2;
		glViewport(viewportoffsetWidth, viewportoffsetHeight, Application::RenderWidth, Application::RenderHeight);

		//Lives2D::Draw();
		LuaEngine::GetSingleton()->CallLuaFunction("Draw");

		eglSwapBuffers(m_EGLDisplay, m_EGLSurface);
	}


	//��ʼ��;
	void onInit()
	{
		glClearColor(0, 0, 0, 1);


		//���ֻ������ �������� ����ֺڱ�
		float tmpDesignRatio = (float)Application::DesignWidth / Application::DesignHeight;
		float tmpScreenRatio = (float)Application::ScreenWidth / Application::ScreenHeight;
		if (tmpScreenRatio > tmpDesignRatio)//����,ȡheihgt������,width���ڱ�
		{
			Application::RenderWidth = Application::DesignWidth*((float)Application::ScreenHeight / Application::DesignHeight);
			Application::RenderHeight = Application::ScreenHeight;
		}
		else if (tmpScreenRatio < tmpDesignRatio)//����,ȡwidth������,height���ڱ�
		{
			Application::RenderWidth = Application::ScreenWidth;
			Application::RenderHeight = Application::DesignHeight*((float)Application::ScreenWidth / Application::DesignWidth);
		}
		else
		{
			Application::RenderWidth = Application::ScreenWidth;
			Application::RenderHeight = Application::ScreenHeight;
		}

		float viewportoffsetWidth = (Application::ScreenWidth - Application::RenderWidth) / 2;
		float viewportoffsetHeight = (Application::ScreenHeight - Application::RenderHeight) / 2;
		glViewport(viewportoffsetWidth, viewportoffsetHeight, Application::RenderWidth, Application::RenderHeight);

		AudioCardInit();

		//[captures] (params) -> ret {Statments;} 
		//Lives2D::Init(m_EGLSurface, m_EGLDisplay,m_width,m_height);
		//http://blog.csdn.net/booirror/article/details/26973611

		std::function<void(lua_State*)> tmpFunction = [&](lua_State* var_pLuaState)
		{
			tolua_pushnumber(var_pLuaState, Application::ScreenWidth);
			tolua_pushnumber(var_pLuaState, Application::ScreenHeight);
		};
		LuaEngine::GetSingleton()->CallLuaFunction("Init",2, tmpFunction);
	}

	//��ں���;
	int start(HWND hWnd, int width, int height)
	{
		Application::ScreenWidth = width;
		Application::ScreenHeight = height;

		if (hWnd == 0)
		{
			if (!_createWindow(width, height))
			{
				return -1;
			}
		}
		else
		{
			m_hWnd = hWnd;
		}

		//��ʼ��gles����;
		if (!initDevice())
		{
			return -2;
		}

		onInit();


		if (hWnd)
		{
			return 0;
		}

		MSG msg = { 0 };
		while (msg.message != WM_QUIT)
		{
			if (msg.message == WM_DESTROY ||
				msg.message == WM_CLOSE)
			{
				break;
			}
			/**
			*   ����Ϣ��������Ϣ������Ϣ���������Ⱦ����
			*/
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
			{
				static float frameTime = 1.0f/30; //��֡ 30
				static int begintime = 0;
				static int endtime = 0;
				static float deltaTime = 0.0f;
				deltaTime = (endtime - begintime)/1000.0f;
				if (deltaTime>frameTime)
				{
					begintime = GetTickCount();
					update(deltaTime);
					render();
				}
				endtime = GetTickCount();
			}
		}

		shutDownDevice();

		return 0;
	}

	/**
	*   �¼�
	*/
	virtual int     events(unsigned msg, unsigned wParam, unsigned lParam)
	{
#ifndef GET_X_LPARAM
#define GET_X_LPARAM(lp)                        ((int)(short)LOWORD(lp))
#endif

#ifndef GET_Y_LPARAM
#define GET_Y_LPARAM(lp)                        ((int)(short)HIWORD(lp))
#endif

#ifndef GET_WHEEL_DELTA_WPARAM
#define GET_WHEEL_DELTA_WPARAM(wParam)          (int)((short)HIWORD(wParam))
#endif

		//printf("msg %d  %d\n", msg,wParam);

		switch (msg)
		{
		case WM_SIZE:
		{
			RECT    rt;
			GetClientRect(m_hWnd, &rt);
			Application::ScreenWidth = rt.right - rt.left;
			Application::ScreenHeight = rt.bottom - rt.top;

		}
		break;
		case WM_LBUTTONDOWN:
		{
			int tmpX = GET_X_LPARAM(lParam);
			int tmpY = GET_Y_LPARAM(lParam);

			//ת�����������Ļ�����м䣬��������������
			tmpX = tmpX - Application::ScreenWidth / 2;
			tmpY = Application::ScreenHeight /2 - tmpY;


			//������Ʒֱ���
			float tmpWidthRatio = Application::RenderWidth / (float)Application::DesignWidth;
			float tmpHeightRatio = Application::RenderHeight / (float)Application::DesignHeight;

			tmpX = tmpX/tmpWidthRatio;
			tmpY = tmpY/tmpHeightRatio;

			//Lives2D::OnTouch(tmpX, tmpY);
			std::function<void(lua_State*)> tmpFunction = [&](lua_State* var_pLuaState)
			{
				tolua_pushnumber(var_pLuaState, tmpX);
				tolua_pushnumber(var_pLuaState, tmpY);
			};
			LuaEngine::GetSingleton()->CallLuaFunction("OnTouch", 2, tmpFunction);
		}
		break;
		case WM_LBUTTONUP:
		{
			int tmpX = GET_X_LPARAM(lParam);
			int tmpY = GET_Y_LPARAM(lParam);

			//ת�����������Ļ�����м䣬��������������
			tmpX = tmpX - Application::ScreenWidth / 2;
			tmpY = Application::ScreenHeight / 2 - tmpY;

			//������Ʒֱ���
			float tmpWidthRatio = Application::RenderWidth / (float)Application::DesignWidth;
			float tmpHeightRatio = Application::RenderHeight / (float)Application::DesignHeight;

			tmpX = tmpX / tmpWidthRatio;
			tmpY = tmpY / tmpHeightRatio;

			std::function<void(lua_State*)> tmpFunction = [&](lua_State* var_pLuaState)
			{
				tolua_pushnumber(var_pLuaState, tmpX);
				tolua_pushnumber(var_pLuaState, tmpY);
			};
			LuaEngine::GetSingleton()->CallLuaFunction("OnTouchRelease", 2, tmpFunction);
		}
		break;
		case WM_RBUTTONDOWN:
		{
		}
		break;
		case WM_RBUTTONUP:
		{
		}
		break;
		case WM_MOUSEMOVE:
		{

		}
		break;

		case WM_MOUSEWHEEL:
		{
		}
		break;



		case WM_KEYDOWN:
		{
			std::function<void(lua_State*)> tmpFunction = [&](lua_State* var_pLuaState)
			{
				tolua_pushnumber(var_pLuaState, GET_X_LPARAM(wParam));
			};
			LuaEngine::GetSingleton()->CallLuaFunction("OnKey", 1, tmpFunction);
		}
		break;
		case WM_CHAR:
		{
		}
		break;
		case WM_KEYUP:
		{

		}
		break;

		case WM_CLOSE:
		case WM_DESTROY:
		{
			::PostQuitMessage(0);
		}
		break;
		default:
			return DefWindowProc(m_hWnd, msg, wParam, lParam);
		}
		return  0;
	}


	virtual void  onDestroy()
	{
		LuaEngine::GetSingleton()->CallLuaFunction("OnDestroy");

		AudioCardExit();
	}

protected:
	bool _createWindow(int width, int height)
	{
		m_hWnd = CreateWindowEx(
			NULL,
			_T("WinGame"),
			_T("Lives2D"),
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			width,
			height,
			NULL,
			NULL,
			m_hInstance,
			this    //! ����ע�⣬����ǰ���ָ����Ϊ����������,�μ� windowProc����.
		);

		if (m_hWnd == 0)
		{
			return  false;
		}
		ShowWindow(m_hWnd, SW_SHOW);
		UpdateWindow(m_hWnd);
		return  true;
	}

	bool initDevice()
	{

		const EGLint attribs[] =
		{
			EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
			EGL_BLUE_SIZE, 8,
			EGL_GREEN_SIZE, 8,
			EGL_RED_SIZE, 8,
			EGL_DEPTH_SIZE, 24,
			EGL_NONE
		};
		EGLint 	format(0);
		EGLint	numConfigs(0);
		EGLint  major;
		EGLint  minor;

		//! 1
		m_EGLDisplay = eglGetDisplay(EGL_DEFAULT_DISPLAY);

		//! 2init
		eglInitialize(m_EGLDisplay, &major, &minor);

		//! 3
		eglChooseConfig(m_EGLDisplay, attribs, &m_EGLConfig, 1, &numConfigs);

		eglGetConfigAttrib(m_EGLDisplay, m_EGLConfig, EGL_NATIVE_VISUAL_ID, &format);
		//! 4 
		m_EGLSurface = eglCreateWindowSurface(m_EGLDisplay, m_EGLConfig, m_hWnd, NULL);

		//! 5
		EGLint attr[] = { EGL_CONTEXT_CLIENT_VERSION, 2, EGL_NONE, EGL_NONE };
		m_EGLContext = eglCreateContext(m_EGLDisplay, m_EGLConfig, 0, attr);
		//! 6
		if (eglMakeCurrent(m_EGLDisplay, m_EGLSurface, m_EGLSurface, m_EGLContext) == EGL_FALSE)
		{
			return false;
		}

		eglQuerySurface(m_EGLDisplay, m_EGLSurface, EGL_WIDTH, &Application::ScreenWidth);
		eglQuerySurface(m_EGLDisplay, m_EGLSurface, EGL_HEIGHT, &Application::ScreenHeight);

		//! windows api
		SendMessage(m_hWnd, WM_SIZE, 0, 0);
		return  true;
	}

	/**
	*   �ر�
	*/
	void    shutDownDevice()
	{

		onDestroy();
		if (m_EGLDisplay != EGL_NO_DISPLAY)
		{
			eglMakeCurrent(m_EGLDisplay, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
			if (m_EGLContext != EGL_NO_CONTEXT)
			{
				eglDestroyContext(m_EGLDisplay, m_EGLContext);
			}
			if (m_EGLSurface != EGL_NO_SURFACE)
			{
				eglDestroySurface(m_EGLDisplay, m_EGLSurface);
			}
			eglTerminate(m_EGLDisplay);
		}
		m_EGLDisplay = EGL_NO_DISPLAY;
		m_EGLContext = EGL_NO_CONTEXT;
		m_EGLSurface = EGL_NO_SURFACE;

		UnregisterClass(_T("WinGame"), m_hInstance);
	}

	static  LRESULT CALLBACK    windowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
#define GWL_USERDATA (-21)
		/**
		*   ʹ��this���ݣ���ȫ�ֺ�����ת��Ϊ��ĳ�Ա��������
		*/
		WinGame*  pThis = (WinGame*)GetWindowLong(hWnd, GWL_USERDATA);
		if (pThis)
		{
			return  pThis->events(msg, wParam, lParam);
		}
		if (WM_CREATE == msg)
		{
			CREATESTRUCT*   pCreate = (CREATESTRUCT*)lParam;
			SetWindowLong(hWnd, GWL_USERDATA, (DWORD_PTR)pCreate->lpCreateParams);
		}
		return  DefWindowProc(hWnd, msg, wParam, lParam);
	}

};
