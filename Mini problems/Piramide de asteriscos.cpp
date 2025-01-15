#include <iostream>

using namespace std;

int main() {
    int filas;
    cout << "Introduce el numero de filas para la piramide: ";
    cin >> filas;

    string linea = "";
    for (int i = 1; i <= filas; ++i) {
        linea += "*";
        cout << linea << endl;
    }

    return 0;
}
