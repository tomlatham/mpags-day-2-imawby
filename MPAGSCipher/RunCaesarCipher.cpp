#include <string>
#include <vector>

#include "RunCaesarCipher.hpp"

std::string runCaesarCipher(const std::string& initialString, unsigned long key, const bool isEncryptMode){

  const std::vector<char> alphabet = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
  const size_t alphabetSize = alphabet.size();

  std::string cipheredString{""};
  int index;

  if(!isEncryptMode)
    key *= -1;
  
  for(const char letter : initialString){
    for(size_t i{0}; i < alphabetSize; ++i){
      if(letter == alphabet[i]){
        index = i + key;
        break;
      }
    } 
     
    if(index < 0){
      cipheredString += alphabet[alphabetSize - (abs(index) % alphabetSize)];
      continue;
    }

    cipheredString += alphabet[index % alphabetSize];
  }
    
  return cipheredString;
}
    
