#include "header.h"
#include "commands/commands.h"
#include "command_handler/command_handler.h"
#include "errors/errors.h"

int main(int argc, char* argv[]) {
    std::string ANSI_RED = "\033[31m";
    std::string error = ANSI_RED + "Error: ";

    std::map<std::string, std::string> commands;
    commands["info"] = "Show all the information about the program.";

    return command_handler::process(argc, argv, commands, error);
}