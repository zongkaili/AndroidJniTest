package com.kelly.jnitest;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import butterknife.Bind;
import butterknife.ButterKnife;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {
    static {
        System.loadLibrary("myjni");
    }
    @Bind(R.id.btn1) Button mBtn1;
    @Bind(R.id.btn2) Button mBtn2;
    @Bind(R.id.btn3) Button mBtn3;
    @Bind(R.id.btn4) Button mBtn4;
    @Bind(R.id.btn5) Button mBtn5;
    @Bind(R.id.btn6) Button mBtn6;
    @Bind(R.id.text1) TextView mTv1;
    @Bind(R.id.text2) TextView mTv2;
    @Bind(R.id.text3) TextView mTv3;

    HelloJni helloJni;
    HiJni hiJni;

    int[] num = new int[]{1 , 2 , 3};

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        ButterKnife.bind(this);

        helloJni = new HelloJni();
        hiJni = new HiJni(this);

        addListenter();
    }

    private void addListenter() {
        mBtn1.setOnClickListener(this);
        mBtn2.setOnClickListener(this);
        mBtn3.setOnClickListener(this);
        mBtn4.setOnClickListener(this);
        mBtn5.setOnClickListener(this);
        mBtn6.setOnClickListener(this);
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()){
            case R.id.btn1:
                mTv1.setText("2 + 3 = " + helloJni.javaCallCToAdd(2 , 3));
                break;
            case R.id.btn2:
                mTv2.setText(helloJni.javaCallCToPrint("I am from java"));
                break;
            case R.id.btn3:
                int[] intArray = helloJni.javaCallCToHandleArray(num);
                String str = "";
                for(int i=0;i<intArray.length;i++){
                    str += intArray[i];//拼接成字符串，最终放在变量str中
                }
                mTv3.setText("数组：" + str);
                break;
            case R.id.btn4:
                hiJni.cCallJava1();
                break;
            case R.id.btn5:
                hiJni.cCallJava2();
                break;
            case R.id.btn6:
                hiJni.cCallJava3();
                break;
        }
    }
}
