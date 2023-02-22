//
// Created by lingweitao on 2023/2/22.
//
#include "dll_DataManger.h"

const std::map<const char *, std::string> mp = {
        {"1", "one"},
        {"2", "two"},
        {"3", "three"},
        {"4", "four"},
        {"5", "five"}
};
/*
 * Class:     dll_DataManger
 * Method:    getValueByKey
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */

void util_jstring_to_char(JNIEnv *env, jstring jstr, char *result) {
    if (env == NULL || jstr == NULL) {
        return;
    }
    jclass clsstring = env->FindClass("java/lang/String");
    jstring strencode = env->NewStringUTF("utf-8");
    jmethodID mid = env->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray barr = (jbyteArray) env->CallObjectMethod(jstr, mid, strencode);
    jsize alen = env->GetArrayLength(barr);
    jbyte *ba = env->GetByteArrayElements(barr, JNI_FALSE);
    if (alen > 0) {
        memcpy(result, ba, alen);
        result[alen] = 0;
    }
    env->ReleaseByteArrayElements(barr, ba, 0);
}

JNIEXPORT jstring JNICALL Java_dll_DataManger_getValueByKey
        (JNIEnv *env, jobject obj, jstring str) {
    char result[128] = {};
    util_jstring_to_char(env, str, result);
      return env->NewStringUTF(result);

}

/*
 * Class:     dll_DataManger
 * Method:    getMapSize
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_dll_DataManger_getMapSize
        (JNIEnv *, jobject) {
    return mp.size();
}