#include "utils.hpp"
#include <cstdint>
#include <cstring>

std::string utils::convertBytesToHex(std::string byteStr)
{
    unsigned char hex_chars[]= "0123456789abcdef";
    std::string hexStr = "";

    for ( std::string::iterator it=byteStr.begin(); it!=byteStr.end(); ++it)
    {
        hexStr += hex_chars[(it[0] & 0xF0) >> 4];
        hexStr += hex_chars[it[0] & 0xF];
    }
    
    return hexStr;
}

std::string utils::toLower(std::string inputStr)
{
    std::string lowerStr = "";

    for ( std::string::iterator it=inputStr.begin(); it!=inputStr.end(); ++it)
    {
        lowerStr += std::tolower(it[0]);
    }

    return lowerStr;
}

std::string utils::toUpper(std::string inputStr)
{
    std::string upperStr = "";

    for ( std::string::iterator it=inputStr.begin(); it!=inputStr.end(); ++it)
    {
        upperStr += std::toupper(it[0]);
    }

    return upperStr;
}
std::string utils::convertHexToBytes(std::string hexStr)
{
    uint8_t hex_chars[0xFF] = { 0 };
    memset(hex_chars, 0, sizeof(hex_chars));
    hex_chars['0'] = 0x0;
    hex_chars['1'] = 0x1;
    hex_chars['2'] = 0x2;
    hex_chars['3'] = 0x3;
    hex_chars['4'] = 0x4;
    hex_chars['5'] = 0x5;
    hex_chars['6'] = 0x6;
    hex_chars['7'] = 0x7;
    hex_chars['8'] = 0x8;
    hex_chars['9'] = 0x9;
    hex_chars['A'] = hex_chars['a'] = 0xA;
    hex_chars['B'] = hex_chars['b'] = 0xB;
    hex_chars['C'] = hex_chars['c'] = 0xC;
    hex_chars['D'] = hex_chars['d'] = 0xD;
    hex_chars['E'] = hex_chars['e'] = 0xE;
    hex_chars['F'] = hex_chars['f'] = 0xF;

    std::string byteStr = "";

    for ( std::string::iterator it=hexStr.begin(); it!=hexStr.end(); it += 2)
    {
        char byte = (hex_chars[(uint8_t) it[0]] << 4) + hex_chars[(uint8_t)it[1]];
        byteStr += byte;
    }
    

    return byteStr;
}