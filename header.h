#include <iostream>
#include <fstream>
#include <string>

#ifdef _WIN32
    #include <conio.h>
    #include <windows.h>

#else
    #include <unistd.h>
    #include <chrono>
    #include <thread>
#endif

namespace prefix {
    namespace help {
        std::string long_prefix = "--";
    }

    namespace command {
        std::string command = "-";
    }
}
namespace commands {
    namespace description {
        std::string search_description = "Searchs for the specified text in the specified file text.";
        const char* search_help_description = "Help for --search subcommand: \n"
                            "Usage: -search <file_path> <text_to_search>\n"
                            "Description: Searchs for the specified text in the specified file text.\n"
                            "Example: -search /path/to/file.txt \"Hello, world!\"\n";
    }
}

namespace errors {
    std::string no_exist = "El comando introducido no existe. ¿Quisiste decir \"--help\"?\n";
}
//separe namespace description into long desc and short desc maybe

bool startsWith(const char* argv, const char* prefix) {
    std::string command(argv);
    std::string prefixC(prefix);

    return (command.substr(0, prefixC.length()) == prefixC);
}