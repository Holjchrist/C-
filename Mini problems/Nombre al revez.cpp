#include <iostream>
#include <string>

using namespace std;

int main() {
    // Solicitar al usuario que ingrese un texto
    string texto;
    cout << "Introduce la cadena que deseas invertir: ";
    getline(cin, texto);

    // Invertir la cadena manualmente
    string texto_invertido;
    for (int i = texto.length() - 1; i >= 0; --i) {
        texto_invertido += texto[i];
    }

    // Mostrar el resultado
    cout << "La cadena invertida es: " << texto_invertido << endl;

    return 0;
}