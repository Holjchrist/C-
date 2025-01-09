// TAREA: Gestión de un Árbol Binario de Búsqueda
// -------------------------------------------------------------------------------------
// Descripción:
// Este programa implementa un árbol binario de búsqueda (Binary Search Tree, BST) en C++.
// Un árbol binario de búsqueda es una estructura de datos donde cada nodo tiene un valor,
// con las siguientes reglas:
// - Los nodos con valores menores que el nodo actual se almacenan en el subárbol izquierdo.
// - Los nodos con valores mayores se almacenan en el subárbol derecho.
// El programa permite insertar, buscar, eliminar nodos y mostrar el árbol en diferentes
// tipos de recorrido (InOrder, PreOrder y PostOrder).
//
// Restricciones:
// 1. El primer nodo insertado será la raíz (root).
// 2. Al mostrar el árbol, debe hacerse de forma intuitiva y clara, mostrando la topología.
// 3. Se pueden utilizar cualquiera de los tres tipos de recorridos clásicos (InOrder, PreOrder, PostOrder).
// 4. Al eliminar un nodo, deben seguirse las reglas de sustitución del nodo para mantener la estructura del árbol.
// 5. Solo se permiten números naturales (positivos y enteros).
//------------------------------------------------------
// Autores:
//-Jesmel Maria Ramirez Matos - 1121013
//-Algellys Batista Perez - 1123467
//-Holjchrist Martinez  - 1124628
//-Hector David Martinez Rosario - 1108421
//-Robert Manuel Cepeda Fernandez - 1122845
//-Jeremy Octavio Almonte Mateo - 1122803
// ------------------------------------------------
// Fecha de entrega: Viernes, 3 de enero 2025 
//-------------------------------------------------
#include <iostream>
#include <limits> // Para usar std::numeric_limits
#include <iomanip> // Para usar std::setw
#include <string> // Para validar cadenas de entrada
using namespace std;

// Estructura que representa un nodo en el árbol
struct Node {
    int data; // Dato almacenado en el nodo
    Node* left; // Puntero al hijo izquierdo
    Node* right; // Puntero al hijo derecho

    // Constructor que inicializa el nodo con un valor y punteros a NULL
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Clase que representa el árbol binario de búsqueda
class BinarySearchTree {
private:
    Node* root; // Raíz del árbol

    // Inserta un nodo en el árbol
    Node* insert(Node* node, int val, bool& inserted) {
        if (!node) { // Caso base: se encuentra un lugar vacío
            inserted = true;
            return new Node(val);
        }
        if (val < node->data) // Si el valor es menor, insertar en el subárbol izquierdo
            node->left = insert(node->left, val, inserted);
        else if (val > node->data) // Si el valor es mayor, insertar en el subárbol derecho
            node->right = insert(node->right, val, inserted);
        else
            inserted = false; // El valor ya existe en el árbol
        return node;
    }

    // Busca un valor en el árbol
    Node* search(Node* node, int val) {
        if (!node || node->data == val) // Caso base: el nodo es NULL o se encuentra el valor
            return node;
        if (val < node->data) // Si el valor es menor, buscar en el subárbol izquierdo
            return search(node->left, val);
        return search(node->right, val); // Si el valor es mayor, buscar en el subárbol derecho
    }

    Node* findMin(Node* node) {
        if (!node || !node->left) // Caso base: nodo nulo o sin hijo izquierdo
            return node;
        return findMin(node->left); // Llamada recursiva hacia el hijo izquierdo
    }


    Node* findMax(Node* node) {
        if (!node || !node->right) // Caso base: nodo nulo o sin hijo derecho
            return node;
        return findMax(node->right); // Llamada recursiva hacia el hijo derecho
    }


    // Elimina un nodo del árbol
    Node* deleteNode(Node* node, int val, bool& deleted) {
        if (!node) return NULL; // Caso base: nodo no encontrado

        if (val < node->data) // Si el valor es menor, buscar en el subárbol izquierdo
            node->left = deleteNode(node->left, val, deleted);
        else if (val > node->data) // Si el valor es mayor, buscar en el subárbol derecho
            node->right = deleteNode(node->right, val, deleted);
        else { // Nodo encontrado
            deleted = true;
            if (!node->left && !node->right) { // Caso 1: nodo hoja
                delete node;
                return NULL;
            }
            if (!node->right) { // Caso 2: solo tiene hijo izquierdo
                Node* temp = node->left;
                delete node;
                return temp;
            }
            if (!node->left) { // Caso 3: solo tiene hijo derecho
                Node* temp = node->right;
                delete node;
                return temp;
            }
            // Caso 4: tiene ambos hijos
            Node* maxLeft = findMax(node->left); // Encontrar el nodo máximo del subárbol izquierdo
            node->data = maxLeft->data; // Reemplazar el valor actual con el máximo
            node->left = deleteNode(node->left, maxLeft->data, deleted); // Eliminar el nodo duplicado
        }
        return node;
    }

