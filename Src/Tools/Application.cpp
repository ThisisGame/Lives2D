#include"Application.h"

std::string Application::mDataPath;//在安卓系统 指的是 Assets目录
std::string Application::mPersistentDataPath;//持久性存储目录，在安卓系统 指的是sdcard/Android/com.xxx.xxx/files

int Application::ScreenWidth;
int Application::ScreenHeight;
int Application::DesignWidth;
int Application::DesignHeight;
int Application::RenderWidth;//实际渲染分辨率
int Application::RenderHeight;

bool Application::isRunning;
