#include "../include/utils/Base64Decoder.h"

// Base64 字符表
const char Base64Decoder::base64_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

void Base64Decoder::write(char b) {
    if (b == '=' || b < 0 || b > 127) {
        return; // 跳过填充或无效字符
    }

    int value = -1;

    // 查找字符对应的值
    for (int i = 0; i < 64; i++) {
        if (base64_chars[i] == b) {
            value = i;
            break;
        }
    }

    if (value == -1) {
        throw std::invalid_argument("Invalid Base64 character");
    }

    charCount++;

    // 处理解码逻辑
    if (charCount % 4 == 1) {
        carryOver = value;
    } else if (charCount % 4 == 2) {
        outStream << static_cast<char>((carryOver << 2) | (value >> 4));
        carryOver = value & 15;
    } else if (charCount % 4 == 3) {
        outStream << static_cast<char>((carryOver << 4) | (value >> 2));
        carryOver = value & 3;
    } else if (charCount % 4 == 0) {
        outStream << static_cast<char>((carryOver << 6) | value);
    }
}

void Base64Decoder::close() {
    // 如果还剩余的字符，进行处理
    if (charCount % 4 == 2) {
        outStream << static_cast<char>(carryOver << 2);
    } else if (charCount % 4 == 3) {
        outStream << static_cast<char>((carryOver << 4));
    }
}

std::string Base64Decoder::decode(const std::string &encoded) {
    for (char c : encoded) {
        write(c);
    }
    close();
    return outStream.str();
}
