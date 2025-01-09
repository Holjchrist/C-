#include <iostream>
using namespace std;

int main() {

    for (int num = 1; num <= 100; num++) {
        int resultado = num; 

        if ((num % 5 == 0) && (num % 3 == 0)) {
                    cout << "Coca-Cola" << endl;
        }
        else if (resultado % 3 == 0) {
            cout << "Coca" << endl;
        }

        else if (num % 5 == 0) {
            cout << "Cola" << endl;
        }

        else {
            cout << num << endl;
        }
    }
    return 0;
}