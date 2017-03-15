/**
 * Created by zongkaili on 2017/3/13.
 */
//引入头文件
#include <com_kelly_jnitest_HelloJni.h>
#include <string.h>
#include <android/log.h>
//导入日志头文件
#include <android/log.h>
//修改日志tag中的值
#define LOG_TAG "logfromc"
//日志显示的等级
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

//相加
jint JNICALL Java_com_kelly_jnitest_HelloJni_javaCallCToAdd(JNIEnv * env , jobject obj, jint x, jint y){

   return x + y;
}

//追加字符串
jstring JNICALL Java_com_kelly_jnitest_HelloJni_javaCallCToPrint(JNIEnv * env , jobject obj, jstring str){

      return (*env)->NewStringUTF(env , "I am from c");
}

jintArray JNICALL Java_com_kelly_jnitest_HelloJni_javaCallCToHandleArray(JNIEnv * env , jobject obj, jintArray arr){
    // 1.获取到 arr的大小
    int len = (*env)->GetArrayLength(env, arr);
    LOGI("len=%d", len);

    if(len==0){
       return arr;
    }
    //取出数组中第一个元素的内存地址
    jint* p = (*env)-> GetIntArrayElements(env,arr,0);
    int i=0;
    for(;i<len;i++){
//       LOGI("len=%ld", *(p+i));//取出的每个元素
       *(p+i) += 5; //取出的每个元素加五
    }

    return arr;
}
