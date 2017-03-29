package com.teamtop.xgame;

import android.os.Bundle;
import android.app.Activity;

public class GameActivity extends Activity {
	
	private GameSurfaceView m_gameSurfaceView;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		
		//把Activity的View设置为GLSurfaceView，并且指定Renderer为GameRender，这样刷帧渲染的时候调用的是我们自己的GameRender，然后在GameRender每一帧执行onDrawFrame的时候调用C++的nativeDraw
		m_gameSurfaceView=new GameSurfaceView(this);
		setContentView(m_gameSurfaceView);
	}

	
	//加载游戏so(C++编译而成)
	static 
	{
		System.loadLibrary("xGame");
	}

}
