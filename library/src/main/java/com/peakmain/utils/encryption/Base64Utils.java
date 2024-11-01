package com.peakmain.utils.encryption;

/**
 * author ：Peakmain
 * createTime：2024/11/1
 * mail:2726449200@qq.com
 * describe：
 */
public class Base64Utils {
    private Base64Utils() {

    }

    static {
        System.loadLibrary("pkUtils");
    }
    public static String encode(String str){
        return nativeEncode(str);
    }
    public static String decoder(String str){
        return nativeDecoder(str);
    }

    private static native String nativeDecoder(String str);

    private static native String nativeEncode(String str);
}
