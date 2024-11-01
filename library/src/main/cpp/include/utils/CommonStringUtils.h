//
// Created by 周成东 on 2024/10/31.
//

#ifndef UTILS_COMMONSTRINGUTILS_H
#define UTILS_COMMONSTRINGUTILS_H

#include <iostream>
#include <regex>
#include <jni.h>

using namespace std;

struct CommonStringUtils {
    static bool isRegexMatch(const string &str, const string &p) {
        if (str.empty())return false;
        regex pattern(p);
        return regex_match(str, pattern);
    }

    static string getStringUTFChars(JNIEnv *env, const jstring &jStr) {
        if (jStr == nullptr) {
            return "";
        }
        const char *cStr = env->GetStringUTFChars(jStr, nullptr);
        std::string result(cStr); // 复制内容到 std::string
        env->ReleaseStringUTFChars(jStr, cStr); // 释放原始内存
        return result;
    }
};

#endif //UTILS_COMMONSTRINGUTILS_H
