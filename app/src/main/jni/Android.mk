LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := HiJni
LOCAL_SRC_FILES := HiJni.c
#增加 log 函数对应的log 库  liblog.so  libthread_db.a
LOCAL_LDLIBS += -llog

include $(BUILD_SHARED_LIBRARY)