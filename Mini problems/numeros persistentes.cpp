#include <iostream>
using namespace std;

// Función para calcular la persistencia de un número
int calcularPersistencia(int n) {
    int pasos = 0;
    while (n >= 10) {
        int producto = 1;
        // Multiplicamos los dígitos del número
        while (n > 0) {
            producto *= n % 10; // Extraemos el último dígito y lo multiplicamos
            n /= 10; // Eliminamos el último dígito
        }
        n = producto; // Actualizamos el número al producto de sus dígitos
        pasos++; // Contamos un paso más en el proceso
    }
    return pasos;
}

int main() {
    // Recorremos los números de dos dígitos
    for (int n = 10; n < 100; n++) {
        int persistencia = calcularPersistencia(n);
        // Verificamos si la persistencia es mayor a 3
        if (persistencia > 3) {
            cout << "El único número de dos dígitos con persistencia mayor a 3 es: " << n << endl;
            break; // Solo hay uno, por lo que rompemos el ciclo al encontrarlo
        }
    }
    return 0;
}
