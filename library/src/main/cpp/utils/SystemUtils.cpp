//
// Created by Peakmain on 2024/11/1.
//

#include "../include/utils/SystemUtils.h"
#include <sys/system_properties.h>

string getSystemProperty(const string &key, const string &defaultValue = "unknown") {
    const prop_info *prop = __system_property_find(key.c_str());
    if (prop != nullptr) {
        char value[PROP_VALUE_MAX];
        char name[PROP_VALUE_MAX];  // 新增字符数组以存储属性名称
        if (__system_property_read(prop, name, value) > 0) {
            return std::string(value);
        }
    }
    return defaultValue;
}

string SystemUtils::getDeviceSystemVersion() {
    return getSystemProperty("ro.build.version.release");
}

string SystemUtils::getBrand() {
    return getSystemProperty("ro.product.brand");
}
