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

# ProgmaBegin BuildLua
LUA_SRC_PATH:=../../../../Lives2D_Depends/lua-5.1.4/lua-5.1.4/src
include $(CLEAR_VARS)
LOCAL_PATH:=$(LUA_SRC_PATH)

LOCAL_MODULE    := libLua
LOCAL_SRC_FILES := lapi.c \
				lauxlib.c \
				lbaselib.c \
				lcode.c \
				ldblib.c \
				ldebug.c \
				ldo.c \
				ldump.c \
				lfunc.c \
				lgc.c \
				linit.c \
				liolib.c \
				llex.c \
				lmathlib.c \
				lmem.c \
				loadlib.c \
				lobject.c \
				lopcodes.c \
				loslib.c \
				lparser.c \
				lstate.c \
				lstring.c \
				lstrlib.c \
				ltable.c \
				ltablib.c \
				ltm.c \
				lua.c \
				luac.c \
				lundump.c \
				lvm.c \
				lzio.c \
				print.c \

include $(BUILD_STATIC_LIBRARY)

# ProgmaEnd

# ProgmaBegin BuildTOLUAPP

TOLUAPP_SRC_PATH:=../../../../Lives2D_Depends/toluapp-master/toluapp-master

include $(CLEAR_VARS)

LOCAL_PATH:=$(TOLUAPP_SRC_PATH)

LOCAL_MODULE    := libTOLUAPP

LOCAL_C_INCLUDES:= $(LUA_SRC_PATH) $(TOLUAPP_SRC_PATH)/include

LOCAL_SRC_FILES:=src/lib/tolua_event.c \
src/lib/tolua_is.c \
src/lib/tolua_map.c \
src/lib/tolua_push.c \
src/lib/tolua_to.c \

LOCAL_CPP_FEATURES:=rtti exceptions
#LOCAL_CFLAGS:=-O3 -fPIC

include $(BUILD_STATIC_LIBRARY)

# ProgmaEnd

# ProgmaBegin BuildFreeImage

FREE_IMAGE_SRC_PATH:=../../../../Lives2D_Depends/FreeImage

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
LOCAL_CFLAGS:=-O3 -fPIC

include $(BUILD_STATIC_LIBRARY)

# ProgmaEnd


# ProgmaBegin BuildGLM

GLM_SRC_PATH:=../../../../Lives2D_Depends/GLM-0.9.6.3

include $(CLEAR_VARS)

LOCAL_PATH:=$(GLM_SRC_PATH)

LOCAL_MODULE    := libGLM

LOCAL_C_INCLUDES:= $(GLM_SRC_PATH)/glm \
$(GLM_SRC_PATH)/glm/detail \
$(GLM_SRC_PATH)/glm/gtc \
$(GLM_SRC_PATH)/glm/gtx \

LOCAL_SRC_FILES:=glm/detail/dummy.cpp \
glm/detail/glm.cpp \

LOCAL_CPP_FEATURES:=rtti exceptions
LOCAL_CFLAGS:=-O3 -fPIC

include $(BUILD_STATIC_LIBRARY)

# ProgmaEnd

# ProgmaBegin BuildEngine

ENGINE_SRC_PATH:=../../../Src

include $(CLEAR_VARS)

LOCAL_PATH:=$(ENGINE_SRC_PATH)

LOCAL_MODULE    := libEngine


LOCAL_SRC_FILES := Tools/Helper.cpp \
		Tools/Application.cpp \
		Tools/lua_Application.cpp \
		Audio/AudioSource.cpp \
		Audio/lua_AudioSource.cpp \
		Audio/AudioCard.cpp \
		Audio/lua_AudioCard.cpp \
		GLProgram/GLProgram.cpp \
		GLProgram/GLProgram_Texture.cpp \
		GUI/UIRect.cpp \
		GUI/UIDrawRect.cpp \
		GUI/UIClickRect.cpp \
		GUI/UIButton.cpp \
		GUI/UIRoot.cpp \
		GUI/lua_UIRect.cpp \
		GUI/lua_UIDrawRect.cpp \
		GUI/lua_UIClickRect.cpp \
		GUI/lua_UIButton.cpp \
		GUI/lua_UIRoot.cpp \
		Image/Image.cpp \
		Image/lua_Image.cpp \
		ImageAnimation/ImageAnimationClip.cpp \
		ImageAnimation/ImageAnimation.cpp \
		ImageAnimation/lua_ImageAnimationClip.cpp \
		ImageAnimation/lua_ImageAnimation.cpp \
		KeyTouch/KeyCode.cpp \
		KeyTouch/KeyTouchListener.cpp \
		KeyTouch/KeyTouch.cpp \
		KeyTouch/lua_KeyTouchListener.cpp \
		KeyTouch/lua_KeyTouch.cpp \
		LuaEngine/BinaryPacker.cpp \
		LuaEngine/NetworkClient.cpp \
		LuaEngine/NetworkDispatch.cpp \
		LuaEngine/lua_BinaryPacker.cpp \
		LuaEngine/lua_NetworkClient.cpp \
		Texture2D/Texture2D.cpp \
		LuaEngine/LuaEngine.cpp \
		
LOCAL_C_INCLUDES:= $(LUA_SRC_PATH) \
$(TOLUAPP_SRC_PATH)/include \
$(FREE_IMAGE_SRC_PATH)/Source \
$(GLM_SRC_PATH)\
$(ENGINE_SRC_PATH) \

LOCAL_STATIC_LIBRARIES := libLua libTOLUAPP libFreeImage libGLM

include $(BUILD_STATIC_LIBRARY)

# ProgmaEnd


include $(CLEAR_VARS)
LOCAL_PATH:= $(JNI_PATH)

LOCAL_MODULE    := liblives2d
LOCAL_CFLAGS    := -Werror
LOCAL_SRC_FILES := ./AndroidGame.cpp
LOCAL_LDLIBS    := -llog -lGLESv2

LOCAL_C_INCLUDES:= $(LUA_SRC_PATH) \
$(TOLUAPP_SRC_PATH)/include \
$(TOLUAPP_SRC_PATH)/src/lib \
$(FREE_IMAGE_SRC_PATH)/Source \
$(GLM_SRC_PATH) \
$(ENGINE_SRC_PATH) \

LOCAL_STATIC_LIBRARIES := libEngine

include $(BUILD_SHARED_LIBRARY)

