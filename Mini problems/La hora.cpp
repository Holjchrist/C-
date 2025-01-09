#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // Se recorren todas las combinaciones de horas y minutos (de 00:00 a 23:59)
    for (int h = 0; h < 24; h++) {
        for (int m = 0; m < 60; m++) {
            // Formamos el número de 4 dígitos de la hora (h*100 + m)
            int time = h * 100 + m;

            // Separamos las horas y los minutos para la comprobación
            int hours = h;
            int minutes = m;

            // Verificamos si la suma de los cuadrados de las horas y minutos es igual al número de la hora
            if (pow(hours, 2) + pow(minutes, 2) == time) {
                cout << "La hora que cumple con la propiedad es: ";
                printf("%02d:%02d\n", h, m); // Imprimimos la hora en formato hh:mm
            }
        }
    }
    return 0;
}
