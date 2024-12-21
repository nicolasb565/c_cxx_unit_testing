#include <algorithm>
#include <cctype>

#include "Soundex.h"

char consonantToDigit(char character) {
    switch(character) {
    case 'b':
    case 'f':
    case 'p':
    case 'v':
        return '1';
    case 'c':
    case 'g':
    case 'j':
    case 'k':
    case 'q':
    case 's':
    case 'x':
    case 'z':
        return '2';
    case 'd':
    case 't':
        return '3';
    case 'l':
        return '4';
    case 'm':
    case 'n':
        return '5';
    case 'r':
        return '6';
    default:
        break;
    }
    return '\0';
}

bool isVowel(char c) {
    switch(c) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'y':
        return true;
    default:
        break;
    }
    return false;
}

std::string Soundex::encode(std::string str) {
    return str + "000";
}
