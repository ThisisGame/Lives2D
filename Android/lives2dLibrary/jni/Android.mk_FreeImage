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
LOCAL_PATH:= $(call my-dir)
JNI_PATH:=$(call my-dir)

LUA_HEAD_PATH:=../../../../Lives2D_Depends/lua-5.1.4/lua-5.1.4/src
LUA_SRC_PATH:=../../../../Lives2D_Depends/lua-5.1.4/lua-5.1.4/src

FREE_IMAGE_SRC_PATH:=../../../../Lives2D_Depends/FreeImage

ENGINE_SRC_PATH:=../../../Src


# ProgmaBegin BuildFreeImage

include $(CLEAR_VARS)

LOCAL_PATH:=$(FREE_IMAGE_SRC_PATH)

include $(FREE_IMAGE_SRC_PATH)/Makefile.srcs

LOCAL_MODULE    := libFreeImage

LOCAL_C_INCLUDES:= $(FREE_IMAGE_SRC_PATH)/Source \
$(FREE_IMAGE_SRC_PATH)/Metadata \
$(FREE_IMAGE_SRC_PATH)/FreeImageToolkit \
$(FREE_IMAGE_SRC_PATH)/LibJPEG \
$(FREE_IMAGE_SRC_PATH)/LibPNG \
$(FREE_IMAGE_SRC_PATH)/ZLib \
$(FREE_IMAGE_SRC_PATH)/LibOpenJPEG \

LOCAL_SRC_FILES:=$(SRCS)
LOCAL_CPP_FEATURES:=rtti exceptions
#LOCAL_CFLAGS:=-O3 -fPIC

include $(BUILD_STATIC_LIBRARY)

# ProgmaEnd

include $(CLEAR_VARS)
LOCAL_PATH:= $(JNI_PATH)

LOCAL_MODULE    := liblives2d
LOCAL_CFLAGS    := -Werror
LOCAL_SRC_FILES := ./AndroidGame.cpp
LOCAL_LDLIBS    := -llog -lGLESv2

LOCAL_C_INCLUDES:= $(FREE_IMAGE_SRC_PATH)/Source
LOCAL_STATIC_LIBRARIES := libFreeImage

include $(BUILD_SHARED_LIBRARY)

