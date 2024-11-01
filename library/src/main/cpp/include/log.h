//
// Created by admin on 2021/8/20.
//

#ifndef ATOUR_LIFE_LOG_H
#define ATOUR_LIFE_LOG_H

#include <android/log.h>
#define TAG "ATOUR_LIFE_JNI_TAG"
#include <string.h>
# define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, TAG, __VA_ARGS__)
# define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__)
# define LOGI(...) __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)
# define LOGW(...) __android_log_print(ANDROID_LOG_WARN, TAG, __VA_ARGS__)

#endif //ATOUR_LIFE_LOG_H