#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << "Numeros cuyo cuadrado termina en el mismo numero:" << endl;

    // Recorremos todos los n�meros menores que 500
    for (int n = 0; n < 500; n++) {
        int square = n * n;

        // Calculamos el n�mero de d�gitos de n
        int len = 0;
        int temp = n;
        while (temp > 0) {
            temp /= 10;
            len++;
        }

        // Verificamos si el cuadrado termina en el mismo n�mero
        if (square % (int)pow(10, len) == n) {
            cout << n << " ";
        }
    }
    cout << endl;

    return 0;
}
