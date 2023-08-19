#include "errors.h"

int errors::custom(std::string error_message, std::string &error_msg) {
    std::cerr << error_msg << error_message << std::endl;
    return -1;
}