    // Muestra el árbol en PreOrder (raíz, izquierda, derecha)
    void preOrder(Node* node) {
        if (node) {
            cout << node->data << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    // Muestra el árbol en InOrder (izquierda, raíz, derecha)
    void inOrder(Node* node) {
        if (node) {
            inOrder(node->left);
            cout << node->data << " ";
            inOrder(node->right);
        }
    }

    // Muestra el árbol en PostOrder (izquierda, derecha, raíz)
    void postOrder(Node* node) {
        if (node) {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->data << " ";
        }
    }

    // Muestra el árbol de forma jerárquica
    void displayHierarchy(Node* node, int level) {
        if (node == NULL) return;

        displayHierarchy(node->right, level + 1); // Mostrar subárbol derecho primero
        cout << setw(4 * level) << "" << node->data << endl; // Mostrar nodo con sangría
        displayHierarchy(node->left, level + 1); // Mostrar subárbol izquierdo
    }

public:
    // Constructor que inicializa el árbol vacío
    BinarySearchTree() : root(NULL) {}

    // Inserta un valor en el árbol
    void insert(int val) {
        if (val < 0) { // Validación: solo se permiten números naturales
            cout << "Solo se permiten numeros naturales." << endl;
            return;
        }
        bool inserted = false;
        root = insert(root, val, inserted);
        if (inserted)
            cout << "Valor insertado." << endl;
        else
            cout << "El valor ya existe en el arbol." << endl;
    }

    // Busca un valor en el árbol
    bool search(int val) {
        return search(root, val) != NULL;
    }

    // Elimina un valor del árbol
    void deleteNode(int val) {
        bool deleted = false;
        root = deleteNode(root, val, deleted);
        if (deleted)
            cout << "Valor eliminado." << endl;
        else
            cout << "El valor no existe en el arbol." << endl;
    }

    // Muestra el árbol en InOrder
    void displayInOrder() {
        if (!root) {
            cout << "El arbol esta vacio." << endl;
            return;
        }
        inOrder(root);
        cout << endl;
    }

    // Muestra el árbol en PreOrder
    void displayPreOrder() {
        if (!root) {
            cout << "El arbol esta vacio." << endl;
            return;
        }
        preOrder(root);
        cout << endl;
    }

    // Muestra el árbol en PostOrder
    void displayPostOrder() {
        if (!root) {
            cout << "El arbol esta vacio." << endl;
            return;
        }
        postOrder(root);
        cout << endl;
    }

    // Muestra el árbol jerárquicamente
    void displayHierarchy() {
        if (!root) {
            cout << "El arbol esta vacio." << endl;
            return;
        }
        displayHierarchy(root, 0);
    }

    // Verifica si el árbol está vacío
    bool isEmpty() {
        return root == NULL;
    }
};

// Función principal
int main() {
    BinarySearchTree bst; // Crear instancia del árbol
    int choice;
    string input;

    do {
        // Menú de operaciones
        cout << "\nMenu de operaciones con el arbol binario de busqueda:" << endl;
        cout << "1. Insertar un valor" << endl;
        cout << "2. Buscar un valor" << endl;
        cout << "3. Eliminar un valor" << endl;
        cout << "4. Mostrar el arbol en InOrder" << endl;
        cout << "5. Mostrar el arbol en PreOrder" << endl;
        cout << "6. Mostrar el arbol en PostOrder" << endl;
        cout << "7. Mostrar el arbol jerarquicamente" << endl;
        cout << "8. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> choice;

        // Validación de entrada
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Por favor ingrese una opcion valida." << endl;
            continue;
        }

        // Procesar la opción seleccionada
        switch (choice) {
        case 1:
            cout << "Ingrese el valor a insertar: ";
            cin >> input;
            if (input.find_first_not_of("0123456789") == string::npos) {
                int value = stoi(input);
                bst.insert(value);
            }
            else {
                cout << "Por favor ingrese un numero entero valido." << endl;
            }
            break;
        case 2:
            if (bst.isEmpty()) {
                cout << "El arbol esta vacio." << endl;
                break;
            }
            cout << "Ingrese el valor a buscar: ";
            cin >> input;
            if (input.find_first_not_of("0123456789") == string::npos) {
                int value = stoi(input);
                if (bst.search(value))
                    cout << "Valor encontrado." << endl;
                else
                    cout << "Valor no encontrado." << endl;
            }
            else {
                cout << "Por favor ingrese un numero entero valido." << endl;
            }
            break;
        case 3:
            if (bst.isEmpty()) {
                cout << "El arbol esta vacio." << endl;
                break;
            }
            cout << "Ingrese el valor a eliminar: ";
            cin >> input;
            if (input.find_first_not_of("0123456789") == string::npos) {
                int value = stoi(input);
                bst.deleteNode(value);
            }
            else {
                cout << "Por favor ingrese un numero entero valido." << endl;
            }
            break;
        case 4:
            bst.displayInOrder();
            break;
        case 5:
            bst.displayPreOrder();
            break;
        case 6:
            bst.displayPostOrder();
            break;
        case 7:
            bst.displayHierarchy();
            break;
        case 8:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion no valida." << endl;
        }
    } while (choice != 8); // Repetir hasta que el usuario decida salir

    return 0;
}