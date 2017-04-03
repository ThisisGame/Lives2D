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

#include"Game2D_Main\Game2D.h"

class WinGame
{
public:
	HINSTANCE m_hInstance;	//ʵ�����;

	HWND m_hWnd;	//���ھ��;

	int m_width;	//����;

	int m_height;	//�߶�;


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
		m_width = 0;
		m_height = 0;
		m_hInstance = hInstance;

		m_EGLConfig = 0;
		m_EGLSurface = 0;
		m_EGLContext = 0;
		m_EGLDisplay = 0;
	}



	virtual ~WinGame()
	{
		UnregisterClass(_T("WinGame"), m_hInstance);
	}


	//��Ⱦ����;
	void render()
	{
		if (m_width == 0 || m_height == 0)
		{
			return;
		}

		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

		glViewport(0, 0, m_width, m_height);

		Game2D::render();

		eglSwapBuffers(m_EGLDisplay, m_EGLSurface);
	}


	//��ʼ��;
	void onInit()
	{
		glClearColor(0, 0, 0, 1);


		glViewport(0, 0, (GLsizei)m_width, (GLsizei)m_height);

		Game2D::Init(m_EGLSurface, m_EGLDisplay,m_width,m_height);
	}

	//��ں���;
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
				render();
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
		}
		break;
		case WM_LBUTTONUP:
		{
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
		case WM_CHAR:
		{
		}
		break;
		case WM_KEYDOWN:
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


	virtual void        onDestroy()
	{
	}

protected:
	bool _createWindow(int width, int height)
	{
		m_hWnd = CreateWindowEx(
			NULL,
			_T("WinGame"),
			_T("Game2D"),
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

		eglQuerySurface(m_EGLDisplay, m_EGLSurface, EGL_WIDTH, &m_width);
		eglQuerySurface(m_EGLDisplay, m_EGLSurface, EGL_HEIGHT, &m_height);

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