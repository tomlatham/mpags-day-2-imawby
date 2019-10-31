#include <string>
#include <vector>

#include "RunCaesarCipher.hpp"

std::string runCaesarCipher(const std::string& initialString, const unsigned long key, const bool isEncryptMode){

  const std::vector<char> alphabet = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
  const size_t alphabetSize = alphabet.size();

  std::string cipheredString{""};

  const unsigned long truncatedKey { key % alphabetSize };

  for(const char letter : initialString){
    for(size_t i{0}; i < alphabetSize; ++i){
      if(letter == alphabet[i]){
        if ( isEncryptMode ) {
          cipheredString += alphabet[(i + truncatedKey) % alphabetSize];
        } else {
          cipheredString += alphabet[(alphabetSize + i - truncatedKey) % alphabetSize];
        }
        break;
      }
    } 
  }

  /*
  const unsigned long truncatedKey { isEncryptMode ? key % alphabetSize : alphabetSize - (key % alphabetSize) };

  for(const char letter : initialString){
    for(size_t i{0}; i < alphabetSize; ++i){
      if(letter == alphabet[i]){
        cipheredString += alphabet[(i + truncatedKey) % alphabetSize];
        break;
      }
    } 
  }
  */

  return cipheredString;
}
    
