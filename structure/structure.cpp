#include "structure.h"

bool is_sudo() {
    return (geteuid() == 0);
}

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

double calculateCpuUsage(unsigned long long& prevIdle, unsigned long long& prevTotal) {
		std::ifstream statFile("/proc/stat");
		std::string line4;
		unsigned long long user, nice, system, idle, iowait, irq, softirq, steal;

		if (std::getline(statFile, line4)) {
			std::istringstream iss(line4);
			std::string cpuLabel;
			iss >> cpuLabel >> user >> nice >> system >> idle >> iowait >> irq >> softirq >> steal;
		}

		unsigned long long total = user + nice + system + idle + iowait + irq + softirq + steal;
		unsigned long long totalDiff = total - prevTotal;
		unsigned long long idleDiff = idle - prevIdle;
		double cpu_usage = (totalDiff > 0) ? (1.0 - static_cast<double>(idleDiff) / totalDiff) * 100.0 : 0.0;
		prevTotal = total;
		prevIdle = idle;

    return cpu_usage;
}

std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
    if (!pipe) throw std::runtime_error("popen() failed!");
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}