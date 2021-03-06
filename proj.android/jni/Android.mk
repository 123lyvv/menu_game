LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp


HELLOCPP_FILES := $(wildcard $(LOCAL_PATH)/hellocpp/*.cpp)
HELLOCPP_FILES += $(wildcard $(LOCAL_PATH)/hellocpp/*.c)
HELLOCPP_FILES := $(HELLOCPP_FILES:$(LOCAL_PATH)/%=%)

CLASSES_FILES := $(wildcard $(LOCAL_PATH)/../../Classes/*.cpp)
CLASSES_FILES += $(wildcard $(LOCAL_PATH)/../../Classes/*.c)
CLASSES_FILES := $(CLASSES_FILES:$(LOCAL_PATH)/%=%)

LOCAL_SRC_FILES := $(HELLOCPP_FILES)
LOCAL_SRC_FILES += $(CLASSES_FILES)


LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes

LOCAL_WHOLE_STATIC_LIBRARIES += cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocosdenshion_static
LOCAL_WHOLE_STATIC_LIBRARIES += box2d_static
LOCAL_WHOLE_STATIC_LIBRARIES += chipmunk_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_extension_static

include $(BUILD_SHARED_LIBRARY)

$(call import-module,cocos2dx)
$(call import-module,cocos2dx/platform/third_party/android/prebuilt/libcurl)
$(call import-module,CocosDenshion/android)
$(call import-module,extensions)
$(call import-module,external/Box2D)
$(call import-module,external/chipmunk)
