#include<Windows.h>
#include"Tools/Helper.h"

#include "WinGame.h"
#include"Tools/Application.h"
#include"GUI/UIParser.h"
#include"GUI/UIRoot.h"
#include"Component/GameObject.h"

//
//int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
//{
//	UNREFERENCED_PARAMETER(hInstance);
//	UNREFERENCED_PARAMETER(hPrevInstance);
//	UNREFERENCED_PARAMETER(lpCmdLine);
//	UNREFERENCED_PARAMETER(nCmdShow);
//
//	//UIParser* tmpUIParser = new UIParser();
//	//GameObject* tmpGoUI= tmpUIParser->CreateUI((Application::PersistentDataPath() + "/Resource/UI/UI_Login/UI_Login.xml").c_str());
//	//UIRoot* tmpUIRoot =(UIRoot*)tmpGoUI->GetComponent("UIRoot");
//
//	//return 0;
//	AllocConsole();
//	freopen("CONOUT$", "a+", stdout);
//
//
//	std::string tmpConfigPath =Application::PersistentDataPath()+ "/Resource/Config.txt";
//	std::string tmpConfig = Helper::ReadTxt(tmpConfigPath.c_str());
//	std::string tmpPattern = "x";
//	std::vector<std::string> tmpConfigVector = Helper::Split(tmpConfig, tmpPattern);
//
//	int tmpWidth = std::stoi(tmpConfigVector[0]);
//	int tmpHeight = std::stoi(tmpConfigVector[1]);
//
//	WinGame game;
//	game.start(0, tmpWidth+16, tmpHeight+38);
//}