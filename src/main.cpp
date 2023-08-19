#include "header.h"
#include "commands/commands.h"
#include "process_arguments/process_args.h"
#include "errors/errors.h"

int main(int argc, char* argv[]) {
    std::map<std::string, std::string> commands;
    commands["info"] = "Show all the information about the program.";

    return command_handler::process(argc, argv, commands);
}