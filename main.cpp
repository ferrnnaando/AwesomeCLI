#include "header.h"
#include "structure/structure.h"
//<filesystem> what is lol

    std::string color;
    std::string formatted_color;

int main(int argc, char* argv[]) {
    color = ANSI_COLOR_RESET;
    prefix::entered_exec_name = argv[0];

    if(prefix::entered_exec_name.find(prefix::program_name) == std::string::npos) {
        std::cout << argv[0] << ": " << "El nombre del ejecutable debe ser \"" + prefix::program_name + "\". Por favor, no trate de modificar ni distribuir este programa." << std::endl;
        return 1;
    } 
    else {
        if(is_sudo()) {
             if (!files_exists("/awesome-cli/")) {
                config_files();
            }
        }
        else {
           std::cout << "El programa parece no estar ejecutándose con el permiso de root mediante sudo. \nDar este permiso es de vital importancia para que AwesomeCLI pueda acceder a \nla información del hardware, rastrear rutas del sistema y  monitorear información.\n";
            return 1;
        }

        switch (argc) {
            case 1:
                std::cout << "Uso: ./" + prefix::program_name + " --help / -h" << std::endl;
                return 1;

            default:
                if (argv[1] == prefix::long_prefix + "help" || argv[1] == prefix::short_prefix + "h") {
                    switch (argc) {
                        case 2:
                            std::cout << color << commands::description::help_description;
                            return 0;

                        case 3:
                            if (std::string(argv[2]) == "search") {
                                std::cout << commands::description::search_help_description;
                                return 0;
                            } else {
                                std::cout << "-" << argv[2] << ": " << "El comando indicado no existe. ¿Quisiste decir --help?" << std::endl;
                            }
                            break; 

                        default:
                            if (argc >= 4) {
                                std::cout << "Has indicado más parámetros de los necesarios. ¿Quisiste decir --help <command>?" << std::endl;
                                return 1;
                            } else {
                                std::cout << "Error inesperado." << std::endl;
                                return 1;
                            }
                    }
                } 
                else if(argv[1] == prefix::long_prefix + "version" || argv[1] == prefix::short_prefix + "v") {
                    std::cout << commands::description::version_description;
                    return 0;
                }
                else if(argv[1] == prefix::long_prefix + "config" || argv[1] == prefix::short_prefix + "c") {
                   switch (argc) {
                    case 2:
                        std::cout << "show the config.";
                        return 0;

                    case 3:
                        if (std::string(argv[2]) == "color") {
                            std::cout << "Introduce un color: gris, verde";
                        }
                        return 0;

                    case 4:
                        if (std::string(argv[2]) == "color") {
                            if (std::string(argv[3]) == "verde") { 
                                

                                    formatted_color = "verde";
                                    std::ofstream register_config;
                                    register_config.open("/awesome-cli/config", std::ios::out);
                                    if (register_config.is_open()) {
                                        register_config << "color: " << formatted_color;
                                        register_config.close();
                                    }


                                if (register_config.is_open()) {
                                    register_config << "color: " << formatted_color;
                                }

                        std::cout << color << "El color verde es el nuevo color de terminal.";
                            } else if (std::string(argv[3]) == "gris") {
                                std::cout << "El color gris es el nuevo color de terminal.";
                            } else {
                                std::cout << "Color no reconocido. Usa 'verde' o 'gris'.";
                            }
                        }
                        return 1;

                    default:
                        std::cout << "Comando no reconocido.";
                        return 1;
                    }
                }
            }
        }

    return 0;
}






/*#ifdef _WIN32
    // Code specific to Windows platform
    #include <windows.h>
#endif

#ifdef _MSC_VER
    #if _MSC_VER >= 1929
        // Code for Visual C++ 2019 and newer
    #else
        // Code for older versions of Visual C++
    #endif
#endif*/

/*int main() {
    int numero, contador = 0;
    do {
        cout << "Introduce un numero: ";
        cin >> numero;

        if(numero >= 1){
            contador++;
            system("clear");
        } else {
            break;
        }
    } while(numero != 0);

    if(contador > 1) {
        cout <<"Has arruinado la cadena cuando llevabas " << contador << " valores introducidos correctamente.\n";
    } else if (contador == 1) { 
        cout <<"Has arruinado la cadena cuando llevabas " << contador << " valor introducido correctamente.\n";
     } else {
        cout << "No se ha guardado ningun numero porque no has introducido ninguno correctamente.\n";
     }

    double dynamic_double[] = {3.7, 2.9, 1.2, 1.1, 1.0, 392.5};
    int thrD_array[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    std::cout << "---------" << std::endl;
    for(int a = 0; a < 3; a++) {
        std::cout << "| ";
        for(int b = 0; b < 3; b++) {
            
            std::cout << thrD_array[a][b] << " ";
        }
        std::cout << "|" << std::endl;
    }
    std::cout << "---------" << std::endl;

    std::cout << std::endl;

    for(const int (&row)[3] : thrD_array) {
        for(const int &n : row) {
            cout << n << " ";
        }
        std::cout << std::endl;
    }

    return 0;
    }
*/