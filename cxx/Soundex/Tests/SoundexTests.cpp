#include "gmock/gmock.h"

#include "Soundex.h"

using namespace testing;

TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
    Soundex soundex;
    std::string encoded = soundex.encode("A");
    ASSERT_THAT(encoded, Eq("A000"));
}

TEST(SoundexEncoding, PadsWithZerosToEnsureThreeDigits) {
    Soundex soundex;
    std::string encoded = soundex.encode("I");
    ASSERT_THAT(encoded, Eq("I000"));
}

int main(int argc, char** argv) {
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
