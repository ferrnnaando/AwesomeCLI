#include "structure.h"

bool is_sudo() {
    return (geteuid() == 0);
}

//bool files_exists() {
bool files_exists(const std::string& directory) {
    std::ifstream file(directory);
    
    return file.good();
}

void config_files() {
    system("mkdir /awesome-cli/ && touch /awesome-cli/config.txt");
}

bool startsWith(const char* argv, const char* prefix) {
    std::string command(argv);
    std::string prefixC(prefix);

    return (command.substr(0, prefixC.length()) == prefixC);
}