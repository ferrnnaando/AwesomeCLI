#include <iostream>
#ifdef _WIN32
    #include <conio.h>
#else
    #include <unistd.h>
#endif

using namespace std;

int main() {
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

    for(int a = 0; a < 3; a++) {
        for(int b = 0; b < 3; b++) {
            std::cout << thrD_array[a][b] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    for(const int (&row)[3] : thrD_array) {
        for(const int &n : row) {
            cout << n << " ";
        }
        std::cout << std::endl;
    }

    return 0;
    }
