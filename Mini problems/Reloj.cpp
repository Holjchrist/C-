#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int count = 0;  // Contador de los cruces de las manecillas

    // Calculamos las manecillas que se cruzan en 24 horas (1440 minutos)
    for (int minute = 0; minute < 1440; minute++) {  // Desde el minuto 0 hasta el minuto 1439
        // Ángulo de la manecilla de los minutos
        double minuteAngle = (minute % 60) * 6;

        // Ángulo de la manecilla de la hora
        double hourAngle = ((minute / 60) * 30) + ((minute % 60) * 0.5);

        // Calcular la diferencia de ángulo entre ambas manecillas
        double angleDiff = fabs(minuteAngle - hourAngle);

        // Si la diferencia de ángulos es muy pequeña (lo que indica que se cruzan)
        if (angleDiff < 0.1 || fabs(angleDiff - 360) < 0.1) {
            count++;
        }
    }

    // Mostrar cuántas veces se cruzan las manecillas
    cout << "Las manecillas se cruzan " << count << " veces en 24 horas." << endl;

    return 0;
}
