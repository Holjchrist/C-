// TAREA: Torres de Hanoi con Gestión de Entradas y Salidas
// -------------------------------------------------------------------------------------
// Descripción:
// Este programa simula la resolución del clásico problema de las Torres de Hanoi, 
// donde se mueven anillos entre tres pilares respetando las reglas del juego. 
// El número de anillos es proporcionado por el usuario, y se resuelve de manera 
// recursiva. Además, se gestiona la entrada del número de anillos para garantizar 
// que sea un número válido, manejando errores y proporcionando retroalimentación al usuario.
//
// Funcionalidades principales:
// 1. Resolución del problema de las Torres de Hanoi de manera recursiva.
// 2. Contabilización del número total de movimientos realizados para resolver el problema.
// 3. Solicitud interactiva al usuario para ingresar el número de anillos y controlar entradas inválidas.
// 4. Posibilidad de realizar múltiples simulaciones con diferentes números de anillos.
//
// Restricciones:
// 1. El número de anillos debe ser un número entero positivo.
// 2. El número de anillos no puede ser cero, ya que no es posible resolver las Torres de Hanoi con 0 anillos.
// 3. El programa se ejecuta en un bucle que permite al usuario intentar con diferentes cantidades de anillos, 
//    hasta que decida salir con una respuesta 'n' o 'N'.
//
// Funciones adicionales:
// - Verificación de entradas inválidas utilizando un ciclo para asegurar que solo se ingresen números enteros 
//   positivos.
// - Recursión para la solución del problema de las Torres de Hanoi, moviendo los anillos entre los pilares de 
//   acuerdo con las reglas del juego.
// - Respuesta interactiva para que el usuario decida si desea intentar con un nuevo número de anillos o salir 
//   del programa.
//
// ------------------------------------------------
// Autores:
// - Jesmel Maria Ramirez Matos - 1121013
// - Algellys Batista Perez - 1123467
// - Holjchrist Martinez - 1124628
// - Robert Manuel Cepeda Fernandez - 1122845
// - Jeremy Octavio Almonte Mateo - 1122803
// ------------------------------------------------
// Fecha de entrega: Lunes, 7 de enero 2025
// -------------------------------------------------
#include <iostream>
#include <limits> // Para numeric_limits (utilizado para gestionar entradas inválidas)
#include <sstream> // Para usar stringstream en la conversión

using namespace std;

// Funcion recursiva para resolver las Torres de Hanoi
void torresDeHanoi(int n, char desde, char hacia, char auxiliar, int& contador) {
    if (n == 1) {
        // Mover el anillo 1 directamente desde el pilar de origen al pilar de destino
        cout << "Mover anillo 1 desde " << desde << " hacia " << hacia << endl;
        contador++;  // Incrementamos el contador de movimientos
        return;  // Finalizamos la recursión para el anillo 1
    }

    // Llamada recursiva para mover n-1 anillos al pilar auxiliar
    torresDeHanoi(n - 1, desde, auxiliar, hacia, contador);

    // Mover el anillo n al pilar de destino
    cout << "Mover anillo " << n << " desde " << desde << " hacia " << hacia << endl;
    contador++;  // Incrementamos el contador de movimientos

    // Llamada recursiva para mover los n-1 anillos desde el pilar auxiliar al pilar de destino
    torresDeHanoi(n - 1, auxiliar, hacia, desde, contador);
}

// Funcion principal que ejecuta la simulación de las Torres de Hanoi
void ejecutarTorresDeHanoi() {
    int n; // Numero de anillos
    cout << "Bienvenido a las Torres de Hanoi" << endl;
    cout << "Posicion inicial:" << endl;
    cout << "Pilar A (Origen): Todos los anillos" << endl;
    cout << "Pilar B (Auxiliar): Vacio" << endl;
    cout << "Pilar C (Destino): Vacio" << endl << endl;

    // Solicitar al usuario que ingrese el número de anillos
    cout << "Ingrese el numero de anillos: ";

    while (true) {
        string input;
        cin >> input;

        // Verificar si el input es un número entero positivo
        bool esValido = true;
        for (char c : input) {
            if (!isdigit(c)) {  // Si algún carácter no es un dígito, la entrada es inválida
                esValido = false;
                break;
            }
        }

        if (esValido) {
            // Intentar convertir la entrada a un número entero
            stringstream ss(input);
            ss >> n;

            if (ss.fail()) {
                cout << "No se pudo convertir el número. Por favor ingrese un numero valido." << endl;
                continue;
            }

            if (n == 0) {
                // Manejar el caso especial donde n es 0
                cout << "No es posible resolver las Torres de Hanoi sin anillos. Ingrese un numero valido." << endl;
                continue; // Pedir nueva entrada
            }
            break; // Entrada válida
        }
        else {
            // Mensaje para entradas que no son números enteros positivos
            cout << "Por favor, ingrese un numero entero positivo: ";
        }
    }

    int contador = 0; // Contador para el número de movimientos
    cout << endl << "Los movimientos necesarios para resolver las Torres de Hanoi son:" << endl;
    torresDeHanoi(n, 'A', 'C', 'B', contador);  // Llamar la función recursiva para resolver el problema

    cout << endl << "Numero total de movimientos: " << contador << endl;
    cout << "Posicion final:" << endl;
    cout << "Pilar A (Origen): Vacio" << endl;
    cout << "Pilar B (Auxiliar): Vacio" << endl;
    cout << "Pilar C (Destino): Todos los anillos" << endl << endl;

    // Preguntar al usuario si quiere realizar otra simulación
    char respuesta;
    while (true) {
        cout << "Desea intentar con otro numero de anillos? (s/n): ";
        cin >> respuesta;

        // Verificar si la entrada es válida (solo 's' o 'n')
        if (cin.fail() || cin.peek() != '\n') {
            // Si el input es más largo que un solo carácter, es inválido
            cout << "Entrada invalida. Por favor ingrese 's' para continuar o 'n' para salir." << endl;
            cin.clear(); // Limpiar el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar el resto de la línea
        }
        else if (respuesta == 's' || respuesta == 'S') {
            // Si la respuesta es 's' o 'S', ejecutar la simulación nuevamente
            ejecutarTorresDeHanoi();
            return; // Terminar la función actual y evitar un bucle infinito
        }
        else if (respuesta == 'n' || respuesta == 'N') {
            // Si la respuesta es 'n' o 'N', agradecer al usuario y salir
            cout << "Gracias por jugar a las Torres de Hanoi. Hasta luego!" << endl;
            return;  // Salir de la función
        }
        else {
            // Si la entrada no es válida, mostrar un mensaje de error y pedir una nueva respuesta
            cout << "Entrada invalida. Por favor ingrese 's' para continuar o 'n' para salir." << endl;
        }
    }
}

int main() {
    ejecutarTorresDeHanoi(); // Iniciar la simulación
    return 0;  // Terminar la ejecución del programa
}
