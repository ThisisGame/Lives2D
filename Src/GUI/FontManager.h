#pragma once

#include"Font.h"
#include<map>
#include "Tools/Application.h"

class FontManager
{
private:
	std::map<const char*, Font*> mMapFonts;

	FontManager();

	static FontManager* mSingleton;

public:
	
	static FontManager* GetSingleton();

	~FontManager();

public:
	Font* BuildFont(const char* varFontPath);

	Font* GetFont(const char* varFontPath);
};

