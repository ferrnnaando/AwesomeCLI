#pragma once
#include <iostream>
#include <fstream> //?
#include <string>
#include <sstream> //?
#include <vector>
#include <thread>
#include <stdlib.h>
#include <functional>
#include <chrono>
#include <cstring>
#define NUM_CORES std::thread::hardware_concurrency()
const std::string ANSI_RED = "\033[31m";
const std::string ANSI_YELLOW = "\033[33m";
const std::string ANSI_RESET = "\033[0m";
const std::string ANSI_UNDERLINE = "\033[4m";
const std::string ANSI_ITALIC = "\033[3m";
const std::string ANSI_BOLD = "\033[1m";
std::string error = ANSI_RED + "Error: " + ANSI_RED;
std::string warning = ANSI_YELLOW + "Advertencia: " + ANSI_YELLOW;

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
    #include <cstdio>
	#include <memory>
	#include <stdexcept>
	#include <sys/sysinfo.h>
	#include <sys/statvfs.h>
	#include <iomanip>
#endif

struct is_integer {
    bool is;
};

int contador_top = 0;
int seconds = 0;

struct config_file;
struct hardware_info;
struct statvfs buffer;
struct system_info {
    std::string model_name; //cpu
    std::string cores; //cpu
    std::string gpu_info; //gpu
    double ram_total; //ram
    double ram_used; //ram
    double ram_percent; //ram
    long ram_total_literal; //ram
    long memav_value; //ram
    std::string os_name; //os info
    std::string os_model = "Linux"; //os info
    std::string disk_usage; //disk info
    std::string network_usage; //network info

    bool found_cpu, found_gpu, found_ram, found_os;
};

system_info cpu;
system_info gpu;
system_info ram;
system_info os;
system_info disk;
system_info network;
std::string line8, line9, line10;
std::string info_cpu;
std::string info_gpu;
std::string info_os;
std::string info_ram;
std::string ram_usage;
std::string formated_consum;
std::string formated_bot_status;
std::string status_title;
std::string formated_disk_usage;
std::string formated_network_usage;
std::string formated_uptime;

namespace prefix {
        std::string short_prefix = "-";
        std::string long_prefix = "--";
        std::string program_name = "awesome-cli";
        std::string entered_exec_name;
}

namespace commands {
    namespace description {
        std::string help_search = "-s, --search <archivo> <string> Busca una cadena de carácteres en un archivo de texto.\n";
        std::string help_track =  "-t, --track Muestra información del hardware, drivers y componentes.\n";
        std::string help_stress = "-c, --stress <segundos / loop> <target:cpu / ram> Estresa ciertos componentes del hardware.\n";
        std::string help_encrypt = "    --encrypt <texto> <clave> Encripta un codigo con una clave secreta. Si la pierdes, será imposible descifrar el texto.\n";
        std::string help_decrypt = "    --decrypt <cifrado> <clave> Desencripta un codigo con una clave secreta.\n";

        const char* help_description = //"Instalación: sudo ./awesome-cli --install"
                                       " Uso: sudo ./awesome-cli --comando / -alias <opcion> <otra opcion>\n\n"
                                       ""
                                       " Opciones:\n"
                                       "   -h, --help       Muestra este mensaje de ayuda,\n"
                                       "       --config     Muestra tu configuración y modifícala,\n"
                                       "   -V, --version    Mostrar la versión del programa e información.\n"
                                       ""
                                       " Comandos:\n"
                                       "   -t, --track                        Muestra información del hardware, drivers y componentes,\n"
                                       "   -s, --search <archivo> <string>    Busca una cadena de carácteres en un archivo de texto,\n"
                                       "       --encrypt <texto> <clave>      Encripta un codigo con una clave secreta. Si la pierdes, será imposible descifrar el texto,\n"
                                       "       --decrypt <cifrado> <clave>    Desencripta un codigo con una clave secreta,\n"
                                       "   -c, --stress <segundos / loop> <potencia: high / medium / low> Estresa la CPU a tu gusto.\n\n"
                                       ""
                                       " Ejemplos:\n"
                                       "   ./awesome-cli --config color,\n"
                                       "   ./awesome-cli --config set.color green,\n"
                                       "   ./awesome-cli -s ~/Desktop/Dev/file.txt ram.\n\n"
                                       ""
                                       " Advertencia: Para buscar ayuda sobre un comando específico recuerda introducir el nombre completo sin prefijo ni alias. Ejemplo:\n"
                                       "   Bien: --help search, -h search,\n"
                                       "   Mal:  --help -s, -h s.\n\n";

                                       //the help command just works for commands. not for options

        const char* version_description = " * Versión: 2.1.4\n"
                                          "    // Un CLI eficiente, compacto y versátil capaz de hacer cualquier cosa.\n"
                                          "    // Proyecto de código abierto disponible en: https://github.com/ferrnnaando/\n"
                                          "    // Este proyecto está destinado a ser forkeado, usado y distribuido libremente bajo la MIT License.\n";
    }
}

namespace errors {
    std::string no_exist = "El comando introducido no existe. ¿Quisiste decir \"--help\"?\n";
}