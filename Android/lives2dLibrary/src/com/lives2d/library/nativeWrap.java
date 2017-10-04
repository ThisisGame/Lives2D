/*
 * Copyright (C) 2007 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.lives2d.library;

import java.io.File;
import java.io.IOException;

import android.media.MediaPlayer;
import android.util.Log;

// Wrapper for native library

public class nativeWrap {

     static {
         System.loadLibrary("lives2d");
     }

    /**
     * @param width the current view width
     * @param height the current view height
     */
     public static native void init(int width, int height);
     public static native void step(float deltaTime);
     public static native void setSdCardPath(String sdcardpath);
     public static native void setAssetsPath(String assetpath);
     public static native void setsdCardDataPath(String sdcarddatapath);
     public static native void onTouch(int x,int y);
     public static native void onTouchRelease(int x,int y);
     
     
     //播放音效
     public static void PlayAudio(String varAudioPath)
     {
     	Log.i("Lives2D", "Java PlayAudio "+varAudioPath);

         final MediaPlayer mediaPlayer=new MediaPlayer();
     	
         mediaPlayer.setOnCompletionListener(new MediaPlayer.OnCompletionListener()   
 	   {//播放完毕回调监听  
 		   
 		    @Override  
 		    public void onCompletion(MediaPlayer varMediaPlayer)   
 		    {  
 		    	//Log.i("Lives2D", "PlayAudio:"+varAudioPath+" finish");  
 		    	mediaPlayer.release();
 		    }
 	   });
 	   
 	   try {  
 		      
 		    Log.i("Lives2D", "PlayAudio:"+varAudioPath);  
 		    File f= new File(varAudioPath);    
 		    if (f.exists() && f.isFile())  
 		    {    
 		    	Log.i("Lives2D", "PlayAudio:"+varAudioPath+" filesize:"+f.length());  
 		    }else
 		    {    
 		    	Log.e("Lives2D", "PlayAudio:"+varAudioPath+" file not exist");  
 		    	return;
 		    }    

 		    mediaPlayer.setDataSource(varAudioPath);  
 		  
 		    mediaPlayer.prepare();  
 		  
 		    //开始播放  
 		    mediaPlayer.start();  
 		      
 		} catch (IllegalArgumentException e) {  
 		    // TODO Auto-generated catch block  
 		    e.printStackTrace();  
 		} catch (SecurityException e) {  
 		    // TODO Auto-generated catch block  
 		    e.printStackTrace();  
 		} catch (IllegalStateException e) {  
 		    // TODO Auto-generated catch block  
 		    e.printStackTrace();  
 		} catch (IOException e) {  
 		    // TODO Auto-generated catch block  
 		    e.printStackTrace();  
 		}
    }
}
