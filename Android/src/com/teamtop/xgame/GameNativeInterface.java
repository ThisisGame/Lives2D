package com.teamtop.xgame;

public class GameNativeInterface {
	
	public static enum TOUCH_EVENT
	{
		TOUCH_DOWN,
		TOUCH_UP,
		TOUCH_MOVE
	};
	
	public static native int nativeOnCreate(int width,int height); //在Render初始化的时候初始化C++ GLES
	
	public static native int nativeOnDraw();  

	public static native int nativeOnPause();
	
	public static native int nativeOnResume();
	
	public static native int nativeOnUpdate();
	
	public static native int nativeOnEvent(byte[] date); 
	
	public static native int nativeSetDataPath(String dataPath); //设置文件存储路径

	public static native int nativeOnTouch(float x,float y,int touchevent);//将Android层的点击事件传到C++层
}
