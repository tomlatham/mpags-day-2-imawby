#include <vector>
#include <string>
#include <iostream>

#include "ProcessCommandLine.hpp"

bool processCommandLine(const std::vector<std::string>& cmdLineArgs, bool& helpRequested, bool& versionRequested, std::string& inputFileName, std::string& outputFileName, bool& keyGiven, bool& cipherModeGiven, unsigned long& key, bool& isEncryptMode){

  // Add a typedef that assigns another name for the given type for clarity
  typedef std::vector<std::string>::size_type size_type;
  const size_type nCmdLineArgs {cmdLineArgs.size()};

  // Process command line arguments - ignore zeroth element, as we know this to
  // be the program name and don't need to worry about it
  for (size_type i {1}; i < nCmdLineArgs; ++i) {

    if (cmdLineArgs[i] == "-h" || cmdLineArgs[i] == "--help") {
      helpRequested = true;
    }
    else if (cmdLineArgs[i] == "--version") {
      versionRequested = true;
    }
    else if(cmdLineArgs[i] == "--encrypt"){
      cipherModeGiven = true;
      isEncryptMode = true;
    }
    else if(cmdLineArgs[i] == "--decrypt"){
      cipherModeGiven = true;
      isEncryptMode = false;
    }
    else if (cmdLineArgs[i] == "-i") {
      // Handle input file option
      // Next element is filename unless -i is the last argument
      if (i == nCmdLineArgs-1) {
	std::cerr << "[error] -i requires a filename argument" << std::endl;
        return 1;
      }
      else {
        // Got filename, so assign value and advance past it
        inputFileName = cmdLineArgs[i+1];
        ++i;
      }
    }
    else if (cmdLineArgs[i] == "-o") {
      // Handle output file option
      // Next element is filename unless -o is the last argument
      if (i == nCmdLineArgs-1) {
	std::cerr << "[error] -o requires a filename argument" << std::endl;
        return 1;
      }
      else {
        // Got filename, so assign value and advance past it
        outputFileName = cmdLineArgs[i+1];
        ++i;
      }
    }
    else if (cmdLineArgs[i] == "-k") {
      // Handle caesar cipher key option
      // Next element is key unless -k is the last argument
      if (i == nCmdLineArgs-1) {
	std::cerr << "[error] -k requires a key argument" << std::endl;
        return 1;
      }
      else {
        // Got key, so assign value and advance past it
	keyGiven = true;
        key = std::stol(cmdLineArgs[i+1]);
        ++i;
      }
    }
    else {
      // Have an unknown flag to output error message and return non-zero
      // exit status to indicate failure
      std::cerr << "[error] unknown argument '" << cmdLineArgs[i] << "'\n";
      return 1;
    }
  }
  return 0;
}


