#pragma once
#include "../header.h"

class errors {
    public:
        static int custom(std::string error_message, std::string &error_msg);
};