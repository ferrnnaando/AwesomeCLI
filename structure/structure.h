#pragma once
#include <iostream>
#include <fstream> //?
#include <string>
#include <sstream> //?
#include <vector>
    #include <unistd.h>
    #include <chrono>
    #include <thread>
    #include <cstdio>
	#include <memory>
	#include <stdexcept>
	#include <sys/sysinfo.h>
	#include <sys/statvfs.h>
	#include <iomanip>

bool is_sudo();

bool files_exists(const std::string& text);
void config_files();
bool startsWith(const char* argv, const char* prefix);
double calculateCpuUsage(unsigned long long& prevIdle, unsigned long long& prevTotal);
std::string exec(const char* cmd);
void print_hardware_info();