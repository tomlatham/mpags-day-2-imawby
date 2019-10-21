#include <string>
#include <cctype>

#include "TransformChar.hpp"

std::string transformChar(const char inputChar)
{

  std::string encryptedText;
  // Uppercase alphabetic characters
  if (std::isalpha(inputChar))
    {
      encryptedText += std::toupper(inputChar);

    }

  // Transliterate digits to English words
  switch (inputChar) {
  case '0':
    encryptedText += "ZERO";
    break;
  case '1':
    encryptedText += "ONE";
    break;
  case '2':
    encryptedText += "TWO";
    break;
  case '3':
    encryptedText += "THREE";
    break;
  case '4':
    encryptedText += "FOUR";
    break;
  case '5':
    encryptedText += "FIVE";
    break;
  case '6':
    encryptedText += "SIX";
    break;
  case '7':
    encryptedText += "SEVEN";
    break;
  case '8':
    encryptedText += "EIGHT";
    break;
  case '9':
    encryptedText += "NINE";
    break;
  }


  return encryptedText;

}
