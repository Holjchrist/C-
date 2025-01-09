/*
-------------------------------------------------------------------------------------
TAREA: MasterMind de 4 dígitos únicos en C++
-------------------------------------------------------------------------------------
Objetivo:
1. Implementar un juego interactivo donde el usuario adivine un número secreto compuesto de 4 dígitos únicos entre 1 y 6.
2. Proporcionar retroalimentación detallada para cada intento:
   - 'C' para dígitos correctos en la posición correcta.
   - 'F' para dígitos presentes pero en una posición incorrecta.
   - 'X' para dígitos no presentes en el número secreto.
3. Calcular y mostrar un puntaje basado en el número de intentos realizados.
4. Manejar correctamente las entradas del usuario, validando que sean números válidos dentro del rango y con el formato esperado.
5. Utilizar memoria estática y lógica eficiente para gestionar el juego.

Requisitos:
1. Generar un número secreto de 4 dígitos únicos aleatorios entre 1 y 6.
2. Implementar un sistema de validación para garantizar que las entradas del usuario sean válidas.
3. Proporcionar retroalimentación detallada basada en las reglas del juego:
   - Correcto ('C'), Fuera de lugar ('F') y No presente ('X').
4. Permitir un máximo de 10 intentos por parte del usuario para adivinar el número.
5. Calcular el puntaje final según la cantidad de intentos realizados, asignando más puntos a quienes adivinen en menos intentos.
6. Mostrar mensajes claros al ganar, perder o ingresar datos no válidos.

Nota: Este programa valida cuidadosamente las entradas del usuario y proporciona mensajes claros para garantizar una experiencia interactiva robusta.
-------------------------------------------------------------------------------------
Jesmel Maria Ramirez Matos - 1121013
Algellys Batista Perez - 1123467
Holjchrist Martinez - 1124628
-------------------------------------------------------------------------------------
29 de Noviembre del 2024
*/

#include <iostream>
#include <cstdlib>  // Para srand() y rand()
#include <ctime>    // Para time()
#include <cstring>  // Para funciones como strlen() y strcmp()

using namespace std;

// Función para generar un número aleatorio único de 4 dígitos entre 1 y 6
void generarNumeroAleatorio(char numero[]) {
    srand(time(0)); // Inicializa la semilla para generar números aleatorios
    bool usado[7] = { false }; // Array para verificar si un dígito ya fue usado

    for (int i = 0; i < 4; i++) {
        int digito;
        do {
            digito = (rand() % 6) + 1; // Genera un número aleatorio entre 1 y 6
        } while (usado[digito]);       // Repite hasta encontrar un dígito no usado
        usado[digito] = true;         // Marca el dígito como usado
        numero[i] = '0' + digito;     // Convierte el número a carácter y lo almacena
    }
    numero[4] = '\0'; // Añade el carácter nulo al final del arreglo
}

// Función para evaluar el intento del usuario y devolver un resultado
void evaluarIntento(const char secreto[], const char intento[], char resultado[]) {
    bool presente[7] = { false }; // Array para verificar si un dígito está en el número secreto

    // Marca los dígitos presentes en el número secreto
    for (int i = 0; i < 4; i++) {
        presente[secreto[i] - '0'] = true; // Convierte el carácter a entero y lo marca
    }

    // Evalúa cada dígito del intento del usuario
    for (int i = 0; i < 4; i++) {
        if (intento[i] == secreto[i]) {
            resultado[i] = 'C'; // 'C' para dígitos correctos en la posición correcta
        }
        else if (presente[intento[i] - '0']) {
            resultado[i] = 'F'; // 'F' para dígitos presentes pero en posición incorrecta
        }
        else {
            resultado[i] = 'X'; // 'X' para dígitos no presentes
        }
    }
    resultado[4] = '\0'; // Añade el carácter nulo al final del arreglo
}

// Función para calcular el puntaje basado en el número de intentos
int calcularPuntaje(int intento) {
    static const int puntajes[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 }; // Tabla de puntajes
    return intento <= 10 ? puntajes[intento - 1] : 0; // Devuelve el puntaje correspondiente
}

// Función principal del programa
int main() {
    char numeroSecreto[5]; // Arreglo para almacenar el número secreto
    generarNumeroAleatorio(numeroSecreto); // Genera el número secreto

    int intentosMaximos = 10; // Máximo número de intentos permitidos
    cout << "Bienvenido al juego de adivinanza de 4 digitos unicos entre 1 y 6.\n";
    cout << "Tienes " << intentosMaximos << " intentos.\n";
    cout << "Reglas: 'C' = Correcto, 'F' = Fuera de lugar, 'X' = No presente.\n";

    // Bucle para gestionar los intentos del usuario
    for (int intento = 1; intento <= intentosMaximos; ++intento) {
        char intentoUsuario[5], resultado[5]; // Arreglos para el intento del usuario y el resultado
        cout << "\nIntento #" << intento << ": ";
        cin >> intentoUsuario; // Captura el intento del usuario

        // Valida que el intento sea de 4 dígitos
        if (strlen(intentoUsuario) != 4) {
            cout << "Por favor, ingresa un numero de 4 digitos unicos entre 1 y 6.\n";
            --intento; // No cuenta este intento como válido
            continue;
        }

        // Valida que todos los dígitos estén entre 1 y 6
        bool valido = true;
        for (int i = 0; i < 4; i++) {
            if (intentoUsuario[i] < '1' || intentoUsuario[i] > '6') {
                valido = false;
                break;
            }
        }

        if (!valido) {
            cout << "Por favor, ingresa solo digitos entre 1 y 6.\n";
            --intento; // No cuenta este intento como válido
            continue;
        }

        // Evalúa el intento del usuario y genera el resultado
        evaluarIntento(numeroSecreto, intentoUsuario, resultado);
        cout << "Resultado: " << resultado << endl;

        // Verifica si el usuario adivinó el número secreto
        if (strcmp(resultado, "CCCC") == 0) {
            int puntaje = calcularPuntaje(intento); // Calcula el puntaje basado en el intento
            cout << "Felicidades Adivinaste el numero en el intento #" << intento << "!\n";
            cout << "Puntaje total: " << puntaje << " puntos.\n";
            return 0; // Termina el programa
        }
    }

    // Si el usuario no adivina en los intentos permitidos
    cout << "\nLo siento, no adivinaste el numero secreto.\n";
    cout << "El numero era: " << numeroSecreto << endl;
    cout << "Puntaje final: 0 puntos. Mejor suerte la proxima vez!\n";
    return 0;
}
