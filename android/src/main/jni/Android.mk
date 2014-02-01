LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := emailchecker
LOCAL_CFLAGS := -std=gnu++11 -fno-exceptions -fno-rtti

EMAILCHECKER_SOURCES = $(shell find $(LOCAL_PATH)/../../../../common/ -name "*.cpp"|sed 's+$(LOCAL_PATH)/++')

ANDROID_SOURCES = $(shell find $(LOCAL_PATH)/../jni -name "*.cpp"|sed 's+$(LOCAL_PATH)/++')

LOCAL_SRC_FILES := $(EMAILCHECKER_SOURCES) $(ANDROID_SOURCES)
LOCAL_C_INCLUDES := $(LOCAL_PATH)/ $(LOCAL_PATH)/../../../../common/

APP_STL := gnustl_shared
APP_ABI := armeabi x86

include $(BUILD_SHARED_LIBRARY)
