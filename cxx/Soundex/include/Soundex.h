#pragma once

#include <string>

class Soundex {
public:
    std::string encode(const std::string& word) const;
private:
    static constexpr size_t MaxCodeLength = 4;
    std::string head(const std::string& word) const;
    std::string encodedDigits(const std::string& word) const;
    std::string encodedDigit(char letter) const;
    std::string zeroPad(const std::string& word) const;
    bool isVowel(char letter) const;
};
