//
// Created by 周成东 on 2024/10/24.
//

#include "../include/utils/StringUtils.h"

/**
 * 拼接两个字符串
 * @param str1
 * @param str2
 * @return
 */
string StringUtils::concat(const string &str1, const string &str2) {
    return str1 + str2;
}

/**
 在字符串中查找子串

 * @param str
 * @param subStr
 * @return
 */
int StringUtils::find(const string &str, const string &subStr) {
    size_t pos = str.find(subStr);
    if (pos != string::npos) {
        return static_cast<int>(pos);
    }
    return -1;
}


bool StringUtils::isEmpty(const std::string &str) {
    return str.empty();
}

//判断字符串是否只包含空格
bool StringUtils::isOnlySpaces(const string &str) {
    for (char c: str) {
        if (c != ' ') {
            return false;
        }
    }
    return true;
}

//判断字符串是否包含某个子串
bool StringUtils::contains(const string &str, const string &subStr) {
    return str.find(subStr) != std::string::npos;

}
