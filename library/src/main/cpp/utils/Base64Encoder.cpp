//
// Created by 周成东 on 2024/10/28.
//

#include "../include/utils/Base64Encoder.h"

void Base64Encoder::write(int b) {
    if (b < 0) {
        b += 256;
    }

    if (charCount % 3 == 0) {
        int lookup = b >> 2;
        carryOver = b & 3;
        outStream << base64_chars[lookup];
    } else if (charCount % 3 == 1) {
        int lookup = ((carryOver << 4) + (b >> 4)) & 63;
        carryOver = b & 15;
        outStream << base64_chars[lookup];
    } else if (charCount % 3 == 2) {
        int lookup = ((carryOver << 2) + (b >> 6)) & 63;
        outStream << base64_chars[lookup];
        lookup = b & 63;
        outStream << base64_chars[lookup];
        carryOver = 0;
    }
    charCount++;

    if (charCount % 57 == 0) {
        outStream << '\n';
    }
}

void Base64Encoder::write(const std::vector<char> &buf) {
    for (char c: buf) {
        write(static_cast<int>(c));
    }
}

void Base64Encoder::close() {
    if (charCount % 3 == 1) {
        int lookup = (carryOver << 4) & 63;
        outStream << base64_chars[lookup];
        outStream << "==";
    } else if (charCount % 3 == 2) {
        int lookup = (carryOver << 2) & 63;
        outStream << base64_chars[lookup];
        outStream << '=';
    }
}

std::string Base64Encoder::encode(const vector<char> &bytes) {
    std::stringstream out;
    Base64Encoder encoder(out);

    encoder.write(bytes);
    encoder.close();

    return out.str();
}
 std::string Base64Encoder::encode(const std::string &unencoded) {
    std::vector<char> bytes(unencoded.begin(), unencoded.end());
    return encode(bytes);
}


