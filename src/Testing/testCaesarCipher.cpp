#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "CaesarCipher.hpp"
#include "CipherMode.hpp"

TEST_CASE("CaesarCipher Works, [alphanumeric]"){
    const std::string abc{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    const size_t size = abc.size();
    std::string res{""};
    size_t shift{0};
    std::string input {""};

    SECTION("Encryption is applied, [alphanumeric]"){
    CipherMode en = CipherMode::encrypt;
    for (size_t key = 0 ; key < 25 ; key++){
        CaesarCipher test(key);
        for (size_t i = 1 ; i < size ; i++ ){
            shift = ( i + key ) % size;
            input = {abc[i]};
            res = test.applyCipher(input , en);
            std::string exp{abc[shift]};
            REQUIRE( res == exp );            
        }     
    }

    SECTION("Decryption is applied, [alphanumeric]"){
    CipherMode dec = CipherMode::decrypt;
    for (size_t key = 0 ; key < 25 ; key++){
        CaesarCipher test(key);
        for (size_t i = 1 ; i < size ; i++ ){
            shift = ( i + size - key ) % size;
            input = {abc[i]};
            res = test.applyCipher(input , dec);
            std::string exp{abc[shift]};
            REQUIRE( res == exp );            
        }     
    }

    }
}

}


