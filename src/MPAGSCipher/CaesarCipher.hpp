#ifndef CAESARCIPHER_HPP
#define CAESARCIPHER_HPP

#include <string>
#include <vector>
#include <CipherMode.hpp>

class CaesarCipher{
    public:
        explicit CaesarCipher(std::size_t key);
        explicit CaesarCipher(std::string key);
        std::string applyCipher(std::string inputText, CipherMode mode);
    private:
        std::size_t key_;
        const std::vector<char> alphabet_ = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};


};



#endif