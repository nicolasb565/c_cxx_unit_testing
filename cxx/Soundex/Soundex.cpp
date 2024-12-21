#include <unordered_map>
#include <algorithm>
#include <cctype>

#include "Soundex.h"

std::string Soundex::encode(const std::string& word) const {
    return zeroPad(head(word) + encodedDigits(word));
}

std::string Soundex::head(const std::string& word) const {
    return word.substr(0, 1);
}

std::string Soundex::encodedDigit(char letter) const {
    const std::unordered_map<char, std::string> encodings {
        {'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"},
        {'c', "2"}, {'g', "2"}, {'j', "2"}, {'k', "2"}, {'q', "2"}, {'s', "2"}, {'x', "2"}, {'z', "2"},
        {'d', "3"}, {'t', "3"},
        {'l', "4"},
        {'m', "5"}, {'n', "5"},
        {'r', "6"}
    };
    
    auto it = encodings.find(std::tolower(letter));
    if(it != encodings.end()) {
        return it->second;
    }
    return "";
}

bool Soundex::isVowel(char letter) const {
    return letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u';
}

std::string Soundex::encodedDigits(const std::string& word) const {
    size_t index = 1;
    std::string ret;
    do {
        std::string digit = encodedDigit(word[index]);
        if(ret.length() == 0 || (digit.length() > 0 && digit[0] != ret.back())) {
            ret.append(digit);
        }
        else if(isVowel(std::tolower(word[index - 1]))) {
            ret.append(digit);
        }
        index++;
    } while(ret.length() < 3 && index < word.length());
    return ret;
}

std::string Soundex::zeroPad(const std::string& word) const {
    auto zerosNeeded = MaxCodeLength - std::min(word.length(), MaxCodeLength);
    return word + std::string(zerosNeeded, '0');
}
