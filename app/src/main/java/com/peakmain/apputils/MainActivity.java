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
        Log.e("TAG","解密后:"+ Base64Utils.decoder("eyJjYWxsSWQiOiJvcmRlci9zZWxlY3RQZXJzb24iLCJkYXRhIjoie1wiY2hlY2tlZFwiOnRydWUsXCJjaGVja2Vkc3RhdGVcIjowLFwiY2hlY2tpbmlkXCI6MTMxMzgsXCJjcmVhdGV0aW1lXCI6XCIyMDI0LTExLTEyIDEzOjQ3OjAxXCIsXCJjcmVpZFwiOm51bGwsXCJjcmV0eXBlXCI6bnVsbCxcIm1lbW9cIjpudWxsLFwibW9iaWxlXCI6XCIxMzbilqfilqfilqfilqcxOTQzXCIsXCJtb2RpZnl0aW1lXCI6XCIyMDI0LTExLTE1IDE3OjI4OjA1XCIsXCJuYW1lXCI6XCLlkajmiJDkuJztoL3tuI1cIixcInN0YXRlXCI6MSxcInVpZFwiOjEwNzEzMDAyMyxcInVzZXJUeXBlXCI6MH0ifQ=="));
    }
}