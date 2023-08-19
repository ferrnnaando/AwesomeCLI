#include "header.h"
#include "commands/commands.h"
#include "command_handler/command_handler.h"
#include "errors/errors.h"

void detect_program_name(char* argv[]) {
    #ifdef __APPLE__
        char* filename = basename(const_cast<char*>(argv[0]));
        std::cout << filename;
    #endif
}

int main(int argc, char* argv[]) {
    detect_program_name(argv);
    std::string ANSI_RED = "\033[31m";
    std::string error = ANSI_RED + "Error: ";

    std::map<std::string, std::string> commands;
    commands["version"] = "Display basic information about AwesomeCLI.";
    commands["help"] = "Display util help about all the avaiable commands.";

    std::cout << commands["version"];
    //TODO: Add your own commands

    return command_handler::process(argc, argv, commands, error);
}