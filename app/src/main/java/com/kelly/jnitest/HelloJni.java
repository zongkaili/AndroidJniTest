package com.kelly.jnitest;

/**
 * Created by zongkaili on 2017/3/13.
 */

public class HelloJni {

    public native int javaCallCToAdd(int x , int y);
    public native String javaCallCToPrint(String str);
    public native int[] javaCallCToHandleArray(int[] num);

}
