#include "header.h"
#include <string>

bool startsWith(const char* argv, const char* prefix) {
    std::string command(argv);
    std::string prefixC(prefix);

    return (command.substr(0, prefixC.length()) == prefixC);
}