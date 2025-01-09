/*
-------------------------------------------------------------------------------------
TAREA: Simulador de Cola con Prioridades en C++
-------------------------------------------------------------------------------------
Objetivo:
1. Implementar un programa que gestione una cola con prioridades utilizando memoria dinámica.
2. Permitir al usuario realizar las siguientes operaciones:
   - Agregar elementos (Enqueue) especificando un dato y su prioridad.
   - Eliminar el elemento con la mayor prioridad (Dequeue).
   - Mostrar y vaciar la cola.
3. Manejar entradas de usuario y validarlas correctamente para evitar errores.
4. Garantizar la actualización y visualización correcta de la cola según las prioridades asignadas.
5. Liberar toda la memoria utilizada antes de finalizar el programa para evitar fugas de memoria.

Requisitos:
1. Permitir al usuario agregar elementos con datos y prioridades entre 0 y 16. Si la prioridad supera 16, asignarla como "Default" (-1).
2. Implementar un sistema de inserción que ordene los elementos según su prioridad:
   - Números más bajos representan prioridades más altas.
   - Elementos con igual prioridad se insertan por orden de llegada.
3. Manejar intentos de desencolar desde una cola vacía con mensajes claros.
4. Proporcionar un mecanismo para mostrar y vaciar la cola con confirmación del usuario.
5. Validar todas las entradas para garantizar que sean numéricas y estén en el rango permitido.
6. Proporcionar mensajes claros para facilitar la interacción del usuario con el programa.
-------------------------------------------------------------------------------------
Jesmel Maria Ramirez Matos - 1121013
Algellys Batista Perez - 1123467
Holjchrist Martinez - 1124628
Hector David Martinez Rosario - 1108421
Robert Manuel Cepeda Fernandez - 1122845
Jeremy Octavio Almonte Mateo - 1122803
-------------------------------------------------------------------------------------
10 de Diciembre del 2024
*/


#include <iostream>
#include <sstream> // Para usar ostringstream
#include <string>
#include <cctype>
using namespace std;

// Estructura para representar un nodo en la cola
struct Queue {
    int dato;
    int prioridad;
    Queue* next;
};
// Prototipos
Queue* crearNodo(int, int);
void enqueue(Queue*&, Queue*&, int, int);
void dequeue(Queue*&, Queue*&);
void mostrarYVaciarCola(Queue*&, Queue*&);
bool colaVacia(Queue*&);
int validarEntradaNumerica();

// Funcion para crear un nuevo nodo
Queue* crearNodo(int dato, int prioridad) {
    Queue* nuevoNodo = new Queue(); // Reservar espacio en la memoria para almacenar el nuevo nodo
    nuevoNodo->dato = dato; // Asignar al nuevo nodo dato que queremos insertar
    // Asignar prioridad o establecer como default si es mayor a 16
    nuevoNodo->prioridad = (prioridad > 16) ? 17 : prioridad;
    nuevoNodo->next = nullptr;
    return nuevoNodo;
}

// Funcion para realizar la operacion Enqueue
void enqueue(Queue*& frente, Queue*& fin, int dato, int prioridad) {
    // Crear un nuevo nodo
    Queue* nuevoNodo = crearNodo(dato, prioridad);

    // Si la cola esta vacia
    if (colaVacia(frente)) {
        frente = fin = nuevoNodo;
    }
    // Insertar al final si la prioridad es default 
    else if ( prioridad == 17) {
        fin->next = nuevoNodo;
        fin = nuevoNodo;
    }
    // Insertar segun prioridad
    else {
        if (prioridad < frente->prioridad) {
            // Si la prioridad es mayor (menor numero), se inserta al inicio
            nuevoNodo->next = frente;
            frente = nuevoNodo;
        }
        else {
            // Buscar la posicion correcta segun prioridad
            Queue* actual = frente;
            while (actual->next != nullptr && actual->next->prioridad <= prioridad) {
                actual = actual->next;
            }
            nuevoNodo->next = actual->next;
            actual->next = nuevoNodo;

            // Actualizar puntero al final si se inserta al final
            if (nuevoNodo->next == nullptr) {
                fin = nuevoNodo;
            }
        }
    }
    cout << "Elemento " << dato << " con prioridad " << (prioridad > 16 ? 17 : prioridad) << " encolado.\n";
}

