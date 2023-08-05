#include "header.h"

int main(int argc, char* argv[]) {
    int count = 0;

    if(argc == 1) {
        //std::cout << "dumb";
        std::cout << "Introduce una opcion a ejecutar, usa --help para obtener ayuda." << std::endl;
        return 1;
    } 
    else {
        if(argv[1] == prefix::help::help + "help") {
             if(argc >= 3) {
                std::cout << "No puedes hacer eso. ¿Quisiste decir --help <command>?" << std::endl;
                return 1;
            } 
            else if(argc > 2 && std::string(argv[2]) == "search") {
                std::cout << commands::description::search_help_description;
                return 0;
            } 
            else {
                std::cout << " -search *(set/your/path/file.txt) *(text-to-search) -> " << commands::description::search_description << std::endl << std::endl; 
                return 0;
            }  
        } 
        else if(argv[1] == prefix::command::command + "search") {
            ++count;
            if(argc >= 5) {
                std::cout << "Has introducido más argumentos de los esperados para -search. Usa --help search para ver más." << std::endl;
                return 1;
            }
            std::cout << argv[1] << ": Work fines." << std::endl;
            //should use a ifstream 
            return 0;
        } 

        //handle errors
        else if(startsWith(argv[1], "--")) {
            std::cout << argv[1] << ": The entered parameter does not exist. Did you mean \"--help\"?\n";
            return 1;
        } else if(startsWith(argv[1], "-")) {
            std::cout << argv[1] << ": The entered command not exist. Did you mean \"--help\"?\n";
            return 1;
        }
    }

    if(count > 1) {
        std::cout << "Please enter just one subcommand.";
        return 1;
    }


//chec if enters -- and a comand to throw werror

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