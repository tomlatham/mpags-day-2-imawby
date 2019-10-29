// Standard Library includes
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// Our project headers
#include "TransformChar.hpp"
#include "ProcessCommandLine.hpp"
#include "RunCaesarCipher.hpp"

// For std::isalpha and std::isupper
#include <cctype>

// Main function of the mpags-cipher program
int main(int argc, char* argv[])
{
  // Convert the command-line arguments into a more easily usable form
  const std::vector<std::string> cmdLineArgs {argv, argv+argc};

  // Options that might be set by the command-line arguments
  bool helpRequested {false};
  bool versionRequested {false};
  bool cipherModeGiven{false};
  bool keyGiven{false};
  unsigned long key{0};
  bool isEncryptMode{false};

  std::string inputFileName {""};
  std::string outputFileName {""};
  std::ifstream inputFile;
  std::ofstream outputFile;

  if(processCommandLine(cmdLineArgs, helpRequested, versionRequested, inputFileName, outputFileName, keyGiven, cipherModeGiven, key, isEncryptMode))
    return 1;

  // Handle help, if requested
  if (helpRequested) {
    // Line splitting for readability
    std::cout
      << "Usage: mpags-cipher [-i <file>] [-o <file>]\n\n"
      << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
      << "Available options:\n\n"
      << "  -h|--help        Print this help message and exit\n\n"
      << "  --version        Print version information\n\n"
      << "  -k KEY           Key for Caesar cipher"
      << "  --encrypt        Use Caesar cipher in encrypt mode"
      << "  --decrypt        Use Caesar cipher in decrypt mode"
      << "  -i FILE          Read text to be processed from FILE\n"
      << "                   Stdin will be used if not supplied\n\n"
      << "  -o FILE          Write processed text to FILE\n"
      << "                   Stdout will be used if not supplied\n\n";
    // Help requires no further action, so return from main
    // with 0 used to indicate success
    return 0;
  }

  // Handle version, if requested
  // Like help, requires no further action,
  // so return from main with zero to indicate success
  if (versionRequested) {
    std::cout << "0.1.0" << std::endl;
    return 0;
  }

  if(!cipherModeGiven && !keyGiven){
    std::cout << "Cipher mode and key have not been given" << std::endl;
    return 1;
  }

  if(!cipherModeGiven){
    std::cout << "Cipher mode has not been given" << std::endl;
    return 1;
  }

  if(!keyGiven){
    std::cout << "Key has not been declared" << std::endl;
    return 1;
  }

  // Initialise variables for processing input text
  char inputChar {'x'};
  std::string inputString {""};

  if (!inputFileName.empty()) {
    inputFile.open(inputFileName);
    if(inputFile.good()){   
      while(inputFile >> inputChar)
        {
          inputString += transformChar(inputChar);
        }
    } else {
      return 1;
    }
    inputFile.close();
  } else {
    while(std::cin >> inputChar)
      {
	inputString += transformChar(inputChar);
      }
  } 

  std::string cipheredString{""};

  cipheredString = runCaesarCipher(inputString, key, isEncryptMode);

  // Output the transliterated text
  if (!outputFileName.empty()) {
    outputFile.open(outputFileName);
    if(outputFile.good()){ 
      outputFile << cipheredString;
    } else {
      return 1;
    }
    outputFile.close();
  } else {
    std::cout << cipheredString << std::endl;
  }


  // No requirement to return from main, but we do so for clarity
  // and for consistency with other functions
  return 0;
}
