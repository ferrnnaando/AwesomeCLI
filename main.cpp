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
           std::cout << "Uso: sudo ./awesome-cli\n";
            return 1;
        }

        switch (argc) {
            case 1: //tells how to do a good usage if the user just did ./awesome-cli
                std::cout << "Uso: sudo ./" + prefix::program_name + " --help / -h (No ejecutado con permisos de root)" << std::endl;
                return 1;

            default: //if the user entered a parameter, let register it and value it below.
                if (argv[1] == prefix::long_prefix + "help" || argv[1] == prefix::short_prefix + "h") { //|| allows to check for long command version prefix and the alias.
                    switch (argc) {
                        case 2:
                            std::cout << color << commands::description::help_description; //print the main help const char message
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
                        if (std::string(argv[2]) == "set.color") {
                            std::cout << "Introduce un color: gris, verde" << std::endl;
                            return 1;
                        } else {
                            std::cout << "El parametro indicado no existe. ¿Quisiste decir --help config?" << std::endl;
                            return 1;
                        }
                        return 0;

                    case 4:
                        if (std::string(argv[2]) == "set.color") {
                            if (std::string(argv[3]) == "verde") { 
                            std::cout << color << "El color verde es el nuevo color de terminal.";
                            return 0;
                            } 
                            else if (std::string(argv[3]) == "gris") {
                                std::cout << "El color gris es el nuevo color de terminal.";
                                return 0;
                            } 
                            else {
                                std::cout << "El color indicado no existe. ¿Quisiste decir --help config?" << std::endl;
                                return 1;
                            }
                        }
                        break;

                    default:
                        if (argc >= 4) { //awesome-cli -c set.color red ->red<->>
                            std::cout << "Has indicado más parámetros de los necesarios. ¿Quisiste decir --help config?" << std::endl;
                            return 1;
                        } else { //unhandled error
                            std::cout << "Error inesperado." << std::endl;
                            return 1;
                        }
                    }
                } else { //checking if entered a command not registered
                    std::cout << "El comando indicado no existe. ¿Quisiste decir --help?" << std::endl;
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