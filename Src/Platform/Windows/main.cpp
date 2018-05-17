#include<glad/glad.h>
#include<glfw/include/glfw3.h>

#include <stdlib.h>
#include <stdio.h>

#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtx/transform2.hpp>
#include<glm/gtx/euler_angles.hpp>

#include"Tools/Application.h"

#include"LuaEngine/LuaEngine.h"




#include"PlayerPrefs/PlayerPrefs.h"

#include"Tools/Time.h"

#include"Physics/PhysicsWorld.h"

static void error_callback(int error, const char* description)
{
	fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}

	std::function<void(lua_State*)> tmpFunction = [&](lua_State* var_pLuaState)
	{
		tolua_pushnumber(var_pLuaState, key);
	};
	LuaEngine::GetSingleton()->CallLuaFunction("OnKey", 1, tmpFunction);
}

/*! @brief The function signature for mouse button callbacks.
*
*  This is the function signature for mouse button callback functions.
*
*  @param[in] window The window that received the event.
*  @param[in] button The [mouse button](@ref buttons) that was pressed or
*  released.
*  @param[in] action One of `GLFW_PRESS` or `GLFW_RELEASE`.
*  @param[in] mods Bit field describing which [modifier keys](@ref mods) were
*  held down.
*
*  @sa @ref input_mouse_button
*  @sa @ref glfwSetMouseButtonCallback
*
*  @since Added in version 1.0.
*  @glfw3 Added window handle and modifier mask parameters.
*
*  @ingroup input
*/
static void mouse_callback(GLFWwindow* window, int button, int action, int mods)
{
	switch (button)
	{
		case GLFW_MOUSE_BUTTON_LEFT:
		{
			switch (action)
			{
				case GLFW_PRESS:
				{
					double xpos, ypos;
					glfwGetCursorPos(window,&xpos, &ypos);

					int tmpX =(int) xpos;
					int tmpY = (int)ypos;

					tmpX = tmpX - Application::ScreenWidth / 2;
					tmpY = Application::ScreenHeight / 2 - tmpY;


					float tmpWidthRatio = Application::RenderWidth / (float)Application::DesignWidth;
					float tmpHeightRatio = Application::RenderHeight / (float)Application::DesignHeight;

					tmpX = tmpX / tmpWidthRatio;
					tmpY = tmpY / tmpHeightRatio;

					//Lives2D::OnTouch(tmpX, tmpY);
					std::function<void(lua_State*)> tmpFunction = [&](lua_State* var_pLuaState)
					{
						tolua_pushnumber(var_pLuaState, tmpX);
						tolua_pushnumber(var_pLuaState, tmpY);
					};
					LuaEngine::GetSingleton()->CallLuaFunction("OnTouch", 2, tmpFunction);
				}
				break;
				case GLFW_RELEASE:
				{
					double xpos, ypos;
					glfwGetCursorPos(window, &xpos, &ypos);

					int tmpX = xpos;
					int tmpY = ypos;

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
				default:
					break;
			}
		}
		break;
		case GLFW_MOUSE_BUTTON_RIGHT:
		{

		}
		break;
		case GLFW_MOUSE_BUTTON_MIDDLE:
		{

		}
		break;
		default:
			break;
		}
}

static void cursor_position_callback(GLFWwindow* window, double x, double y)
{
	//printf("%0.3f: Cursor position: %f %f\n",x,y);
}

/*! @brief The function signature for scroll callbacks.
*
*  This is the function signature for scroll callback functions.
*
*  @param[in] window The window that received the event.
*  @param[in] xoffset The scroll offset along the x-axis.
*  @param[in] yoffset The scroll offset along the y-axis.
*
*  @sa @ref scrolling
*  @sa @ref glfwSetScrollCallback
*
*  @since Added in version 3.0.  Replaces `GLFWmousewheelfun`.
*
*  @ingroup input
*/
static void mousewheel_callback(GLFWwindow*, double xoffset, double yoffset)
{
	short tmpZDelta = (short)yoffset;

	Application::MouseWheel = Application::MouseWheel - tmpZDelta;
}

void Init()
{
	PlayerPrefs::Read((Application::PersistentDataPath() + "/Resource/PlayerPrefs.xml").c_str());

	float version = PlayerPrefs::GetFloat("version");
	PlayerPrefs::SetFloat("version", 1.12);
	version = PlayerPrefs::GetFloat("version");

	bool hasissdk = PlayerPrefs::HasKey("issdk");

	bool issdk = PlayerPrefs::GetBool("issdk");
	PlayerPrefs::SetBool("issdk", true);
	issdk = PlayerPrefs::GetBool("issdk");
	hasissdk = PlayerPrefs::HasKey("issdk");

	bool firstopen = PlayerPrefs::GetBool("FirstOpenGame");
	PlayerPrefs::SetBool("FirstOpenGame", true);
	firstopen = PlayerPrefs::GetBool("FirstOpenGame");

	int logincount = PlayerPrefs::GetInt("LoginCount");
	PlayerPrefs::SetInt("LoginCount", 25);
	logincount = PlayerPrefs::GetInt("LoginCount");

	std::string servername = PlayerPrefs::GetString("ServerName");
	PlayerPrefs::SetString("ServerName", "Taohao2");
	servername = PlayerPrefs::GetString("ServerName");

	PlayerPrefs::DeleteKey("ServerName");
	PlayerPrefs::DeleteKey("issdk");



	issdk = PlayerPrefs::GetBool("issdk");
	servername = PlayerPrefs::GetString("ServerName");

	PlayerPrefs::DeleteAll();
	logincount = PlayerPrefs::GetInt("LoginCount");
	firstopen = PlayerPrefs::GetBool("FirstOpenGame");
}

void update(float varDeltaTime)
{
	PhysicsWorld::Simulation();

	//Lives2D::Update(varDeltaTime);
	std::function<void(lua_State*)> tmpFunction = [&](lua_State* var_pLuaState)
	{
		tolua_pushnumber(var_pLuaState, varDeltaTime);
	};
	Time::deltaTime = varDeltaTime;
	LuaEngine::GetSingleton()->CallLuaFunction("Update", 1, tmpFunction);
}


void render()
{
	if (Application::ScreenWidth == 0 || Application::ScreenHeight == 0)
	{
		return;
	}

	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);


	float tmpDesignRatio = (float)Application::DesignWidth / Application::DesignHeight;
	float tmpScreenRatio = (float)Application::ScreenWidth / Application::ScreenHeight;
	if (tmpScreenRatio > tmpDesignRatio)
	{
		Application::RenderWidth = Application::DesignWidth*((float)Application::ScreenHeight / Application::DesignHeight);
		Application::RenderHeight = Application::ScreenHeight;
	}
	else if (tmpScreenRatio < tmpDesignRatio)
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

	//Lives2D::Draw();
	LuaEngine::GetSingleton()->CallLuaFunction("Draw");
}



