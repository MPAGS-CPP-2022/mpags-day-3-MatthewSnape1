#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "CaesarCipher.hpp"
#include "CipherMode.hpp"

TEST_CASE("encryption is applied, [alphanumeric]"){
    const std::string abc{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    const size_t size = abc.size();
    std::string res{""};
    size_t shift{0};
    CipherMode mode = CipherMode::encrypt;
    for (size_t key = 0 ; key < 25 ; key++){
        CaesarCipher test(key);
        for (size_t i = 1 ; i < size ; i++ ){
            shift = ( i + key ) % size;
            std::string input {abc[i]};
            res = test.applyCipher(input , mode);
            std::string exp{abc[shift]};
            REQUIRE( res == exp );            
        }       
    }
}

TEST_CASE("decryption is applied, [alphanumeric]"){
    const std::string abc{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    const size_t size = abc.size();
    std::string res{""};
    size_t shift{0};
    CipherMode mode = CipherMode::decrypt;
    for (size_t key = 0 ; key < 25 ; key++){
        CaesarCipher test(key);
        for (size_t i = 0 ; i < size ; i++ ){
            shift = ( i + size - key ) % size;
            std::string input {abc[i]};
            res = test.applyCipher(input , mode);
            std::string comp{abc[shift]};
            REQUIRE( res == comp );            
        }       
    }
}