#include <iostream>
using namespace std;

int main() {
    int max = 999;
    int min = 100;
    
    for (min; min <= max; min++) {
        int prim = min % 10;
        int num = prim * prim * prim;

        int sec = (min % 100 - prim) / 10;
        int numd = sec*sec*sec;

        int ter = (min - prim - sec) / 100;
        int numt = ter * ter * ter;

        int sum = num + numd + numt;

        if (sum == min) {
            cout << sum << " ";
        }
    }
}