//
// Created by 周成东 on 2024/10/24.
//
#include <iostream>

#ifndef ATOURLIFE_ANDROID_STRINGUTILS_H
#define ATOURLIFE_ANDROID_STRINGUTILS_H

#include <regex>
using namespace std;

class StringUtils {
public:
    // 拼接两个字符串
    static string concat(const std::string &str1, const std::string &str2);

    // 在字符串中查找子串
    static int find(const std::string &str, const std::string &subStr);

    // 判断字符串是否为空
    static bool isEmpty(const string &str);

    // 判断字符串是否只包含空格
    static bool isOnlySpaces(const string &str);

    // 判断字符串是否包含某个子串
    static bool contains(const string &str, const string &subStr);

    //是否是数字
    static bool isNumeric(const string &str);

    //是否是日期
    static bool isDate(const string &str);

    //身份证是否有效
    static bool isValidateIdCard(const string &str);

    //字符串加密
    static string replacePhone(const string &str);

    //是否是密码
    static bool isPassword(const string &str);

    //是否是邮箱
    static bool isEmail(const string &str);
    //是否是电话号码
    static bool isPhone(const string &str);




};


#endif //ATOURLIFE_ANDROID_STRINGUTILS_H