void onInit()
{
	//LuaEngine Start
	LuaEngine::GetSingleton()->DoFile((Application::PersistentDataPath() + "/Resource/Script/Engine/Lives2D.lua").c_str());

	glClearColor(0, 0, 0, 1);


	float tmpDesignRatio = (float)Application::DesignWidth / Application::DesignHeight;
	float tmpScreenRatio = (float)Application::ScreenWidth / Application::ScreenHeight;
	if (tmpScreenRatio > tmpDesignRatio)
	{
		Application::RenderWidth = Application::DesignWidth*((float)Application::ScreenHeight / Application::DesignHeight);
		Application::RenderHeight = Application::ScreenHeight;
	}
	else if (tmpScreenRatio < tmpDesignRatio)
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

	//AudioCardInit();

	//[captures] (params) -> ret {Statments;} 
	//Lives2D::Init(m_EGLSurface, m_EGLDisplay,m_width,m_height);
	//http://blog.csdn.net/booirror/article/details/26973611

	std::function<void(lua_State*)> tmpFunction = [&](lua_State* var_pLuaState)
	{
		tolua_pushnumber(var_pLuaState, Application::ScreenWidth);
		tolua_pushnumber(var_pLuaState, Application::ScreenHeight);
	};
	LuaEngine::GetSingleton()->CallLuaFunction("Init", 2, tmpFunction);
}

int main(void)
{
	GLFWwindow* window;

	glfwSetErrorCallback(error_callback);

	if (!glfwInit())
		exit(EXIT_FAILURE);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	window = glfwCreateWindow(640, 480, "Lives2d", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

	glfwSetKeyCallback(window, key_callback);

	glfwSetMouseButtonCallback(window, mouse_callback);

	glfwSetScrollCallback(window, mousewheel_callback);

	//glfwSetCursorPosCallback(window, cursor_position_callback);
	
	glfwSwapInterval(1);

	onInit();

	while (!glfwWindowShouldClose(window))
	{
		//float ratio;
		int width, height;

		glfwGetFramebufferSize(window, &width, &height);
		//ratio = width / (float)height;

		Application::ScreenWidth = width;
		Application::ScreenHeight = height;

		static int begintime = 0;
		static int endtime = 0;
		static float deltaTime = 0.0f;
		deltaTime = (endtime - begintime) / 1000.0f;

		begintime = GetTickCount();


		update(deltaTime);


		render();

		endtime = GetTickCount();


		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);

	glfwTerminate();
	exit(EXIT_SUCCESS);
}