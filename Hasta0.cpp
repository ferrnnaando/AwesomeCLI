#include <iostream>
#include <conio.h>

using namespace std;

int main() {
    int numero, contador = 0; //empieza por 0 la variable
    do {
        cout << "Introduce un numero:";
        cin >> numero;
        if(numero>0){ //si el numero es mayor que 0
            contador++; //ignora el numero introducido, solo añade 1 numero al contador
        }
    } while(numero != 0);
     if(numero == 0){
        cout <<"\nHas arruinado la cadena cuando llevabas " << contador << " valor[es] introducidos correctamente.";
    }
        getch();
        return 0;
    }
