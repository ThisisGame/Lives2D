#pragma once

#include <Windows.h>     
#include <iostream>      
#include <string> 

class Application
{
public:
	static std::string DataPath()
	{
		std::string tmpDataPath;

#ifdef _WIN32

#ifdef _MSC_VER
		tmpDataPath = GetProgramDir() + "/../../../";
#else
		tmpDataPath = GetProgramDir() + "/../../../";
#endif
#endif // _WIN32

		while (std::string::npos!=tmpDataPath.find("\\"))
		{
			tmpDataPath = tmpDataPath.replace(tmpDataPath.find("\\"), 1, "/");
		}
		

		return tmpDataPath;
	}

	static std::string persistentDataPath()
	{
		std::string tmpPersistentDataPath = "./";
		return tmpPersistentDataPath;
	}

private:
	static std::string GetProgramDir()
	{
		char exeFullPath[MAX_PATH]; // Full path   
		std::string strPath = "";

		GetModuleFileName(NULL, exeFullPath, MAX_PATH);
		strPath = (std::string)exeFullPath;    // Get full path of the file   

		int pos = strPath.find_last_of('\\', strPath.length());
		return strPath.substr(0, pos);  // Return the directory without the file name   
	}
};