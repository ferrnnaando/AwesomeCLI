#pragma once
#include "../header.h"
#include "../errors/errors.h"
#include "../commands/commands.h"

class command_handler {
    public:
        static int process(int& argc, char* argv[], std::map<std::string, std::string>& commands);
};