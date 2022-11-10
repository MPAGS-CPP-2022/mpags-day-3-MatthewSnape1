# - Most basic test

add_executable(testHello testHello.cpp)
add_test(NAME test-hello COMMAND testHello)

# - creat interface library for catch

add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CMAKE_CURRENT_LIST_DIR})
target_compile_features(Catch INTERFACE cxx_noexcept)

# - First catch based test

add_executable(testCatch testCatch.cpp)
target_link_libraries(testCatch Catch)
add_test(NAME test-Catch COMMAND testCatch)

# - test transformChar
add_executable(testTransformChar testTransformChar.cpp)
target_link_libraries(testTransformChar MPAGSCipher Catch)
add_test(NAME test-transformchar COMMAND testTransformChar)

# - test CaesarCipher
add_executable(testCaesarCipher testCaesarCipher.cpp)
target_link_libraries(testCaesarCipher MPAGSCipher Catch)
add_test(NAME test-caesarcipher COMMAND testCaesarCipher)

# - test CaesarCipher
add_executable(testCommandLine testCommandLine.cpp)
target_link_libraries(testCommandLine MPAGSCipher Catch)
add_test(NAME test-commandline COMMAND testCommandLine)