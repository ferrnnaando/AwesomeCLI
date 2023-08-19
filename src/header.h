#pragma once
#include <iostream>
#include <string>
#include <map>
#include <cstdlib>

#if defined(__APPLE__) || (__linux__)
    #include <unistd.h>
#elif defined(_WIN32) || defined(_WIN64)
    #include <windows.h>
#endif

#if defined(__APPLE__)
    #include <mach-o/dyld.h>
    #include <libgen.h>
#endif

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