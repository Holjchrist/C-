#include <iostream>
using namespace std;

int main() {
    const int total_personas = 100;
    const int total_monedas = 7869;

    // Variables para almacenar los pagos
    const int pago_senador = 75;
    const int pago_congresista = 99;
    const int pago_invitado = 40;

    // Variables para almacenar los resultados
    int senadores, congresistas, invitados;

    // Iteramos sobre las posibles combinaciones
    for (senadores = 0; senadores <= total_personas; senadores++) {
        for (congresistas = 0; congresistas <= total_personas - senadores; congresistas++) {
            invitados = total_personas - senadores - congresistas;
            int total_recaudado = (senadores * pago_senador) + (congresistas * pago_congresista) + (invitados * pago_invitado);

            // Verificamos si la combinación cumple con el total de monedas
            if (total_recaudado == total_monedas) {
                cout << "Senadores: " << senadores << endl;
                cout << "Congresistas: " << congresistas << endl;
                cout << "Invitados: " << invitados << endl;
                return 0;
            }
        }
    }

    cout << "No se encontró una solución válida." << endl;
    return 0;
}