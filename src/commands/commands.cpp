#include "commands.h"

int commands::info() {
    std::string ANSI_BOLD = "\033[1m";
    std::string ANSI_UNDERLINE = "\033[4m";
    std::string ITALIC = "\033[3m";
    std::string ANSI_BLUE = "\033[34m";
    std::string ANSI_GREEN = "\033[32m";
    std::cout << ANSI_BOLD << ANSI_UNDERLINE << ANSI_GREEN << "AwesomeCLI 3.0";
    return 1;
}