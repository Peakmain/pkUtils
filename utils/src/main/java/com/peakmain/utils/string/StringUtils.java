package com.peakmain.utils.string;

/**
 * author ：Peakmain
 * createTime：2024/10/28
 * mail:2726449200@qq.com
 * describe：字符串工具类
 */
public class StringUtils {
    private StringUtils() {

    }

    static {
        System.loadLibrary("pkUtils");
    }

    public static boolean isEmpty(CharSequence input) {
        return nativeIsCharEmpty(input);
    }

    public static boolean isEmpty(String str) {
        return nativeIsEmpty(str);
    }

    public static boolean isNumeric(String str) {
        return nativeIsStringNumeric(str);
    }

    public static String replacePhone(String string) {
        return nativeReplacePhone(string);
    }

    public static String concat(String s1, String s2) {
        return nativeConcat(s1, s2);
    }

    public static boolean contains(String s1, String s2) {
        return nativeContains(s1,s2);
    }
    public static boolean isDate(String s1,String s2){
        return nativeIsDate(s1,s2);
    }

    private static native boolean nativeIsDate(String s1, String s2);

    private static native boolean nativeContains(String s1, String s2);

    private static native String nativeConcat(String s1, String s2);

    private static native String nativeReplacePhone(String string);

    private static native boolean nativeIsStringNumeric(String str);

    private static native boolean nativeIsEmpty(String str);

    private static native boolean nativeIsCharEmpty(CharSequence input);
}
