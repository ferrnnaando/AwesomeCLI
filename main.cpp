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
        cout << "Introduce un numero:";
        cin >> numero;
        if(numero >= 1){
            contador++;
            system("clear");
        } else {
            break;
        }
    } while(numero != 0);

    if(contador > 1) {
        cout <<"\nHas arruinado la cadena cuando llevabas " << contador << " valores introducidos correctamente.\n";
    } else if (contador == 1) { 
        cout <<"\nHas arruinado la cadena cuando llevabas " << contador << " valor introducido correctamente.\n";
     } else {
        cout << "\nNo se ha guardado ningun numero porque no has introducido ninguno correctamente.\n";
     }

        return 0;
    }
