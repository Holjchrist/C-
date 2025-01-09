#include <iostream>
using namespace std;

int main() {
    // Iterar de 1 a 100
    for (int i = 1; i <= 100; i++) {
        // Si es divisible entre 3 y 5
        if (i % 3 == 0 && i % 5 == 0) {
            cout << "Coca Cola" << endl;
        }
        // Si es divisible solo entre 3
        else if (i % 3 == 0) {
            cout << "Coca" << endl;
        }
        // Si es divisible solo entre 5
        else if (i % 5 == 0) {
            cout << "Cola" << endl;
        }
        // Si no es divisible ni entre 3 ni entre 5
        else {
            cout << i << endl;
        }
    }
    return 0;
}
