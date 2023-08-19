#include "commands.h"

int commands::version() {
    std::string ANSI_BOLD = "\033[1m";
    std::string ANSI_UNDERLINE = "\033[4m";
    std::string ITALIC = "\033[3m";
    std::string ANSI_BLUE = "\033[34m";
    std::string ANSI_GREEN = "\033[32m";
    std::string ANSI_RESET = "\033[0m";
    std::cout << std::endl;
    std::cout << ANSI_BOLD << ANSI_GREEN << "AwesomeCLI 3.0" << ANSI_RESET << std::endl << std::endl;
    std::cout << "  * Author: " << ANSI_BLUE << ITALIC << "@ferrnnaando" << ANSI_RESET << "," << std::endl;
    std::cout << "  * 3.0 surged as a hardware usage improvement and code reestructuration, please check GitHub for the past version very much slower and bad-coded." << std::endl << std::endl;
    return 0;
}

int commands::help() {
    std::string ANSI_BOLD = "\033[1m";
    std::string ANSI_UNDERLINE = "\033[4m";
    std::string ITALIC = "\033[3m";
    std::string ANSI_BLUE = "\033[34m";
    std::string ANSI_GREEN = "\033[32m";
    std::string ANSI_RESET = "\033[0m";
    std::cout << std::endl;
    std::cout << ANSI_BOLD << ANSI_GREEN << "AwesomeCLI 3.0" << ANSI_RESET << std::endl << std::endl;
    std::cout << "  * Author: " << ANSI_BLUE << ITALIC << "@ferrnnaando" << ANSI_RESET << "," << std::endl;
    std::cout << "  * 3.0 surged as a hardware usage improvement and code reestructuration, please check GitHub for the past version very much slower and bad-coded." << std::endl << std::endl;
    return 0;
}