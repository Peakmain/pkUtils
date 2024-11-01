package com.peakmain.apputils;

import android.os.Bundle;
import android.util.Log;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

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
        Log.e("TAG","加密后:"+ Base64Utils.encode("peakmain"));
        Log.e("TAG","解密后:"+ Base64Utils.decoder("cGVha21haW4="));
    }
}
