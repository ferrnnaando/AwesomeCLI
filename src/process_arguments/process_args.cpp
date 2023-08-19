#include "process_args.h"

int command_handler::process(int& argc, char* argv[], std::map<std::string, std::string>& commands) {
    switch(argc) {
        case 1:
            return errors::custom("Please, enter a command. May you mean --help?");
            //std::cout << "this should not work"; On effects, doesn't prints.
        
        default:
            if(argc >= 2) {
                std::string entered_command = std::string(argv[1]);
                if(commands.find(entered_command) == commands.end()) {
                    return errors::custom("The entered command does not exists. Take a look to --help.");
                } 
                else {
                    auto searchCmd = commands.find(entered_command);
                    if(searchCmd->first == "info") /*what is swap and second*/{
                        return commands::info();
                    }
                }
            }
    }

    return 0;
}