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

include $(CLEAR_VARS)
LOCAL_PATH:= $(JNI_PATH)

LOCAL_MODULE    := liblives2d
LOCAL_CFLAGS    := -Werror -Wno-deprecated-register
LOCAL_SRC_FILES := ./AndroidGame.cpp

LOCAL_LDLIBS    := -llog -lGLESv2

LOCAL_C_INCLUDES:= $(FreeType_PATH)/include \
$(JNI_PATH) \

LOCAL_STATIC_LIBRARIES := libFreeType

include $(BUILD_SHARED_LIBRARY)

