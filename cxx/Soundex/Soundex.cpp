#include "Soundex.h"

std::string Soundex::encode(const std::string& word) const {
    return zeroPad(word);
}

std::string Soundex::zeroPad(const std::string& word) const {
    return word + "000";
}
