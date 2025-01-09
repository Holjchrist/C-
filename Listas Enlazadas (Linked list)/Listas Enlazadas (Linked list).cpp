/*
-------------------------------------------------------------------------------------
TAREA: Gesti�n de Lista Enlazada con Operaciones B�sicas en C++
-------------------------------------------------------------------------------------
Objetivo:
1. Implementar un programa que permita gestionar una lista enlazada de forma din�mica.
2. Proporcionar al usuario las siguientes operaciones:
   - Insertar nodos de manera ordenada (ascendente), evitando datos duplicados.
   - Buscar nodos espec�ficos por su valor.
   - Eliminar nodos espec�ficos de la lista.
   - Mostrar todos los elementos de la lista.
   - Vaciar la lista y liberar toda la memoria utilizada antes de finalizar el programa.
3. Garantizar una interacci�n clara y validada con el usuario, evitando entradas inv�lidas.
4. Prevenir errores comunes como p�rdida de memoria, nodos duplicados, y operaciones inv�lidas en listas vac�as.
-------------------------------------------------------------------------------------
Jesmel Maria Ramirez Matos - 1121013
Algellys Batista Perez - 1123467
Holjchrist Martinez�-�1124628
Hector David Martinez Rosario - 1108421
Robert Manuel Cepeda Fernandez - 1122845
Jeremy Octavio Almonte Mateo - 1122803
-------------------------------------------------------------------------------------
10 de Diciembre del 2024
*/

#include <iostream>
#include <limits> // Para limpiar el flujo de entrada
using namespace std;

// Estructura de un nodo en la lista enlazada
struct LinkedList {
    int dato;           // Dato almacenado en el nodo
    LinkedList* next;   // Puntero al siguiente nodo
};

// Funci�n para insertar un nodo de forma ordenada (ascendente) con validaci�n de duplicados
void insertarNodo(LinkedList*& head, int dato) {
    // Verificar si el dato ya existe en la lista
    LinkedList* actual = head;
    while (actual) {
        if (actual->dato == dato) { // Si el dato ya est� en la lista, no se inserta
            cout << "El dato " << dato << " ya existe en la lista. No se insertara.\n";
            return;
        }
        actual = actual->next;
    }

    // Crear un nuevo nodo
    LinkedList* nuevoNodo = new LinkedList();
    nuevoNodo->dato = dato;
    nuevoNodo->next = nullptr;

    // Si la lista est� vac�a o el dato es menor que el primer elemento
    if (!head || dato < head->dato) {
        nuevoNodo->next = head; // Insertar al inicio
        head = nuevoNodo;       // Actualizar el inicio
    }
    else {
        // Encontrar la posici�n adecuada para insertar
        LinkedList* actual = head;
        while (actual->next && actual->next->dato < dato) {
            actual = actual->next;
        }
        nuevoNodo->next = actual->next; // Conectar el nuevo nodo
        actual->next = nuevoNodo;
    }
    cout << "Nodo con dato " << dato << " insertado correctamente.\n";
}

// Funci�n para buscar un nodo por su valor
void buscarNodo(LinkedList* head, int dato) {
    if (!head) { // Si la lista est� vac�a
        cout << "La lista esta vacia. No se puede buscar ningun nodo.\n";
        return;
    }

    // Recorrer la lista para buscar el nodo
    LinkedList* actual = head;
    int posicion = 1;
    while (actual) {
        if (actual->dato == dato) { // Si se encuentra el dato
            cout << "Nodo con dato " << dato << " encontrado en la posicion " << posicion << ".\n";
            return;
        }
        actual = actual->next;
        posicion++;
    }
    cout << "El dato " << dato << " no existe en la lista.\n"; // Si no se encuentra el dato
}

// Funci�n para eliminar un nodo por su valor
void eliminarNodo(LinkedList*& head, int dato) {
    if (!head) { // Si la lista est� vac�a
        cout << "La lista esta vacia. No se puede eliminar ningun nodo.\n";
        return;
    }

    // Caso especial: el nodo a eliminar es el primero
    if (head->dato == dato) {
        LinkedList* temp = head; // Guardar el nodo a eliminar
        head = head->next;       // Actualizar el inicio
        delete temp;             // Liberar memoria
        cout << "Nodo con dato " << dato << " eliminado correctamente.\n";
        return;
    }

    // Buscar el nodo a eliminar
    LinkedList* actual = head;
    while (actual->next && actual->next->dato != dato) {
        actual = actual->next;
    }

    if (!actual->next) { // Si no se encuentra el nodo
        cout << "El dato " << dato << " no existe en la lista. No se elimino ningun nodo.\n";
        return;
    }

    // Eliminar el nodo encontrado
    LinkedList* temp = actual->next;
    actual->next = temp->next; // Saltar el nodo
    delete temp;               // Liberar memoria
    cout << "Nodo con dato " << dato << " eliminado correctamente.\n";
}

// Funci�n para mostrar todos los nodos de la lista y luego vaciarla
void mostrarYVaciarLista(LinkedList*& head) {
    if (!head) { // Si la lista est� vac�a
        cout << "La lista esta vacia.\n";
        return;
    }

    // Mostrar los datos de la lista
    LinkedList* temp = head;
    cout << "Lista enlazada: ";
    while (temp) {
        cout << temp->dato << " ";
        temp = temp->next;
    }
    cout << endl;

    // Vaciar la lista
    while (head) {
        temp = head;
        head = head->next; // Actualizar el inicio
        delete temp;       // Liberar memoria
    }
    cout << "La lista ha sido mostrada y vaciada.\n";
}

// Funci�n para validar entradas num�ricas
int validarEntradaNumerica() {
    int valor;
    while (!(cin >> valor)) { // Validar si la entrada no es un n�mero
        cout << "Entrada invalida. Por favor, ingrese un numero: ";
        cin.clear(); // Limpiar el estado de error
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar la entrada inv�lida
    }
    return valor;
}

// Funci�n principal
int main() {
    LinkedList* head = nullptr; // Inicializar la lista como vac�a
    int opcion, dato;

    do {
        // Mostrar men� de opciones
        cout << "\n--- Menu ---\n";
        cout << "1. Insertar nodo\n";
        cout << "2. Buscar nodo\n";
        cout << "3. Eliminar nodo\n";
        cout << "4. Mostrar y vaciar lista enlazada\n";
        cout << "5. Salir\n";
        cout << "Ingrese una opcion: ";
        opcion = validarEntradaNumerica();

        switch (opcion) {
        case 1: // Insertar nodo
            cout << "Ingrese el dato a insertar: ";
            dato = validarEntradaNumerica();
            insertarNodo(head, dato);
            break;
        case 2: // Buscar nodo
            cout << "Ingrese el dato a buscar: ";
            dato = validarEntradaNumerica();
            buscarNodo(head, dato);
            break;
        case 3: // Eliminar nodo
            cout << "Ingrese el dato a eliminar: ";
            dato = validarEntradaNumerica();
            eliminarNodo(head, dato);
            break;
        case 4: // Mostrar y vaciar lista
            mostrarYVaciarLista(head);
            break;
        case 5: // Salir del programa
            cout << "Liberando memoria y saliendo del programa...\n";
            while (head) {
                LinkedList* temp = head;
                head = head->next;
                delete temp; // Liberar memoria
            }
            break;
        default: // Opci�n inv�lida
            cout << "Opcion invalida. Por favor, elija una opcion del menu.\n";
            break;
        }
    } while (opcion != 5);

    return 0;
}
