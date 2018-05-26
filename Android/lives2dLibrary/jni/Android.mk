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

# ProgmaBegin BuildFreeType
FreeType_PATH:=../../../../Lives2D_Depends/freetype
include $(CLEAR_VARS)
LOCAL_PATH:=$(FreeType_PATH)

LOCAL_MODULE    := libFreeType
LOCAL_SRC_FILES :=  \
 src/autofit/autofit.c \
 src/base/basepic.c \
 src/base/ftapi.c \
 src/base/ftbase.c \
 src/base/ftbbox.c \
 src/base/ftbitmap.c \
 src/base/ftdbgmem.c \
 src/base/ftdebug.c \
 src/base/ftglyph.c \
 src/base/ftinit.c \
 src/base/ftpic.c \
 src/base/ftstroke.c \
 src/base/ftsynth.c \
 src/base/ftsystem.c \
 src/cff/cff.c \
 src/pshinter/pshinter.c \
 src/pshinter/pshglob.c \
 src/pshinter/pshpic.c \
 src/pshinter/pshrec.c \
 src/psnames/psnames.c \
 src/psnames/pspic.c \
 src/raster/raster.c \
 src/raster/rastpic.c \
 src/sfnt/pngshim.c \
 src/sfnt/sfntpic.c \
 src/sfnt/ttbdf.c \
 src/sfnt/ttkern.c \
 src/sfnt/ttload.c \
 src/sfnt/ttmtx.c \
 src/sfnt/ttpost.c \
 src/sfnt/ttsbit.c \
 src/sfnt/sfobjs.c \
 src/sfnt/ttcmap.c \
 src/sfnt/sfdriver.c \
 src/smooth/smooth.c \
 src/smooth/ftspic.c \
 src/truetype/truetype.c \
 src/type1/t1driver.c \
 src/cid/cidgload.c \
 src/cid/cidload.c \
 src/cid/cidobjs.c \
 src/cid/cidparse.c \
 src/cid/cidriver.c \
 src/pfr/pfr.c \
 src/pfr/pfrgload.c \
 src/pfr/pfrload.c \
 src/pfr/pfrobjs.c \
 src/pfr/pfrsbit.c \
 src/type42/t42objs.c \
 src/type42/t42parse.c \
 src/type42/type42.c \
 src/winfonts/winfnt.c \
 src/pcf/pcfread.c \
 src/pcf/pcfutil.c \
 src/pcf/pcfdrivr.c \
 src/psaux/afmparse.c \
 src/psaux/psaux.c \
 src/psaux/psconv.c \
 src/psaux/psobjs.c \
 src/psaux/t1decode.c \
 src/tools/apinames.c \
 src/type1/t1afm.c \
 src/type1/t1gload.c \
 src/type1/t1load.c \
 src/type1/t1objs.c \
 src/type1/t1parse.c\
 src/bdf/bdfdrivr.c\
 src/bdf/bdflib.c\
 src/gzip/ftgzip.c\
 src/lzw/ftlzw.c \
 
LOCAL_CFLAGS := -DANDROID_NDK \
  -DFT2_BUILD_LIBRARY=1 
  
  
LOCAL_C_INCLUDES := $(JNI_PATH) \
  $(FreeType_PATH)/src \
  $(FreeType_PATH)/include
  
LOCAL_LDLIBS := -ldl -llog

include $(BUILD_STATIC_LIBRARY)

# ProgmaEnd

# ProgmaBegin FMOD

FMOD_INCLUDE_PATH:=$(JNI_PATH)/../../../../Lives2D_Depends/FMOD/Android/inc
FMOD_LIB_PATH:=$(JNI_PATH)/../../../../Lives2D_Depends/FMOD/Android/lib
FMOD_COMMON_PATH:=$(JNI_PATH)/../../../../Lives2D_Depends/FMOD/Android/common

include $(CLEAR_VARS)

LOCAL_MODULE            := fmod
LOCAL_SRC_FILES         := $(FMOD_LIB_PATH)/$(TARGET_ARCH_ABI)/libfmodL.so
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/../../lowlevel/inc

include $(PREBUILT_SHARED_LIBRARY)



# ProgmaEnd






# ProgmaBegin BuildBullet

Bullet_SRC_PATH:=../../../../Lives2D_Depends/bullet3

