#include "Component.h"




Component::Component()
{
	
}


Component::~Component()
{
}

void Component::SetComponentName(std::string varComponentName)
{
	mComponentName = varComponentName;
}

std::string Component::GetComponentName()
{
	return mComponentName;
}
