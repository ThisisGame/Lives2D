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

import android.app.Activity;
import android.os.Bundle;
import android.os.Environment;
import android.util.Log;
import android.view.WindowManager;

import java.io.File;


public class lives2dActivity extends Activity {

    glesView mView;

    @Override protected void onCreate(Bundle icicle) {
        super.onCreate(icicle);
        
        Log.i("Lives2D","onCreate");
        
        String tmpSdCardPath=Environment.getExternalStorageDirectory().getAbsolutePath();
        Log.i("Lives2D","SdCardPath:"+tmpSdCardPath);
        nativeWrap.setSdCardPath(tmpSdCardPath);
        
        
        mView = new glesView(getApplication());
        setContentView(mView);
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);
    }

    @Override protected void onPause() {
        super.onPause();
        mView.onPause();
        Log.i("Lives2D","onPause");
    }

    @Override protected void onResume() {
        super.onResume();
        mView.onResume();
        Log.i("Lives2D","onResume");
    }
}
