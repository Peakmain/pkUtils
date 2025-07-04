package com.peakmain.apputils;

import android.os.Bundle;
import android.util.Log;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import com.peakmain.utils.calendar.CalendarUtils;
import com.peakmain.utils.calendar.model.CalendarModel;
import com.peakmain.utils.encryption.Base64Utils;
import com.peakmain.utils.string.StringUtils;

/**
 * author ：Peakmain
 * createTime：2024/10/28
 * mail:2726449200@qq.com
 * describe：
 */
public class MainActivity extends AppCompatActivity {
    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        CalendarModel calendarModel=CalendarUtils.getCurrentDateModel();
        Log.e("Java数据",calendarModel.toString());
    }
}