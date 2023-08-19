#include "errors.h"

int errors::custom(std::string error_message) {
    std::string ANSI_RED = "\033[31m";
    std::string error = ANSI_RED + "Error: ";
    std::cerr << error << error_message << std::endl;
    return -1;
}