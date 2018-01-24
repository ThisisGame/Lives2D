LOCAL_PATH := $(call my-dir)

# ProgmaBegin BuildOpenAL

OpenAL_SRC_PATH:=../../../../Lives2D_Depends/openal-soft

include $(CLEAR_VARS)

LOCAL_PATH:=$(OpenAL_SRC_PATH)

LOCAL_MODULE    := OpenAL
LOCAL_C_INCLUDES:= $(OpenAL_SRC_PATH)/Alc \
 $(OpenAL_SRC_PATH)/Alc/backends \
 $(OpenAL_SRC_PATH)/Alc/effects \
 $(OpenAL_SRC_PATH)/include/AL \
 $(OpenAL_SRC_PATH)/include \
 $(OpenAL_SRC_PATH) \
 $(OpenAL_SRC_PATH)/OpenAL32/Include

LOCAL_SRC_FILES:= \
OpenAL32/alBuffer.c \


LOCAL_CFLAGS:=-DAL_BUILD_LIBRARY -DAL_ALEXT_PROTOTYPES
				
				
LOCAL_LDLIBS :=-llog -Wl,-s



include $(BUILD_STATIC_LIBRARY)

# ProgmaEnd