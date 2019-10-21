#ifndef MPAGS_CIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGS_CIPHER_PROCESSCOMMANDLINE_HPP

#include <string>
#include <vector>

bool processCommandLine(const std::vector<std::string>& cmdLineArgs, bool& helpRequested, bool& versionRequested, std::string& inputFileName, std::string& outputFileName);

#endif // MPAGS_CIPHER_PROCESSCOMMANDLINE_HPP
