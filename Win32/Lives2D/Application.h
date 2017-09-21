#pragma once

class Application
{
public:
	static char* DataPath;//内部存储

	static char* persistentDataPath;//外部存储

public:
	Application()
	{
		DataPath = "../../Resources/";
		persistentDataPath = "./";
	}
};

char* Application::DataPath = "";
char* Application::persistentDataPath = "";