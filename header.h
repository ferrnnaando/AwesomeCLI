#pragma once

#include <iostream>
#include <fstream>
#include <string>

#ifdef _WIN32
    #include <windows.h>

#else
    #include <unistd.h>
    #include <chrono>
    #include <thread>
    #define ANSI_COLOR_RESET "\033[0m"
    #define ANSI_COLOR_GREEN "\033[32m"
    #define GREEN "\033[32m"
#endif

namespace prefix {
        std::string short_prefix = "-";
        std::string long_prefix = "--";
        std::string program_name = "awesome-cli";
        std::string entered_exec_name;
}

namespace commands {
    namespace description {
        std::string search_description = "Searchs for the specified text in the specified file text.";
        const char* search_help_description = "Help for --search subcommand: \n"
                            "Usage: -search <file_path> <text_to_search>\n"
                            "Description: Searchs for the specified text in the specified file text.\n"
                            "Example: -search /path/to/file.txt \"Hello, world!\"\n";

        const char* help_description = "Uso: ./awesome-cli --comando / -alias <opcion> <otra opcion>\n\n"
                                       ""
                                       "Opciones:\n"
                                       "  -h, --help                        Mostrar ayuda,\n"
                                       "  -V, --version                     Mostrar versión,\n"
                                       "  -c, --config                      Muestra tu configuración y modifícala.\n\n"
                                       ""
                                       "Comandos:\n"
                                       "  -s, --search <archivo> <string>   Busca una cadena de carácteres en un archivo de texto.\n\n"
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