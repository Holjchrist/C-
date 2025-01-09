// TAREA: Gesti�n de una Tabla Hash con Resoluci�n de Colisiones por Sondaje Lineal
// -------------------------------------------------------------------------------------
// Descripci�n:
// Este programa implementa una tabla hash en C++ que almacena identificaciones (IDs) 
// compuestas por exactamente 7 d�gitos. Utiliza una funci�n hash basada en los primeros 
// 7 d�gitos de la ID para calcular el �ndice en la tabla. En caso de colisiones, se 
// utiliza el m�todo de sondeo lineal para encontrar un espacio disponible.
//
// Funcionalidades principales:
// 1. Inserci�n de IDs en la tabla hash con verificaci�n de duplicados.
// 2. B�squeda de IDs, retornando su �ndice si est�n almacenadas en la tabla.
// 3. Visualizaci�n completa de las posiciones ocupadas en la tabla hash.
//
// Restricciones:
// 1. La tabla hash tiene un tama�o fijo definido por la constante `MAX_SIZE` (26).
// 2. Solo se aceptan IDs con exactamente 7 d�gitos.
// 3. La resoluci�n de colisiones se realiza exclusivamente mediante sondeo lineal.
// 4. No se permiten duplicados en la tabla hash.
// 5. En caso de que la tabla est� llena, no se pueden insertar m�s IDs.
//
// Funciones adicionales:
// - Mostrar un men� interactivo para realizar operaciones como insertar, buscar y 
//   visualizar la tabla hash.
//
// ------------------------------------------------
// Autores:
// - Jesmel Maria Ramirez Matos - 1121013
// - Algellys Batista Perez - 1123467
// - Holjchrist Martinez - 1124628
// - Robert Manuel Cepeda Fernandez - 1122845
// - Jeremy Octavio Almonte Mateo - 1122803
// ------------------------------------------------
// Fecha de entrega: Viernes, 3 de enero 2025
// -------------------------------------------------
#include <iostream>
#include <string>
#include <limits>

#define MAX_SIZE 26  // Tamano de la tabla hash
#define TOTAL_IDS 26 // Total de IDs a insertar

// Clase que representa la tabla hash
class HashTable {
private:
    std::string table[MAX_SIZE];  // Tabla hash que almacena las IDs
    bool occupied[MAX_SIZE];      // Indica si una posicion esta ocupada

    // funci�n hash para calcular el �ndice basado en los primeros 7 d�gitos
    int hashFunction(const std::string& id) {
        int hash = ((id[0] - '0') * 1000000 +
            (id[1] - '0') * 100000 +
            (id[2] - '0') * 10000 +
            (id[3] - '0') * 1000 +
            (id[4] - '0') * 100 +
            (id[5] - '0') * 10 +
            (id[6] - '0')) % MAX_SIZE;
        return hash;
    }

public:
    // Constructor que inicializa la tabla hash
    HashTable() {
        for (int i = 0; i < MAX_SIZE; ++i) {
            occupied[i] = false; // Todas las posiciones estan inicialmente vacias
        }
    }

    // Insertar una ID en la tabla hash
    bool insert(const std::string& id) {
        if (id.size() != 7) {  // Verifica que la ID tenga 7 d�gitos
            std::cerr << "Error: La ID debe tener exactamente 7 digitos.\n";
            return false;  // Si no tiene 7 d�gitos, no la inserta
        }

        int index = hashFunction(id);  // Calcula el �ndice con la funci�n hash

        // Resolver colisiones con sondeo lineal
        int originalIndex = index;  // Guarda el �ndice original para evitar bucles infinitos
        while (occupied[index]) {  // Revisa si la posici�n ya est� ocupada
            if (table[index] == id) {  // Si la ID ya est� en la tabla
                std::cerr << "Error: La ID " << id << " ya existe en la tabla.\n";
                return false;  // No permite duplicados
            }
            index = (index + 1) % MAX_SIZE;  // Sondeo lineal: mueve a la siguiente posici�n
            if (index == originalIndex) {  // Si se vuelve al �ndice original, la tabla est� llena
                std::cerr << "Error: La tabla esta llena.\n";
                return false;
            }
        }

        // Insertar la ID en la posici�n calculada
        table[index] = id;
        occupied[index] = true;  // Marca la posici�n como ocupada
        return true;
    }

