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
    /**
     * 截取字符串通过Unicode编码
     */
    public static String subStringByCodePoints(String input, int maxLength) {
        if (input == null || input.isEmpty()) return "";
        int length = input.length();
        int endIndex = input.offsetByCodePoints(0, Math.min(maxLength, input.codePointCount(0, length)));
        return input.substring(0, endIndex);
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
        return nativeContains(s1, s2);
    }

    public static boolean isDate(String s1, String s2) {
        return nativeIsDate(s1, s2);
    }

    public static boolean isOnlySpaces(String str) {
        return nativeIsOnlySpaces(str);
    }

    public static boolean isValidateIdCard(String str) {
        return nativeIsValidateIdCard(str);
    }

    //是否是密码
    public static boolean isPassword(String str) {
        return nativeIsPassword(str);
    }

    //是否是邮箱
    public static boolean isEmail(String str) {
        return nativeIsEmail(str);
    }

    //是否是电话号码
    public static boolean isPhone(String str) {
        return nativeIsPhone(str);
    }
    private static native boolean nativeIsPassword(String str);
    private static native boolean nativeIsEmail(String str);
    private static native boolean nativeIsPhone(String str);
    private static native boolean nativeIsValidateIdCard(String str);

    private static native boolean nativeIsOnlySpaces(String str);

    private static native boolean nativeIsDate(String s1, String s2);

    private static native boolean nativeContains(String s1, String s2);

    private static native String nativeConcat(String s1, String s2);

    private static native String nativeReplacePhone(String string);

    private static native boolean nativeIsStringNumeric(String str);

    private static native boolean nativeIsEmpty(String str);

    private static native boolean nativeIsCharEmpty(CharSequence input);
}
