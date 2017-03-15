package com.kelly.jnitest;

import android.content.Context;
import android.widget.Toast;

/**
 * Created by zongkaili on 2017/3/13.
 */

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
