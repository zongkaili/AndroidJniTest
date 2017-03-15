/**
 * Created by zongkaili on 2017/3/13.
 */
//引入头文件
#include <com_kelly_jnitest_HiJni.h>
#include <string.h>
//导入日志头文件
#include <android/log.h>
//修改日志tag中的值
#define LOG_TAG "logfromc"
//日志显示的等级
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)


//调用java中的方法：cCallJavaToPrint
JNIEXPORT void JNICALL Java_com_kelly_jnitest_HiJni_cCallJava1
        (JNIEnv * env, jobject obj){
    char* classname = "com/kelly/jnitest/HiJni";
    jclass dpclazz = (*env)->FindClass(env , classname);
    if (dpclazz == 0) {
       LOGI("not find class!");
    } else {
       LOGI("find class");
    }
     jmethodID methodID = (*env)->GetMethodID(env , dpclazz , "cCallJavaToPrint" , "()V");
    if (methodID == 0) {
       LOGI("not find method!");
    } else{
       LOGI("find method");
    }
    (*env)->CallVoidMethod(env, obj, methodID);
}

//调用java中的方法：cCallJavaToPrintString
JNIEXPORT void JNICALL Java_com_kelly_jnitest_HiJni_cCallJava2
        (JNIEnv * env, jobject obj){
    LOGI("in code");
    // 获取到DataProvider对象
    char* classname = "com/kelly/jnitest/HiJni";
    jclass dpclazz = (*env)->FindClass(env,classname);
    if (dpclazz == 0) {
    LOGI("not find class!");
    } else
    LOGI("find class");
    // 获取到要调用的method
    jmethodID methodID = (*env)->GetMethodID(env,dpclazz,"cCallJavaToPrintString","(Ljava/lang/String;)V");
    if (methodID == 0) {
    LOGI("not find method!");
    } else
    LOGI("find method");

    //调用这个方法
    (*env)->CallVoidMethod(env, obj,methodID,(*env)->NewStringUTF(env,"hello I am from c"));
}

//调用java中的方法：cCallJavaToAdd
JNIEXPORT void JNICALL Java_com_kelly_jnitest_HiJni_cCallJava3
        (JNIEnv * env, jobject obj){
    char* classname = "com/kelly/jnitest/HiJni";
    jclass dpclazz = (*env)->FindClass(env,classname);
    jmethodID methodID = (*env)->GetMethodID(env,dpclazz,"cCallJavaToAdd","(II)I");
    (*env)->CallIntMethod(env, obj,methodID,5l,6l);
}
