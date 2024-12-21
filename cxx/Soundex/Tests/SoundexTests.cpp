#include "gmock/gmock.h"

#include "Soundex.h"

using namespace testing;

class SoundexEncoding: public Test {
public:
    Soundex soundex;
};

TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
    ASSERT_THAT(soundex.encode("a"), Eq("a000"));
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits) {
    ASSERT_THAT(soundex.encode("I"), Eq("I000"));
}

TEST_F(SoundexEncoding, ReplaceConsonantsWithAppropriateDigits) {
    EXPECT_THAT(soundex.encode("Abcd"), Eq("A123"));
    EXPECT_THAT(soundex.encode("Afgt"), Eq("A123"));
    EXPECT_THAT(soundex.encode("Apjl"), Eq("A124"));
    EXPECT_THAT(soundex.encode("Avkm"), Eq("A125"));
    EXPECT_THAT(soundex.encode("Aqnr"), Eq("A256"));
    EXPECT_THAT(soundex.encode("As"), Eq("A200"));
    EXPECT_THAT(soundex.encode("Ax"), Eq("A200"));
    EXPECT_THAT(soundex.encode("Az"), Eq("A200"));
}

TEST_F(SoundexEncoding, LimitLengthToFourCharacters) {
    EXPECT_THAT(soundex.encode("Abcdf").length(), Eq(4u));
}

TEST_F(SoundexEncoding, IgnoresVowelLikeLetters) {
    ASSERT_THAT(soundex.encode("Baeiouhycdl"), Eq("B234"));
}

TEST_F(SoundexEncoding, CombinesDuplicateEncodings) {
    ASSERT_THAT(soundex.encode("Abfcgdt"), Eq("A123"));
}

TEST_F(SoundexEncoding, IgnoreCaseForConsonantsToDigitConversion) {
    EXPECT_THAT(soundex.encode("Abcd"), Eq("A123"));
    EXPECT_THAT(soundex.encode("ABCD"), Eq("A123"));
}

TEST_F(SoundexEncoding, DoNotCombineDuplicateEncodingsSeperatedByVowels) {
    EXPECT_THAT(soundex.encode("Jbob"), Eq("J110"));
    //make sure it also work if vowel is upper case
    EXPECT_THAT(soundex.encode("JbOb"), Eq("J110"));
}

int main(int argc, char** argv) {
    InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
