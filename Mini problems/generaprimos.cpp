#include <iostream>
using namespace std;

// Función para verificar si un número es primo
bool esPrimo(int num) {
    if (num < 2) return false; // Los números menores que 2 no son primos
    for (int i = 2; i * i <= num; i++) { // Solo verificamos hasta la raíz cuadrada de num
        if (num % i == 0) {
            return false; // Si num es divisible por i, no es primo
        }
    }
    return true; // Si no se encontró divisor, es primo
}

// Función para generar números primos hasta un límite
void generarPrimos(int limite) {
    if (limite < 2) {
        cout << "No hay numeros primos menores a 2." << endl;
        return;
    }

    cout << "Numeros primos hasta " << limite << ": ";
    for (int i = 2; i <= limite; i++) {
        if (esPrimo(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int limite;
    cout << "Introduce el limite hasta el que deseas generar numeros primos: ";
    cin >> limite;

    generarPrimos(limite);

    return 0;
}
