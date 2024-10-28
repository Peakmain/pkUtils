package com.peakmain.utils.string;

/**
 * author ：Peakmain
 * createTime：2024/10/28
 * mail:2726449200@qq.com
 * describe：字符串工具类
 */
public class StringUtils {
    private StringUtils(){

    }
    static {
        System.loadLibrary("pkUtils");
    }
    public static boolean isEmpty(CharSequence input){
        return isCharEmpty(input);
    }
    public static boolean isEmpty(String str){
        return isStringEmpty(str);
    }

    private static native boolean isStringEmpty(String str);

    private static native boolean isCharEmpty(CharSequence input);
}
