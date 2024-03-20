#include<iostream>
using namespace std;
/* ordenamiento de arrays*/
//metodo de la clase carta
void ordBur(string cart[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (cart[j] > cart[j + 1]) {
                string temp = cart[j];
                cart[j] = cart[j + 1];
                cart[j + 1] = temp;
            }
        }
    }
}

// Mostrar el vector
void vecOrd(string cart[], int tamanio) {
    for (int i = 0; i < tamanio; i++) {
        cout << cart[i] << " ";
    }
    cout << endl;
}
int main() {
    string cart[12] = {"9", "j", "q", "k", "a", "2", "3", "4", "5", "6", "7", "8"};
    int n = sizeof(cart) / sizeof(cart[0]);
    cout << "El vector original es: ";
    vecOrd(cart, n);
    ordBur(cart, n);
    cout << "El vector ordenado es: ";
    vecOrd(cart, n);
    return 0;
}