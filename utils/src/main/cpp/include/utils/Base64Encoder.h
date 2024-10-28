//
// Created by 周成东 on 2024/10/28.
//

#ifndef ATOURLIFE_ANDROID_BASE64ENCODER_H
#define ATOURLIFE_ANDROID_BASE64ENCODER_H
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
using namespace std;
const char base64_chars[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
                             'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b',
                             'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
                             'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3',
                             '4', '5', '6', '7', '8', '9', '+', '/'};

class Base64Encoder {
public:
    ostream &outStream;
    int charCount;
    int carryOver;

    Base64Encoder(ostream &out) : outStream(out), charCount(0), carryOver(0) {}

    void write(int b);

    void write(const vector<char> &buf);
    void close();

    static string encode(const std::string &unencoded);
    static std::string encode(const std::vector<char> &bytes);

};

#endif //ATOURLIFE_ANDROID_BASE64ENCODER_H
