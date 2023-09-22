#ifndef UTILS_H
#define UTILS_H

#include <string>

namespace utils {
    std::string convertBytesToHex(std::string bytes);
    std::string convertHexToBytes(std::string bytes);
    std::string toUpper(std::string inputStr);
    std::string toLower(std::string inputStr);
}

#endif