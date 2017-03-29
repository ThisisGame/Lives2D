# Copyright (C) 2009 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

######################################
include $(CLEAR_VARS)
LOCAL_MODULE := libPng
LOCAL_SRC_FILES := ../../Libs/libpng/Android/obj/local/armeabi-v7a/libPng.a
include $(PREBUILT_STATIC_LIBRARY)
######################################


######################################
include $(CLEAR_VARS)

LOCAL_MODULE    := xGame
LOCAL_SRC_FILES := NativeRender.cpp

LOCAL_CFLAGS    := -Werror -DANDROID

#引用的静态库
LOCAL_STATIC_LIBRARIES := libPng

#包含的库
LOCAL_LDLIBS    := -lGLESv2 -llog -lz

#头文件路径
LOCAL_C_INCLUDES := ../../Libs/libpng

include $(BUILD_SHARED_LIBRARY)