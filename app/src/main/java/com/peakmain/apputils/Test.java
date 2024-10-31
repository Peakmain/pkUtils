package com.peakmain.apputils;

import java.util.concurrent.Callable;

/**
 * author ：Peakmain
 * createTime：2024/10/29
 * mail:2726449200@qq.com
 * describe：
 */
public class Test {

    class MyThread implements Runnable{

        @Override
        public void run() {

        }
    }

    class MyThread2 implements Callable<String>{

        @Override
        public String call() throws Exception {
            return null;
        }
    }
}
