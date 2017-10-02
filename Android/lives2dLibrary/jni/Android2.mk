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

LUA_HEAD_PATH:=../../../../Lives2D_Depends/lua-5.1.4/lua-5.1.4/src
LUA_SRC_PATH:=../../../../Lives2D_Depends/lua-5.1.4/lua-5.1.4/src

ENGINE_SRC_PATH:=../../../Src

# ProgmaBegin BuildLua

include $(CLEAR_VARS)

LOCAL_MODULE    := libLua
LOCAL_SRC_FILES := $(LUA_SRC_PATH)/lapi.c \
$(LUA_SRC_PATH)/lauxlib.c \
$(LUA_SRC_PATH)/lbaselib.c \
$(LUA_SRC_PATH)/lcode.c \
$(LUA_SRC_PATH)/ldblib.c \
$(LUA_SRC_PATH)/ldebug.c \
$(LUA_SRC_PATH)/ldo.c \
$(LUA_SRC_PATH)/ldump.c \
$(LUA_SRC_PATH)/lfunc.c \
$(LUA_SRC_PATH)/lgc.c \
$(LUA_SRC_PATH)/linit.c \
$(LUA_SRC_PATH)/liolib.c \
$(LUA_SRC_PATH)/llex.c \
$(LUA_SRC_PATH)/lmathlib.c \
$(LUA_SRC_PATH)/lmem.c \
$(LUA_SRC_PATH)/loadlib.c \
$(LUA_SRC_PATH)/lobject.c \
$(LUA_SRC_PATH)/lopcodes.c \
$(LUA_SRC_PATH)/loslib.c \
$(LUA_SRC_PATH)/lparser.c \
$(LUA_SRC_PATH)/lstate.c \
$(LUA_SRC_PATH)/lstring.c \
$(LUA_SRC_PATH)/lstrlib.c \
$(LUA_SRC_PATH)/ltable.c \
$(LUA_SRC_PATH)/ltablib.c \
$(LUA_SRC_PATH)/ltm.c \
$(LUA_SRC_PATH)/lua.c \
$(LUA_SRC_PATH)/luac.c \
$(LUA_SRC_PATH)/lundump.c \
$(LUA_SRC_PATH)/lvm.c \
$(LUA_SRC_PATH)/lzio.c \
$(LUA_SRC_PATH)/print.c \

include $(BUILD_STATIC_LIBRARY)

# ProgmaEnd

# ProgmaBegin BuildEngine
LOCAL_MODULE    := libLua
LOCAL_SRC_FILES := $(ENGINE_SRC_PATH)/Audio/AudioSource.cpp \
$(ENGINE_SRC_PATH)/Audio/lua_AudioSource.cpp \
$(ENGINE_SRC_PATH)/Audio/AudioCard.h \
$(ENGINE_SRC_PATH)/Audio/lua_AudioCard.cpp \

$(ENGINE_SRC_PATH)/GLProgram/GLProgram.h \
$(ENGINE_SRC_PATH)/GLProgram/GLProgram_Texture.h \

$(ENGINE_SRC_PATH)/GUI/UIRect.cpp \
$(ENGINE_SRC_PATH)/GUI/UIDrawRect.cpp \
$(ENGINE_SRC_PATH)/GUI/UIClickRect.cpp \
$(ENGINE_SRC_PATH)/GUI/UIButton.cpp \
$(ENGINE_SRC_PATH)/GUI/UIRoot.cpp \
$(ENGINE_SRC_PATH)/GUI/lua_UIRect.cpp \
$(ENGINE_SRC_PATH)/GUI/lua_UIDrawRect.cpp \
$(ENGINE_SRC_PATH)/GUI/lua_UIClickRect.cpp \
$(ENGINE_SRC_PATH)/GUI/lua_UIButton.cpp \
$(ENGINE_SRC_PATH)/GUI/lua_UIRoot.cpp \

$(ENGINE_SRC_PATH)/Image/Image.cpp \
$(ENGINE_SRC_PATH)/Image/lua_Image.cpp \

$(ENGINE_SRC_PATH)/ImageAnimation/ImageAnimationClip.cpp \
$(ENGINE_SRC_PATH)/ImageAnimation/ImageAnimation.cpp \
$(ENGINE_SRC_PATH)/ImageAnimation/lua_ImageAnimationClip.cpp \
$(ENGINE_SRC_PATH)/ImageAnimation/lua_ImageAnimation.cpp \

$(ENGINE_SRC_PATH)/KeyTouch/KeyCode.h \
$(ENGINE_SRC_PATH)/KeyTouch/KeyTouchListener.h \
$(ENGINE_SRC_PATH)/KeyTouch/KeyTouch.cpp \
$(ENGINE_SRC_PATH)/KeyTouch/lua_KeyTouchListener.cpp \
$(ENGINE_SRC_PATH)/KeyTouch/lua_KeyTouch.cpp \

$(ENGINE_SRC_PATH)/LuaEngine/BinaryPacker.cpp \
$(ENGINE_SRC_PATH)/LuaEngine/NetworkClient.cpp \
$(ENGINE_SRC_PATH)/LuaEngine/NetworkDispatch.cpp \
$(ENGINE_SRC_PATH)/LuaEngine/LuaEngine.cpp \
$(ENGINE_SRC_PATH)/LuaEngine/lua_BinaryPacker.cpp \
$(ENGINE_SRC_PATH)/LuaEngine/lua_NetworkClient.cpp \

$(ENGINE_SRC_PATH)/Texture2D/Texture2D.cpp \

$(ENGINE_SRC_PATH)/Tools/Application.h \

include $(BUILD_STATIC_LIBRARY)

# ProgmaEnd


include $(CLEAR_VARS)

LOCAL_MODULE    := liblives2d
LOCAL_CFLAGS    := -Werror
LOCAL_SRC_FILES := AndroidGame.cpp
LOCAL_LDLIBS    := -llog -lGLESv2

LOCAL_C_INCLUDES:=$(LUA_HEAD_PATH)
LOCAL_STATIC_LIBRARIES := libLua

include $(BUILD_SHARED_LIBRARY)
