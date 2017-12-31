#include"FontManager.h"

FontManager* FontManager::mSingleton;

FontManager::FontManager()
{
}

FontManager * FontManager::GetSingleton()
{
	if (mSingleton == nullptr)
	{
		mSingleton = new FontManager();
	}
	return mSingleton;
}

FontManager::~FontManager()
{
}

Font* FontManager::BuildFont(const char * varFontPath)
{
	if (mMapFonts.count(varFontPath) > 0)
	{
		return mMapFonts[varFontPath];
	}

	Font* font = new Font();

	char fontPath[300];
	sprintf(fontPath, "%s%s", Application::PersistentDataPath().c_str(), varFontPath);

	font->buildSystemFont(fontPath, 30);

	mMapFonts.insert(pair<const char*, Font*>(varFontPath, font));

	return font;
}

Font * FontManager::GetFont(const char * varFontPath)
{
	return mMapFonts[varFontPath];
}
