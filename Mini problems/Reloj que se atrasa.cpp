#include <iostream>
#include <cmath>  
using namespace std;

int fibonacci(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int horas;  
    double tiempoTotal = 0.0;  

    cout << "Ingrese el numero de horas: ";
    cin >> horas;

 
    for (int i = 1; i <= horas; ++i) {
        int f_n = fibonacci(i);
        double tiempoAtraso = f_n / pow(2, i);  
        tiempoTotal += tiempoAtraso;
    }


    int minutos = static_cast<int>(tiempoTotal);
    int segundos = static_cast<int>((tiempoTotal - minutos) * 60);

    cout << "El reloj se atrasara un total de " << minutos << " minutos y "
        << segundos << " segundos en " << horas << " horas." << std::endl;

    return 0;
}
