// TAREA: Simulacion de Tablero de Ajedrez con Movimientos de Reina y Torres
// -------------------------------------------------------------------------------------
// Descripcion:
// Este programa simula un tablero de ajedrez de 8x8 con una reina y dos torres. El objetivo
// es colocar las piezas en posiciones validas y luego marcar los movimientos posibles de
// la reina y las posiciones de peligro generadas por las torres. Los movimientos seguros
// de la reina se marcan con 'V', mientras que las posiciones de peligro generadas por las
// torres se marcan con 'X'. El programa permite al usuario ingresar las posiciones de las
// piezas y luego muestra el tablero con la informacion correspondiente.
//
// Restricciones:
// 1. El tablero es de 8x8 y las piezas deben colocarse en posiciones validas dentro de este.
// 2. La reina puede moverse en cualquier direccion: vertical, horizontal o diagonal.
// 3. Las torres marcan los movimientos peligrosos en su fila y columna.
// 4. Los movimientos seguros de la reina se marcan como 'V'.
// 5. Las posiciones de peligro de las torres se marcan como 'X'.
// 6. Solo se permiten coordenadas en formato "1A" para las piezas.
// 7. El tablero se imprime despues de colocar todas las piezas y marcar los movimientos seguros
//    y peligrosos.
//
// Autores:
// - Jesmel Maria Ramirez Matos - 1121013
// - Algellys Batista Perez - 1123467
// - Holjchrist Martinez - 1124628
// - Hector David Martinez Rosario - 1108421
// - Robert Manuel Cepeda Fernandez - 1122845
// - Jeremy Octavio Almonte Mateo - 1122803
// ------------------------------------------------
// Fecha de entrega: Domingo, 13 de enero 2025
//-------------------------------------------------

#include <iostream>
#include <limits> // Para limpiar el buffer de entrada
#include <cctype> // Para funciones como toupper
using namespace std;

// Definir el tamaño del tablero y los caracteres que representan las piezas y los estados
const int SIZE = 8;
const char EMPTY = '.';          // Casillas vacias
const char SAFE_MOVE = 'V';      // Movimiento seguro para la reina
const char DANGER_MOVE = 'X';   // Movimiento peligroso por torre
const char TORRE = 'T';         // Representacion de la torre
const char REINA = 'R';         // Representacion de la reina

// Estructura para representar una posicion en el tablero (fila, columna)
struct Posicion {
    int fila;
    int columna;
};

// Funcion para verificar si una posicion esta dentro de los limites del tablero
bool esPosicionValida(Posicion pos) {
    return pos.fila >= 0 && pos.fila < SIZE && pos.columna >= 0 && pos.columna < SIZE;
}

// Funcion para verificar si dos posiciones son iguales
bool esMismaPosicion(Posicion p1, Posicion p2) {
    return p1.fila == p2.fila && p1.columna == p2.columna;
}

// Funcion para verificar si una posicion en el tablero esta ocupada por una pieza
bool esPosicionOcupada(char tablero[SIZE][SIZE], Posicion pos) {
    return tablero[pos.fila][pos.columna] != EMPTY;
}

// Funcion para colocar una pieza en una posicion del tablero
void colocarPieza(char tablero[SIZE][SIZE], Posicion pos, char pieza) {
    tablero[pos.fila][pos.columna] = pieza;
}

// Funcion para marcar las posiciones de peligro desde una torre
void marcarPeligroDesdeTorre(char tablero[SIZE][SIZE], Posicion torrePos) {
    // Marcar la fila y la columna de la torre con 'X' (peligro)
    for (int i = 0; i < SIZE; ++i) {
        if (tablero[torrePos.fila][i] == SAFE_MOVE) {
            tablero[torrePos.fila][i] = DANGER_MOVE;
        }
    }
    for (int i = 0; i < SIZE; ++i) {
        if (tablero[i][torrePos.columna] == SAFE_MOVE) {
            tablero[i][torrePos.columna] = DANGER_MOVE;
        }
    }
}

