#pragma once
#include"Helper.h"
#include"jni.h"
#include"android\asset_manager_jni.h"
class FileIO
{
public:
	FileIO(void);
	~FileIO(void);



public:
#ifdef ANDROID
	static AAssetManager* sAAssetManager;
#endif
};

