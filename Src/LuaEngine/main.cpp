#include"BinaryPacker.h"

#include"LuaEngine.h"

void main()
{
	BinaryPacker *pBinaryPacker = new BinaryPacker();
	pBinaryPacker->Malloc(8);
	pBinaryPacker->PushInt(1);
	pBinaryPacker->PushFloat(1.74f);

	
	LuaEngine::GetSingleton()->DoFile("./test.txt");

	BinaryPacker *pBinaryPackerSerialize=new BinaryPacker();
	pBinaryPackerSerialize->SetBinaryCache(pBinaryPacker->GetBinaryCache(), pBinaryPacker->GetBinaryCacheSize());
	
	LuaEngine::GetSingleton()->CallLuaFunction("DispatchNetwork", "BinaryPacker", pBinaryPackerSerialize);
	
	system("pause");
}