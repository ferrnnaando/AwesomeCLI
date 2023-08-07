#pragma once
#include <iostream>
#include <fstream> //?
#include <string>
#include <sstream> //?
#include <vector>

#ifdef _WIN32
    #include <windows.h>

#else
    #include <unistd.h>
    #include <chrono>
    #include <thread>
    #include <cstdio>
	#include <memory>
	#include <stdexcept>
	#include <sys/sysinfo.h>
	#include <sys/statvfs.h>
	#include <iomanip>

    const std::string ANSI_RED = "\033[31m";
#endif

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

struct statvfs buffer;

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

struct config_file;

struct hardware_info;

namespace prefix {
        std::string short_prefix = "-";
        std::string long_prefix = "--";
        std::string program_name = "awesome-cli";
        std::string entered_exec_name;
}

namespace commands {
    namespace description {
       std::string help_search = "-s, --search <archivo> <string> Busca una cadena de carácteres en un archivo de texto.\n";
       std::string help_track =  "  -t, --track Muestra información del hardware, drivers y componentes.\n";

        const char* help_description = //"Instalación: sudo ./awesome-cli --install"
                                       "Uso: sudo ./awesome-cli --comando / -alias <opcion> <otra opcion>\n\n"
                                       ""
                                       "Opciones:\n"
                                       "  -h, --help                        Mostrar ayuda,\n"
                                       "  -V, --version                     Mostrar versión,\n"
                                       "  -c, --config                      Muestra tu configuración y modifícala.\n\n"
                                       ""
                                       "Comandos:\n"
                                       "  -s, --search <archivo> <string>   Busca una cadena de carácteres en un archivo de texto,\n"
                                       "  -t, --track                       Muestra información del hardware, drivers y componentes.\n\n"
                                       ""
                                       "Ejemplos:\n"
                                       "  ./awesome-cli --config color,\n"
                                       "  ./awesome-cli --config set.color green,\n"
                                       "  ./awesome-cli -s ~/Desktop/Dev/file.txt ram.\n\n"
                                       ""
                                       "Advertencia: Para buscar ayuda sobre un comando específico recuerda introducir el nombre completo sin prefijo ni alias. Ejemplo:\n"
                                       "  Bien: --help search, -h search,\n"
                                       "  Mal:  --help -s, -h s.\n\n";

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