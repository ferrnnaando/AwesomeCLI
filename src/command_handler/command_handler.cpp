#include "command_handler.h"

int command_handler::process(int& argc, char* argv[], std::map<std::string, std::string>& commands, std::string &error_command) {
    switch(argc) {
        case 1:
            return errors::custom("Please, enter a command. May you mean --help?", error_command);
            //std::cout << "this should not work"; On effects, doesn't prints.
        
        default:
            if(argc >= 2) {
                std::string entered_command = std::string(argv[1]);
                if(commands.find(entered_command) == commands.end()) {
                    return errors::custom("The entered command does not exists. Take a look to --help.", error_command);
                } 
                else {
                    auto searchCmd = commands.find(entered_command);
                    if(searchCmd->first == "--version") /*what is swap and second*/{
                        return commands::version();
                    } else if(searchCmd->first == "--help") {
                        return commands::help();
                    }
                }
            }
    }

    return 0;
}