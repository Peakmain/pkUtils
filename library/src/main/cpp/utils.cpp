#include <jni.h>
#include <string>
#include "../include/utils/Base64Encoder.h"
#include "../include/utils/Base64Decoder.h"
#include "../include/utils/StringUtils.h"
#include "../utils/CommonStringUtils.h"

//————————————————————————————————————————————————————————String工具类 Start————————————————————————————————————————————————————————
bool isCharSequenceEmpty(JNIEnv *env, jobject input) {
    if (input == NULL) {
        return true;
    }
    jclass charSequenceClass = env->FindClass("java/lang/CharSequence");
    jmethodID charAtMethod = env->GetMethodID(charSequenceClass, "charAt", "(I)C");
    jmethodID lengthMethod = env->GetMethodID(charSequenceClass, "length", "()I");
    //获取长度
    jint length = env->CallIntMethod(input, lengthMethod);
    for (int i = 0; i < length; ++i) {
        jchar c = env->CallCharMethod(input, charAtMethod, i);
        if (c != '\0' && c != ' ') {
            return false;
        }
    }
    return true;
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_peakmain_utils_string_StringUtils_nativeIsCharEmpty(JNIEnv *env, jclass clazz,
                                                             jobject input) {
    return isCharSequenceEmpty(env, input);
}


extern "C"
JNIEXPORT jboolean JNICALL
Java_com_peakmain_utils_string_StringUtils_nativeIsEmpty(JNIEnv *env, jclass clazz, jstring str) {
    string result = CommonStringUtils::getStringUTFChars(env, str);
    return StringUtils::isEmpty(result);
}
extern "C"
JNIEXPORT jboolean JNICALL
Java_com_peakmain_utils_string_StringUtils_nativeIsStringNumeric(JNIEnv *env, jclass clazz,
                                                                 jstring str) {
    string result = CommonStringUtils::getStringUTFChars(env, str);
    return StringUtils::isNumeric(result);
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_peakmain_utils_string_StringUtils_nativeReplacePhone(JNIEnv *env, jclass clazz,
                                                              jstring str) {
    string result = CommonStringUtils::getStringUTFChars(env, str);
    string replacePhoneResult = StringUtils::replacePhone(result);
    return env->NewStringUTF(replacePhoneResult.c_str());
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_peakmain_utils_string_StringUtils_nativeConcat(JNIEnv *env, jclass clazz, jstring s1,
                                                        jstring s2) {
    string ns1 = CommonStringUtils::getStringUTFChars(env, s1);
    string ns2 = CommonStringUtils::getStringUTFChars(env, s2);
    string result = StringUtils::concat(ns1, ns2);
    return env->NewStringUTF(result.c_str());
}
extern "C"
JNIEXPORT jboolean JNICALL
Java_com_peakmain_utils_string_StringUtils_nativeContains(JNIEnv *env, jclass clazz, jstring s1,
                                                          jstring s2) {
    string ns1 = CommonStringUtils::getStringUTFChars(env, s1);
    string ns2 = CommonStringUtils::getStringUTFChars(env, s2);
    bool result = StringUtils::contains(ns1, ns2);
    return result;

}
extern "C"
JNIEXPORT jboolean JNICALL
Java_com_peakmain_utils_string_StringUtils_nativeIsDate(JNIEnv *env, jclass clazz, jstring s1) {
    string result = CommonStringUtils::getStringUTFChars(env, s1);
    return StringUtils::isDate(result);;
}


extern "C"
JNIEXPORT jboolean JNICALL
Java_com_peakmain_utils_string_StringUtils_nativeIsOnlySpaces(JNIEnv *env, jclass clazz,
                                                              jstring str) {
    string result = CommonStringUtils::getStringUTFChars(env, str);
    return StringUtils::isOnlySpaces(result);
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_peakmain_utils_string_StringUtils_nativeIsValidateIdCard(JNIEnv *env, jclass clazz,
                                                                  jstring str) {
    string result = CommonStringUtils::getStringUTFChars(env, str);
    return StringUtils::isValidateIdCard(result);
}
extern "C"
JNIEXPORT jboolean JNICALL
Java_com_peakmain_utils_string_StringUtils_nativeIsPassword(JNIEnv *env, jclass clazz,
                                                            jstring str) {
    string result = CommonStringUtils::getStringUTFChars(env, str);
    return StringUtils::isPassword(result);
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_peakmain_utils_string_StringUtils_nativeIsEmail(JNIEnv *env, jclass clazz, jstring str) {
    string result = CommonStringUtils::getStringUTFChars(env, str);
    return StringUtils::isEmail(result);
}
extern "C"
JNIEXPORT jboolean JNICALL
Java_com_peakmain_utils_string_StringUtils_nativeIsPhone(JNIEnv *env, jclass clazz, jstring str) {
    string result = CommonStringUtils::getStringUTFChars(env, str);
    return StringUtils::isPhone(result);
}
//————————————————————————————————————————————————————————String工具类 End————————————————————————————————————————————————————————

//————————————————————————————————————————————————————————加密工具类 Start————————————————————————————————————————————————————————

extern "C"
JNIEXPORT jstring JNICALL
Java_com_peakmain_utils_encryption_Base64Utils_nativeEncode(JNIEnv *env, jclass clazz,
                                                            jstring str) {
    string result = CommonStringUtils::getStringUTFChars(env, str);
    auto jResult = Base64Encoder::encode(result);
    return env->NewStringUTF(jResult.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_peakmain_utils_encryption_Base64Utils_nativeDecoder(JNIEnv *env, jclass clazz,
                                                             jstring encoded) {
    string result = CommonStringUtils::getStringUTFChars(env, encoded);
    Base64Decoder decoder;

    std::string decoded = decoder.decode(result);
    return env->NewStringUTF(decoded.c_str());
}