include $(CLEAR_VARS)

LOCAL_PATH:=$(Bullet_SRC_PATH)

LOCAL_MODULE    := libBullet

LOCAL_C_INCLUDES:= $(Bullet_SRC_PATH)/src

#find all the file recursively under jni/
FILE_LIST := $(wildcard \
		$(Bullet_SRC_PATH)/src/LinearMath/*.cpp \
		$(Bullet_SRC_PATH)/src/Bullet3Common/*.cpp \
		$(Bullet_SRC_PATH)/src/BulletCollision/BroadphaseCollision/*.cpp \
		$(Bullet_SRC_PATH)/src/BulletCollision/CollisionDispatch/*.cpp \
		$(Bullet_SRC_PATH)/src/BulletCollision/CollisionShapes/*.cpp \
		$(Bullet_SRC_PATH)/src/BulletCollision/NarrowPhaseCollision/*.cpp \
		$(Bullet_SRC_PATH)/src/BulletDynamics/ConstraintSolver/*.cpp \
		$(Bullet_SRC_PATH)/src/BulletDynamics/Dynamics/*.cpp \
		$(Bullet_SRC_PATH)/src/BulletDynamics/Featherstone/*.cpp \
		$(Bullet_SRC_PATH)/src/BulletDynamics/MLCPSolvers/*.cpp \
		$(Bullet_SRC_PATH)/src/BulletDynamics/Vehicle/*.cpp \
		$(Bullet_SRC_PATH)/src/BulletDynamics/Character/*.cpp \
		$(Bullet_SRC_PATH)/src/BulletSoftBody/*.cpp \
		$(Bullet_SRC_PATH)/src/BulletInverseDynamics/*.cpp \
		$(Bullet_SRC_PATH)/src/BulletInverseDynamics/details/*.cpp \
		)
LOCAL_SRC_FILES := $(FILE_LIST:$(LOCAL_PATH)/%=%)

include $(BUILD_STATIC_LIBRARY)

# ProgmaEnd








# ProgmaBegin BuildEngine

ENGINE_SRC_PATH:=../../../Src

include $(CLEAR_VARS)

LOCAL_PATH:=$(ENGINE_SRC_PATH)

LOCAL_MODULE    := libEngine


LOCAL_SRC_FILES := Tools/Helper.cpp \
		Tools/Application.cpp \
		Tools/ConvertUTF/ConvertUTF.c \
		Tools/ConvertUTF/ConvertUTFWrapper.cpp \
		Tools/lua_Application.cpp \
		Tools/Time.cpp \
		Math/Math.cpp \
		Math/lua_Math.cpp \
		PlayerPrefs/TinyXml/tinystr.cpp \
		PlayerPrefs/TinyXml/tinyxmlerror.cpp \
		PlayerPrefs/TinyXml/tinyxmlparser.cpp \
		PlayerPrefs/TinyXml/tinyxml.cpp \
		PlayerPrefs/Convert.cpp \
		PlayerPrefs/PlayerPrefs.cpp \
		Component/Component.cpp \
		Component/Behavior.cpp \
		Component/GameObject.cpp \
		Component/LuaComponent.cpp \
		Component/Object.cpp \
		Component/Reflection.cpp \
		Component/Transform.cpp \
		Component/lua_Behavior.cpp \
		Component/lua_Component.cpp \
		Component/lua_GameObject.cpp \
		Component/Lua_LuaComponent.cpp \
		Component/lua_Object.cpp \
		Component/lua_Transform.cpp \
		$(FMOD_COMMON_PATH)/common.cpp \
		$(FMOD_COMMON_PATH)/common_platform.cpp \
		Audio/AudioSource.cpp \
		Audio/lua_AudioSource.cpp \
		Audio/AudioCard.cpp \
		GLProgram/GLProgram.cpp \
		GLProgram/GLProgram_Texture.cpp \
		GLProgram/Shader.cpp \
		GUI/Font.cpp \
		GUI/FontManager.cpp \
		GUI/UIRect.cpp \
		GUI/UIDrawRect.cpp \
		GUI/UIClickRect.cpp \
		GUI/UIButton.cpp \
		GUI/UILabel.cpp \
		GUI/UIImage.cpp \
		GUI/UIRoot.cpp \
		GUI/UIParser.cpp \
		GUI/lua_UIRect.cpp \
		GUI/lua_UIDrawRect.cpp \
		GUI/lua_UIClickRect.cpp \
		GUI/lua_UIButton.cpp \
		GUI/lua_UILabel.cpp \
		GUI/lua_UIImage.cpp \
		GUI/lua_UIRoot.cpp \
		GUI/lua_UIParse.cpp \
		ImageAnimation/ImageAnimationClip.cpp \
		ImageAnimation/ImageAnimation.cpp \
		ImageAnimation/lua_ImageAnimationClip.cpp \
		ImageAnimation/lua_ImageAnimation.cpp \
		KeyTouch/KeyCode.cpp \
		KeyTouch/KeyTouchListener.cpp \
		KeyTouch/KeyTouch.cpp \
		KeyTouch/lua_KeyTouchListener.cpp \
		KeyTouch/lua_KeyTouch.cpp \
		KeyTouch/Input.cpp \
		KeyTouch/lua_Input.cpp \
		LuaEngine/BinaryPacker.cpp \
		LuaEngine/NetworkClient.cpp \
		LuaEngine/NetworkDispatch.cpp \
		LuaEngine/lua_BinaryPacker.cpp \
		LuaEngine/lua_NetworkClient.cpp \
		Texture2D/Texture2D.cpp \
		3D/Camera.cpp \
		3D/Material.cpp \
		3D/Mesh.cpp \
		3D/MeshFilter.cpp \
		3D/MeshRenderer.cpp \
		3D/Renderer.cpp \
		3D/SkinMeshParser.cpp \
		3D/SkinMeshRenderer.cpp \
		3D/lua_Camera.cpp \
		3D/lua_SkinMeshParser.cpp \
		3D/lua_Material.cpp \
		3D/lua_Mesh.cpp \
		3D/lua_MeshFilter.cpp \
		3D/lua_MeshRenderer.cpp \
		3D/lua_Renderer.cpp \
		3D/lua_SkinMeshRenderer.cpp \
		Physics/lua_PhysicsShape.cpp \
		Physics/lua_PhysicsWorld.cpp \
		Physics/lua_Raycast.cpp \
		Physics/lua_RaycastHit.cpp \
		Physics/lua_Rigidbody.cpp \
		Physics/PhysicsShape.cpp \
		Physics/PhysicsWorld.cpp \
		Physics/Raycast.cpp \
		Physics/RaycastHit.cpp \
		Physics/Rigidbody.cpp \
		LuaEngine/LuaEngine.cpp \
		
LOCAL_C_INCLUDES:= $(LUA_SRC_PATH) \
$(TOLUAPP_SRC_PATH)/include \
$(FREE_IMAGE_SRC_PATH)/Source \
$(GLM_SRC_PATH)\
$(FreeType_PATH)/include \
$(FMOD_INCLUDE_PATH) \
$(FMOD_COMMON_PATH) \
$(Bullet_SRC_PATH)/src \
$(ENGINE_SRC_PATH) \
$(JNI_PATH) \

LOCAL_STATIC_LIBRARIES := libLua libTOLUAPP libFreeImage libGLM libFreeType libBullet

include $(BUILD_STATIC_LIBRARY)

# ProgmaEnd


include $(CLEAR_VARS)
LOCAL_PATH:= $(JNI_PATH)

LOCAL_MODULE    := liblives2d
LOCAL_CFLAGS    := -Werror -Wno-deprecated-register
LOCAL_SRC_FILES := ./AndroidGame.cpp \
./JniHelper.cpp

LOCAL_LDLIBS    := -llog -lGLESv2

LOCAL_C_INCLUDES:= $(LUA_SRC_PATH) \
$(TOLUAPP_SRC_PATH)/include \
$(TOLUAPP_SRC_PATH)/src/lib \
$(FREE_IMAGE_SRC_PATH)/Source \
$(GLM_SRC_PATH) \
$(FreeType_PATH)/include \
$(Bullet_SRC_PATH)/src \
$(ENGINE_SRC_PATH) \
$(JNI_PATH) \

LOCAL_STATIC_LIBRARIES := libEngine
LOCAL_SHARED_LIBRARIES  := fmod

include $(BUILD_SHARED_LIBRARY)

