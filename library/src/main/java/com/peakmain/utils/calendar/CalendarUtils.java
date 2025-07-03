package com.peakmain.utils.calendar;

import com.peakmain.utils.calendar.model.CalendarModel;

/**
 * @author ：Peakmain
 * createTime：2025/7/3
 * mail:2726449200@qq.com
 * describe：
 */
public class CalendarUtils {
    private CalendarUtils(){

    }
   static {
       System.loadLibrary("pkUtils");
   }
   public static CalendarModel getCurrentDateModel(){
       return nativeGetCurrentDateModel();
    }

    private static native CalendarModel nativeGetCurrentDateModel();
}
