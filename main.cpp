#include <iostream>
#include <conio.h>

using namespace std;

int main() {
    int numero, contador = 0;
    do {
        cout << "Introduce un numero:";
        cin >> numero;
        if(numero>0){ /
            contador++;
        }
    } while(numero != 0);

        cout <<"\nHas arruinado la cadena cuando llevabas " << contador << " valor[es] introducidos correctamente.";
    
        getch();
        return 0;
    }
