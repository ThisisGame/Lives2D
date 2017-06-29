#include "UIRect.h"



UIRect::UIRect(UIRectType varUIRectType):mDepth(0), mUIRectType(varUIRectType)
{

}


UIRect::~UIRect()
{
	
}

void UIRect::SetDepth(int varDepth)
{
	mDepth = varDepth;
}

int UIRect::GetDepth()
{
	return mDepth;
}
