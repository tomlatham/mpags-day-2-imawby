#ifndef MPAGSCIPHER_RUNCAESARCIPHER_HPP
#define MPAGSCIPHER_RUNCAESARCIPHER_HPP

#include <string>
#include <vector>

std::string runCaesarCipher(const std::string& initialString, const unsigned long key, const bool isEncryptMode);

#endif // MPAGSCIPHER_RUNCAESARCIPHER_HPP
