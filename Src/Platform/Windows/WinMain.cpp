#include<Windows.h>
#include"Tools\Helper.h"

#include "WinGame.h"
#include"Tools\Application.h"
#include"PlayerPrefs/Convert.h"


int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	UNREFERENCED_PARAMETER(hInstance);
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	UNREFERENCED_PARAMETER(nCmdShow);


	Convert::StringToVector3("(100,100,0.22)");

	AllocConsole();
	freopen("CONOUT$", "a+", stdout);


	std::string tmpConfigPath =Application::PersistentDataPath()+ "/Resource/Config.txt";
	std::string tmpConfig = Helper::ReadTxt(tmpConfigPath);
	std::string tmpPattern = "x";
	std::vector<std::string> tmpConfigVector = Helper::Split(tmpConfig, tmpPattern);

	int tmpWidth = std::stoi(tmpConfigVector[0]);
	int tmpHeight = std::stoi(tmpConfigVector[1]);

	WinGame game;
	game.start(0, tmpWidth+16, tmpHeight+38);
}