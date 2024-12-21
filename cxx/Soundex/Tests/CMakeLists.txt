add_executable(SoundexTests SoundexTests.cpp)

target_compile_options(SoundexTests PRIVATE ${LIBGMOCK_CFLAGS})
target_link_libraries(SoundexTests PRIVATE Soundex ${LIBGMOCK_LIBRARIES})

add_test(NAME SoundexTests COMMAND $<TARGET_FILE:SoundexTests>)
