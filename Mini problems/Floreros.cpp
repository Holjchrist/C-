#include <iostream>
using namespace std;

int main() {

    int x = 8; // Flores adicionales que se restan después
    int flores_iniciales = 100; // Flores iniciales

    cout << "Salvador tiene " << flores_iniciales << " floreros al inicio." << endl << endl;

    // Buscar todas las posibilidades
    for (int N = 0; N <= flores_iniciales; N++) {
        // Verificar las condiciones
        if (N % 6 == 0 && (N - x) % 11 == 0) {
            int vendidas_primera_semana = flores_iniciales - N; // Calcula las flores vendidas
            int restantes_primera_semana = N; // Calcula las flores que quedaron

            // Mostrar el resultado
            cout << "Vendio " << vendidas_primera_semana << " floreros en la primera semana." << endl;
            cout << "Le quedaron " << restantes_primera_semana << " floreros en la primera semana." << endl;
            cout << "Salvador tiene " << (N - x) << " floreros para vender tras restar 8 mas." << endl << endl;
        }
    }

    return 0;
}

