# AndroidJniTest

android关于jni的一个测试demo，简单介绍了Android中java调c和c调用java的流程

## 效果图

![pic](https://github.com/zongkaili/AndroidJniTest/blob/master/screenshot/jnitest.gif)

## 使用

### 首先需要在java层写好native方法：
```java
public class HelloJni {

    public native int javaCallCToAdd(int x , int y);
    public native String javaCallCToPrint(String str);
    public native int[] javaCallCToHandleArray(int[] num);

}
```

```java
public class HiJni {
    private Context context;
    public HiJni(Context context){
        this.context = context;
    }
    public native void cCallJava1();
    public native void cCallJava2();
    public native void cCallJava3();

    public void cCallJavaToPrint(){
        Toast.makeText(context , "hello I am from java ", Toast.LENGTH_SHORT).show();
    }

    public void cCallJavaToPrintString(String s){
        Toast.makeText(context , s, Toast.LENGTH_SHORT).show();
    }

    public int cCallJavaToAdd(int x , int y){
        Toast.makeText(context , x + " + " + y +" = " + (x + y) , Toast.LENGTH_SHORT).show();
        return x + y;
    }
}
```
### 然后Build->Make Project
这时会在app/build/intermediates/classes/debug目录下包名文件夹里生成类的.class文件

### 生成头文件
 - cmd cd进入src/main目录下
 - javah -d jni classpath  E:\projects\JniTest\app\build\intermediates\classes\debug com.kelly.jnitest.HelloJni
 - 此时会在main目录下生成jni文件夹，下面自动生成.h文件，其中包含了java层所写本地方法在c中的声明
 
    JNIEXPORT jint JNICALL Java_com_kelly_jnitest_HelloJni_javaCallCToAdd
    (JNIEnv *, jobject, jint, jint);
   注：如果生成头文件失败，可尝试在javah命令之前执行set classpath=E:\projects\JniTest\app\src\main\java
   然后执行javah -d jni com.kelly.jnitest.HelloJni

 
### 建立.c/.cpp文件，实现.h中声明的方法，方法名必须一致
```java
    jint JNICALL Java_com_kelly_jnitest_HelloJni_javaCallCToAdd(JNIEnv * env , jobject obj, jint x, jint y){
      return x + y;
    }
```
 
### 生成.so文件的配置 
```java
        ndk{
            moduleName "myjni"
            ldLibs "log"
            abiFilters "armeabi" , "armeabi-v7a" , "x86"
        }
```

### 编写Android.mk文件
```java
    LOCAL_PATH := $(call my-dir)  
    
    include $(CLEAR_VARS)  
    
    LOCAL_MODULE    := HelloJni  
    LOCAL_SRC_FILES := HelloJni.c   
    #增加 log 函数对应的log 库  liblog.so  libthread_db.a  
    LOCAL_LDLIBS += -llog  
    
    include $(BUILD_SHARED_LIBRARY) 
```

### load动态库，调用本地方法
```java
    static {
        System.loadLibrary("myjni");
    }
    
    

    HelloJni helloJni = new HelloJni()
    helloJni.javaCallCToAdd(2 , 3)
```