    // Buscar una ID en la tabla hash
    int search(const std::string& id) {
        if (id.size() != 7) {  // Verifica que la ID tenga 7 d�gitos
            std::cerr << "Error: La ID debe tener exactamente 7 digitos.\n";
            return -1;  // Si no tiene 7 d�gitos, no la busca
        }

        int index = hashFunction(id);  // Calcula el �ndice de la ID

        int originalIndex = index;  // Guarda el �ndice original para evitar bucles infinitos

        // Buscar la ID con sondeo lineal
        while (occupied[index]) {  // Mientras haya elementos en la tabla
            if (table[index] == id) {  // Si la ID se encuentra en la posici�n
                return index;  // Retorna el �ndice donde se encuentra
            }
            index = (index + 1) % MAX_SIZE;  // Sondeo lineal: mueve a la siguiente posici�n
            if (index == originalIndex) {  // Si se recorre toda la tabla
                break;
            }
        }
        return -1;  // Si no se encuentra la ID, retorna -1
    }

    // Mostrar la tabla hash
    void display() {
        std::cout << "Tabla Hash:\n";
        // Muestra las IDs almacenadas en las posiciones ocupadas
        for (int i = 0; i < MAX_SIZE; ++i) {
            if (occupied[i]) {  // Si la posici�n est� ocupada
                std::cout << "Indice " << i << ": " << table[i] << std::endl;  // Muestra la ID
            }
        }
    }
};

int main() {
    HashTable hashTable;

    // Lista de IDs a insertar
    const std::string ids[TOTAL_IDS] = {
        "1122348", "1123161", "1122803", "1121812", "1123467",
        "1124507", "1122912", "1120291", "1122845", "1117498",
        "1122340", "1124489", "1105838", "1120975", "1123042",
        "1108421", "1124628", "1120999", "1120449", "1124718",
        "1123320", "1121515", "1121013", "1124176", "1124979" ,"1125001"
    };

    // Insertar IDs en la tabla hash
    for (int i = 0; i < TOTAL_IDS; ++i) {
        hashTable.insert(ids[i]);
    }

    int option;
    std::string id;

    do {
        // Menu de opciones
        std::cout << "\n--- Menu de Opciones ---\n";
        std::cout << "1. Buscar una ID\n";
        std::cout << "2. Mostrar toda la tabla hash\n";
        std::cout << "3. Salir\n";
        std::cout << "Elija una opcion: ";

        std::cin >> option;

        if (std::cin.fail()) {  // Si la entrada es invalida
            std::cin.clear();  // Limpia el estado de error de std::cin
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Descarta la entrada invalida
            std::cout << "Entrada invalida. Intente de nuevo.\n";
            continue;
        }

        switch (option) {
        case 1: {  // Buscar una ID
            std::cout << "Ingrese la ID que desea buscar (7 digitos): ";
            std::cin >> id;
            if (id.size() == 7) {
                int index = hashTable.search(id);
                if (index != -1) {
                    std::cout << "La ID " << id << " se encuentra en el indice " << index << ".\n";
                }
                else {
                    std::cout << "La ID " << id << " no se encuentra en la tabla.\n";
                }
            }
            else {
                std::cout << "Error: La ID debe tener exactamente 7 digitos.\n";
            }
            break;
        }

        case 2:  // Mostrar la tabla hash
            hashTable.display();
            break;

        case 3:  // Salir
            std::cout << "Saliendo del programa...\n";
            break;

        default:
            std::cout << "Opcion no valida. Intente de nuevo.\n";
        }
    } while (option != 3);

    return 0;
}
