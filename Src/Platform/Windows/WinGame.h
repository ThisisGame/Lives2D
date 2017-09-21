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

//#include"Lives2D_Main\Lives2D.h"

#include"LuaEngine\LuaEngine.h"

class WinGame
{
public:
	HINSTANCE m_hInstance;	//实例句柄;

	HWND m_hWnd;	//窗口句柄;

	int m_width;	//宽度;

	int m_height;	//高度;


	//GL相关;
	EGLConfig m_EGLConfig;
	EGLSurface m_EGLSurface;
	EGLContext m_EGLContext;
	EGLDisplay m_EGLDisplay;

public:
	WinGame(HINSTANCE hInstance = 0)
	{
		//想要建立一个窗口，必须有一个窗口类;
		WNDCLASSEX winClass;
		//窗口类名;
		winClass.lpszClassName = _T("WinGame");
		winClass.cbSize = sizeof(winClass);

		//当H 水平方向，V 竖直方向 大小变化或移动时，重绘窗口，
		//为该类中的每一个窗口分配一个唯一的设备上下文;
		winClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
		winClass.lpfnWndProc = windowProc;
		//实例句柄;
		winClass.hInstance = hInstance;
		//窗口最小化图标;
		winClass.hIcon = 0;
		winClass.hIconSm = 0;
		//鼠标光标;
		winClass.hCursor = LoadCursor(hInstance, IDC_ARROW);
		//窗口背景色;
		winClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
		//窗口菜单;
		winClass.lpszMenuName = nullptr;
		winClass.cbClsExtra = 0;
		winClass.cbWndExtra = 0;
		RegisterClassEx(&winClass);


		m_hWnd = 0;
		m_width = 0;
		m_height = 0;
		m_hInstance = hInstance;

		m_EGLConfig = 0;
		m_EGLSurface = 0;
		m_EGLContext = 0;
		m_EGLDisplay = 0;

		//LuaEngine Start
		LuaEngine::GetSingleton()->DoFile("./Lives2D.lua");
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

	//渲染函数;
	void render()
	{
		if (m_width == 0 || m_height == 0)
		{
			return;
		}

		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

		glViewport(0, 0, m_width, m_height);

		//Lives2D::Draw();
		LuaEngine::GetSingleton()->CallLuaFunction("Draw");

		eglSwapBuffers(m_EGLDisplay, m_EGLSurface);
	}


	//初始化;
	void onInit()
	{
		glClearColor(0, 0, 0, 1);


		glViewport(0, 0, (GLsizei)m_width, (GLsizei)m_height);

		//[captures] (params) -> ret {Statments;} 
		//Lives2D::Init(m_EGLSurface, m_EGLDisplay,m_width,m_height);
		//http://blog.csdn.net/booirror/article/details/26973611

		std::function<void(lua_State*)> tmpFunction = [&](lua_State* var_pLuaState)
		{
			tolua_pushnumber(var_pLuaState, m_width);
			tolua_pushnumber(var_pLuaState, m_height);
		};
		LuaEngine::GetSingleton()->CallLuaFunction("Init",2, tmpFunction);
	}

	//入口函数;
	int start(HWND hWnd, int width, int height)
	{
		m_width = width;
		m_height = height;

		if (hWnd == 0)
		{
			if (!_createWindow(m_width, m_height))
			{
				return -1;
			}
		}
		else
		{
			m_hWnd = hWnd;
		}

		//初始化gles环境;
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
			*   有消息，处理消息，无消息，则进行渲染绘制
			*/
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
			{
				static float frameTime = 1.0f/30; //锁帧 30
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
	*   事件
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
			m_width = rt.right - rt.left;
			m_height = rt.bottom - rt.top;

		}
		break;
		case WM_LBUTTONDOWN:
		{
			int tmpX = GET_X_LPARAM(lParam);
			int tmpY = GET_Y_LPARAM(lParam);

			//转换成零点在屏幕窗口中间，右上增长的坐标
			tmpX = tmpX - m_width / 2;
			tmpY = m_height/2 - tmpY;

			//适配设计分辨率
			float tmpWidthRatio = 960.0f/m_width;
			float tmpHeightRatio =540.0f/ m_height;

			tmpX = tmpX*tmpWidthRatio;
			tmpY = tmpY*tmpHeightRatio;

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

			//转换成零点在屏幕窗口中间，右上增长的坐标
			tmpX = tmpX - m_width / 2;
			tmpY = m_height / 2 - tmpY;

			//适配设计分辨率
			float tmpWidthRatio = 960.0f / m_width;
			float tmpHeightRatio = 540.0f / m_height;

			tmpX = tmpX*tmpWidthRatio;
			tmpY = tmpY*tmpHeightRatio;

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
			this    //! 这里注意，将当前类的指针作为参数，传递,参见 windowProc函数.
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

		eglQuerySurface(m_EGLDisplay, m_EGLSurface, EGL_WIDTH, &m_width);
		eglQuerySurface(m_EGLDisplay, m_EGLSurface, EGL_HEIGHT, &m_height);

		//! windows api
		SendMessage(m_hWnd, WM_SIZE, 0, 0);
		return  true;
	}

	/**
	*   关闭
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
		*   使用this数据，将全局函数，转化为类的成员函数调用
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
