#include <iostream>
using namespace std;

void factoresPrimos(int numero) {
    int divisor = 2;

    cout << "Los factores primos de " << numero << " son: ";
    while (numero > 1) {
        while (numero % divisor == 0) {
            cout << divisor << " ";
            numero /= divisor;
        }
        divisor++;
    }
    cout << endl;
}

int main() {
    int numero;
    cout << "Introduce un numero para descomponer en factores primos, el numero debe ser mayor o igual a 2: ";
    cin >> numero;

    if (numero < 2) {
        cout << "El numero debe ser mayor o igual a 2." << endl;
        return 1;
    }

    factoresPrimos(numero);
    return 0;
}
