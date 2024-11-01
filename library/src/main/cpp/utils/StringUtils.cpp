//
// Created by 周成东 on 2024/10/24.
//

#include "../include/utils/StringUtils.h"
#include "../utils/CommonStringUtils.h"

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
    return str.find(subStr) != string::npos;

}

bool StringUtils::isNumeric(const string &str) {
    return CommonStringUtils::isRegexMatch(str, "^[0-9]*$");

}

bool StringUtils::isDate(const string &str) {
    return CommonStringUtils::isRegexMatch(
            str,
            "^((\\d{2}(([02468][048])|([13579][26]))[\\-\\/\\s]?((((0?[13578])|(1[02]))[\\-\\/\\s]?((0?[1-9])|([1-2][0-9])|(3[01])))|(((0?[469])|(11))[\\-\\/\\s]?((0?[1-9])|([1-2][0-9])|(30)))|(0?2[\\-\\/\\s]?((0?[1-9])|([1-2][0-9])))))|(\\d{2}(([02468][1235679])|([13579][01345789]))[\\-\\/\\s]?((((0?[13578])|(1[02]))[\\-\\/\\s]?((0?[1-9])|([1-2][0-9])|(3[01])))|(((0?[469])|(11))[\\-\\/\\s]?((0?[1-9])|([1-2][0-9])|(30)))|(0?2[\\-\\/\\s]?((0?[1-9])|(1[0-9])|(2[0-8]))))))(\\s(((0?[0-9])|([1-2][0-3]))\\:([0-5]?[0-9])((\\s)|(\\:([0-5]?[0-9])))))?$");
}

bool StringUtils::isValidateIdCard(const string &str) {
    return CommonStringUtils::isRegexMatch(str, "^(\\d{17}[0-9Xx])|(\\d{15})$");
}

string StringUtils::replacePhone(const string &str) {
    if (!str.empty()) {
        std::regex pattern("(\\d{3})\\d{4}(\\d{4})");
        return std::regex_replace(str, pattern, "$1▧▧▧▧$2");
    }
    return "";
}

bool StringUtils::isPassword(const string &str) {
    return CommonStringUtils::isRegexMatch(str, "(?=.*?[a-zA-Z])(?=.*?[0-9])[a-zA-Z0-9]{6,12}$");
}

bool StringUtils::isEmail(const string &str) {
    return CommonStringUtils::isRegexMatch(str, "^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
}

bool StringUtils::isPhone(const string &str) {
    return CommonStringUtils::isRegexMatch(str, "^((13[0-9])|(15[^4,\\D])|(18[0,5-9]))\\d{8}$");
}





