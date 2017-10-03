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
}