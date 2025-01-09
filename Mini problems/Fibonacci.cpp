#include <iostream>
using namespace std;


void imprimirFibonacci(int n) {
    int a = 1, b = 1, siguiente;


    for (int i = 0; i < n; ++i) {
        cout << a << " ";
        siguiente = a + b;
        a = b;
        b = siguiente;
    }
}

int main() {
    int n;


    cout << "Introduce el numero de terminos de la sucesion de Fibonacci: ";
    cin >> n;

    imprimirFibonacci(n);

    return 0;
}