// Funcion para realizar la operacion Dequeue
void dequeue(Queue*& frente, Queue*& fin) {
    
    if (colaVacia(frente)) {
        // Manejo de cola vacia
        cout << "La cola esta vacia. No se puede desencolar.\n";
        return;
    }
    // Eliminar el nodo del frente
    Queue* aux = frente;

    //Si solo a un nodo
    if (frente == fin) {
        frente = fin = nullptr;
    }
    else { // Si a mas de un nodo
        frente = frente->next;
    }
    
    cout << "Elemento " << aux->dato << " desencolado.\n";
    delete aux; // Liberar memoria
}

// Funcion para mostrar y vaciar la cola
void mostrarYVaciarCola(Queue*& frente, Queue*& fin) {
    if (colaVacia(frente)) {
        cout << "La cola esta vacia.\n";
        return;
    }
    cout << "Elementos de la cola:\n";

    while (frente != nullptr) {
        cout << "Dato: " << frente->dato
            << ", Prioridad: " << (frente->prioridad == 17 ? "Default" : to_string(frente->prioridad)) << "\n";
        dequeue(frente, fin); 
    }
    
}

// Funcion para saber si la cola esta  vacia
bool colaVacia(Queue*& frente) {
    return (frente == nullptr) ? true : false;
    // Si frente es igual a null retora true, de lo contrario retorna false
}

// Funcion para validar entradas numericas
int validarEntradaNumerica() {
        string entrada;

        while (true) {
            cin >> entrada; // Leer como texto
            bool esValido = true;

            // Validar que todos los caracteres sean dígitos
            for (size_t i = 0; i < entrada.size(); i++) {
                if (!isdigit(entrada[i])) { // Verifica si no es un dígito
                    esValido = false;
                    break;
                }
            }

            if (esValido && !entrada.empty()) { // Si es válido, conviértelo a número
                try {
                    return stoi(entrada); // Convertir a entero
                }
                catch (const exception&) {
                    // En caso de que la conversión falle
                    cout << "Entrada invalida. Intente nuevamente: ";
                    continue;
                }
            }

            cout << "Entrada invalida. Intente nuevamente: ";
        }
}

// Funcion principal
int main() {
    Queue* frente = nullptr; // Inicializar frente de la cola
    Queue* fin = nullptr;    // Inicializar final de la cola
    int opcion, dato, prioridad;

    do {
        // Mostrar menu
        cout << "\n--- Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Mostrar y vaciar cola\n";
        cout << "4. Salir\n";
        cout << "Ingrese una opcion: ";
        opcion = validarEntradaNumerica();

        switch (opcion) {
        case 1: // Opcion Enqueue
            cout << "Ingrese el dato: ";
            dato = validarEntradaNumerica();
            cout << "Ingrese la prioridad (0-16, mayor a 16 se considera default): ";
            prioridad = validarEntradaNumerica();
            enqueue(frente, fin, dato, prioridad);
            break;

        case 2: // Opcion Dequeue
            dequeue(frente, fin);
            break;

        case 3: // Mostrar y vaciar cola
                mostrarYVaciarCola(frente, fin);
            break;

        case 4: // Salir del programa
            cout << "Liberando recursos y saliendo del programa...\n";
            mostrarYVaciarCola(frente, fin); // Liberar nodos restantes antes de salir
            break;

        default: // Manejo de opcion invalida
            cout << "Opcion invalida. Por favor, elija una opcion del menu.\n";
            break;
        }
    } while (opcion != 4);

    return 0;
}
