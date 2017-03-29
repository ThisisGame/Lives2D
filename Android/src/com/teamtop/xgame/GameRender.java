package com.teamtop.xgame;

import java.io.File;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import com.teamtop.util.GameGlobalVal;

import android.opengl.GLSurfaceView.Renderer;
import android.os.Environment;

public class GameRender implements Renderer {

	private int m_Width;
	private int m_Height;
	
	private long m_begin=0;
	private long m_end=0;
	

	@Override
	public void onDrawFrame(GL10 arg0) {
		// TODO Auto-generated method stub
		
		//通过暂停来限制帧率
		m_end=System.currentTimeMillis(); //一帧结束
		long time=m_end-m_begin;	//计算渲染这一帧的时间
		long frame_time=33;   //设置每一帧的间隔时间
		if(time<frame_time) //如果渲染这一帧的时间没有33ms,就暂停33-渲染一帧的时间
		{
			try {
				Thread.sleep(frame_time-time);
			} catch (InterruptedException e) {
				// TODO: handle exception
				e.printStackTrace();
			}
		}
		
		m_begin=System.currentTimeMillis(); //一帧开始
	
		GameNativeInterface.nativeOnUpdate();
		GameNativeInterface.nativeOnDraw(); //Android层的刷帧都执行C++层的刷帧
		
	}

	//这个函数相当于Glut中的resharp,就是改变窗口大小的回调
	@Override
	public void onSurfaceChanged(GL10 gl, int width, int height) {
		// TODO Auto-generated method stub
	}

	//相当与GLut中的Init
	@Override
	public void onSurfaceCreated(GL10 gl, EGLConfig config) {
		// TODO Auto-generated method stub
		
		String sdcardPathString=Environment.getExternalStorageDirectory().getPath(); //获取存储卡地址
		GameNativeInterface.nativeSetDataPath(sdcardPathString+ File.separator+GameGlobalVal.SavePath); //设置游戏资源存储路径
		
		GameNativeInterface.nativeOnCreate(m_Width, m_Height);
	}
	
	//设置渲染视口大小
	public void setScreenWidthHeight(int width,int height)
	{
		m_Width=width;
		m_Height=height;
	}

}
