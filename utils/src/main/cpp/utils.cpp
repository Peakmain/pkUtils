#include <jni.h>
#include <string>
#include "../include/utils/Base64Encoder.h"
#include "../include/utils/StringUtils.h"

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
Java_com_peakmain_utils_string_StringUtils_isCharEmpty(JNIEnv *env, jclass clazz, jobject input) {
    return isCharSequenceEmpty(env, input);

}

/*extern "C"
JNIEXPORT jstring JNICALL
Java_com_atour_atourlife_utils_AESUtil_encodeBase64(JNIEnv *env, jclass clazz,
                                                    jbyteArray encrypted) {
    jsize len = env->GetArrayLength(encrypted);
    jbyte* data = env->GetByteArrayElements(encrypted, NULL);

    std::vector<char> charData(data, data + len);
    std::string encodedString = Base64Encoder::encode(charData);

    env->ReleaseByteArrayElements(encrypted, data, 0);

    return env->NewStringUTF(encodedString.c_str());
}*/

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_peakmain_utils_string_StringUtils_isStringEmpty(JNIEnv *env, jclass clazz, jstring str) {
    const char *cStr = env->GetStringUTFChars(str,NULL);

    if (cStr == nullptr) {
        return true;
    }
    std::string string(cStr);
    env->ReleaseStringUTFChars(str, cStr);
    return StringUtils::isEmpty(string);
}