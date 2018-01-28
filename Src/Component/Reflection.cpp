#include "Reflection.h"

std::map<std::string, FunCreateInstance> Reflection::gMapTypeInfo = std::map<std::string, FunCreateInstance>();//类名和构造函数指针 列表

Reflection::Reflection()
{
}


Reflection::~Reflection()
{
}

Reflection::Reflection(std::string varTypeName, FunCreateInstance varFuncCreateInstance)
{
	gMapTypeInfo[varTypeName] = varFuncCreateInstance;
}

bool Reflection::ContaisType(std::string varTypeName)
{
	if (gMapTypeInfo[varTypeName] != nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}

}

Component * Reflection::CreateInstance(std::string varTypeName)
{
	if (ContaisType(varTypeName))
	{
		return gMapTypeInfo[varTypeName]();
	}
	else
	{
		return nullptr;
	}
}
