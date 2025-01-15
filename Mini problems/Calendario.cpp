#include <iostream>

using namespace std;

bool esBisiesto(int agno) {
    // Un agno es bisiesto si es divisible por 4 y (no divisible por 100 o divisible por 400)
    return (agno % 4 == 0 && (agno % 100 != 0 || agno % 400 == 0));
}

int diasEnMes(int mes, int agno) {
    // Días en cada mes
    switch (mes) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        return esBisiesto(agno) ? 29 : 28;
    default:
        return 0;
    }
}

int main() {
    int dia, mes, agno;

    // Solicitar y validar el año
    do {
        cout << "Introduce el año: ";
        cin >> agno;
        if (agno <= 0) {
            cout << "Año invalido. Por favor, intenta nuevamente." << endl;
        }
    } while (agno <= 0);

    // Solicitar y validar el mes
    do {
        cout << "Introduce el mes (1-12): ";
        cin >> mes;
        if (mes < 1 || mes > 12) {
            cout << "Mes invalido. Por favor, intenta nuevamente." << endl;
        }
    } while (mes < 1 || mes > 12);

    // Solicitar y validar el dia
    do {
        cout << "Introduce el dia: ";
        cin >> dia;
        if (dia < 1 || dia > diasEnMes(mes, agno)) {
            cout << "Día invalido. Por favor, intenta nuevamente." << endl;
        }
    } while (dia < 1 || dia > diasEnMes(mes, agno));

    // Calcular los dias restantes hasta el 1 de enero del próximo agno
    int diasRestantes = 0;

    // Sumar los dias restantes en el mes actual
    diasRestantes += diasEnMes(mes, agno) - dia;

    // Sumar los dias de los meses restantes del agno
    for (int m = mes + 1; m <= 12; ++m) {
        diasRestantes += diasEnMes(m, agno);
    }

    cout << "Faltan " << diasRestantes << " dias para el 1 de enero del proximo año." << endl;

    return 0;
}
