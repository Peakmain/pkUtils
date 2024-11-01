#ifndef BASE64DECODER_H
#define BASE64DECODER_H

#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>

class Base64Decoder {
public:
    Base64Decoder() = default; // 默认构造函数
    std::string decode(const std::string &encoded);

private:
    void write(char b);
    void close();

    std::stringstream outStream;
    int charCount = 0;
    int carryOver = 0;
    static const char base64_chars[];
};

#endif // BASE64DECODER_H
