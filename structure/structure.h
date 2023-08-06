#pragma once
#include <string>
#include <unistd.h>
#include <fstream>

bool is_sudo();

bool files_exists(const std::string& text);
void config_files();
bool startsWith(const char* argv, const char* prefix);