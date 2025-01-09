#include <iostream>
using namespace std;

// Funci�n para calcular la persistencia de un n�mero
int calcularPersistencia(int n) {
    int pasos = 0;
    while (n >= 10) {
        int producto = 1;
        // Multiplicamos los d�gitos del n�mero
        while (n > 0) {
            producto *= n % 10; // Extraemos el �ltimo d�gito y lo multiplicamos
            n /= 10; // Eliminamos el �ltimo d�gito
        }
        n = producto; // Actualizamos el n�mero al producto de sus d�gitos
        pasos++; // Contamos un paso m�s en el proceso
    }
    return pasos;
}

int main() {
    // Recorremos los n�meros de dos d�gitos
    for (int n = 10; n < 100; n++) {
        int persistencia = calcularPersistencia(n);
        // Verificamos si la persistencia es mayor a 3
        if (persistencia > 3) {
            cout << "El �nico n�mero de dos d�gitos con persistencia mayor a 3 es: " << n << endl;
            break; // Solo hay uno, por lo que rompemos el ciclo al encontrarlo
        }
    }
    return 0;
}
