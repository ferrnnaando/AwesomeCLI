#include <iostream>
#include <fstream>
#include <string>

#ifdef _WIN32
    #include <windows.h>

#else
    #include <unistd.h>
    #include <chrono>
    #include <thread>
#endif

namespace prefix {
        std::string short_prefix = "-";
        std::string long_prefix = "--";
}

namespace commands {
    namespace description {
        std::string search_description = "Searchs for the specified text in the specified file text.";
        const char* search_help_description = "Help for --search subcommand: \n"
                            "Usage: -search <file_path> <text_to_search>\n"
                            "Description: Searchs for the specified text in the specified file text.\n"
                            "Example: -search /path/to/file.txt \"Hello, world!\"\n";

        const char* help_description = "Uso: ./awesomecli --comando / -alias <opcion> <otra opcion>\n\n"
                                       "Opciones:\n"
                                       "  -h, --help                        Mostrar ayuda,\n"
                                       "  -V, --version                     Mostrar versión.\n\n"
                                       ""
                                       "Comandos:\n"
                                       "  -s, --search <archivo> <string>   Busca una cadena de carácteres en un archivo de texto.\n\n";

        const char* version_description = " * Versión: 2.1.3\n"
                                          "    // Un CLI eficiente, compacto y versátil capaz de hacer cualquier cosa.\n"
                                          "    // Proyecto de código abierto disponible en: https://github.com/ferrnnaando/\n"
                                          "    // Este proyecto está destinado a ser forkeado, usado y distribuido libremente bajo la MIT License.\n";
    }
}

namespace errors {
    std::string no_exist = "El comando introducido no existe. ¿Quisiste decir \"--help\"?\n";
}