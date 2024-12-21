add_library(Soundex SHARED Soundex.cpp)

target_include_directories(Soundex PUBLIC include)

add_subdirectory(Tests)