// Funcion para marcar los movimientos seguros de la reina en el tablero
void marcarMovimientosSegurosParaReina(char tablero[SIZE][SIZE], Posicion reinaPos) {
    // Direcciones para los 8 movimientos posibles de la reina (horizontal, vertical, diagonal)
    int dFila[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
    int dColumna[] = { 0, 0, 1, -1, 1, -1, 1, -1 };

    // Para cada direccion posible, marcamos los movimientos seguros
    for (int d = 0; d < 8; ++d) {
        int f = reinaPos.fila + dFila[d];
        int c = reinaPos.columna + dColumna[d];
        // Continuar mientras la posicion sea valida
        while (esPosicionValida({ f, c })) {
            // Si la casilla esta vacia, marcarla como 'V' (movimiento seguro)
            if (tablero[f][c] == EMPTY) {
                tablero[f][c] = SAFE_MOVE;
            }
            // Si la casilla tiene una torre, dejarla como esta
            if (tablero[f][c] == TORRE) {
                tablero[f][c] = TORRE;
            }
            // Si la casilla es peligrosa (ya marcada por una torre), dejarla como esta
            if (tablero[f][c] == DANGER_MOVE) {
                tablero[f][c] = DANGER_MOVE;
            }

            // Avanzar a la siguiente casilla en la misma direccion
            f += dFila[d];
            c += dColumna[d];
        }
    }
}

// Funcion para imprimir el tablero en consola
void imprimirTablero(char tablero[SIZE][SIZE]) {
    cout << "  A B C D E F G H\n"; // Encabezado con letras
    for (int i = 0; i < SIZE; ++i) {
        cout << i + 1 << " "; // Numeracion de filas
        for (int j = 0; j < SIZE; ++j) {
            cout << tablero[i][j] << ' '; // Imprimir cada casilla del tablero
        }
        cout << '\n'; // Salto de linea despues de cada fila
    }
}

// Funcion para convertir una coordenada en formato "1A" a la estructura Posicion
Posicion convertirCoordenada(const string& coordenada) {
    Posicion pos;
    // Convertir el numero (restar 1 para que sea compatible con indices 0-based)
    pos.fila = coordenada[0] - '1';
    // Convertir la letra (restar 'A' para obtener indice 0-based)
    pos.columna = toupper(coordenada[1]) - 'A';
    return pos;
}

// Funcion para ingresar una posicion valida para una pieza (reina o torre)
void ingresarPosicionValida(char tablero[SIZE][SIZE], Posicion& p, const string& pieza) {
    bool posicionValida = false; // Variable de control para finalizar el bucle

    do {
        string coordenada;
        // Solicitar al usuario la posicion de la pieza en formato "1A"
        cout << "Ingrese la posicion de la " << pieza << " (ejemplo: 1A): ";
        cin >> coordenada;

        // Validar que la entrada tenga el formato correcto
        if (coordenada.length() != 2 || !isdigit(coordenada[0]) || !isalpha(coordenada[1])) {
            cout << "Formato invalido. Debe ingresar un numero seguido de una letra (ejemplo: 1A).\n";
            continue; // Volver al inicio del bucle
        }

        // Convertir la coordenada a la estructura Posicion
        p = convertirCoordenada(coordenada);

        // Validar que la posicion este dentro de los limites y no este ocupada
        if (!esPosicionValida(p) || esPosicionOcupada(tablero, p)) {
            cout << "Posicion invalida o ocupada. Intente nuevamente.\n";
        }
        else {
            posicionValida = true; // Salir del bucle al finalizar correctamente
        }
    } while (!posicionValida);
}

// Funcion principal
int main() {
    char tablero[SIZE][SIZE];
    // Inicializar el tablero con casillas vacias
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            tablero[i][j] = EMPTY;

    // Declarar las posiciones de la reina y las dos torres
    Posicion reina, torre1, torre2;

    // Ingresar y colocar la reina en el tablero
    ingresarPosicionValida(tablero, reina, "reina");
    colocarPieza(tablero, reina, REINA);

    // Ingresar y colocar la primera torre en el tablero
    ingresarPosicionValida(tablero, torre1, "primera torre");
    colocarPieza(tablero, torre1, TORRE);

    // Ingresar y colocar la segunda torre en el tablero
    ingresarPosicionValida(tablero, torre2, "segunda torre");
    colocarPieza(tablero, torre2, TORRE);

    // Marcar los movimientos seguros para la reina
    marcarMovimientosSegurosParaReina(tablero, reina);

    // Marcar las posiciones de peligro desde ambas torres
    marcarPeligroDesdeTorre(tablero, torre1);
    marcarPeligroDesdeTorre(tablero, torre2);

    // Imprimir el tablero final con las piezas y los movimientos marcados
    cout << "\nTablero final:\n";
    imprimirTablero(tablero);

    return 0; // Finalizar el programa
}
