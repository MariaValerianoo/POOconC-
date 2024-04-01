#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Daviplata {
private:
    string nombreTitular;
    float saldo;
    vector<string> movimientos;

public:
    // Constructor
    Daviplata(string _nombreTitular, float _saldo) : nombreTitular(_nombreTitular), saldo(_saldo) {}

    string getNombreTitular() const { return nombreTitular; }
    float getSaldo() const { return saldo; }
    vector<string> getMovimientos() const { return movimientos; }

    void setNombreTitular(const string& _nombreTitular) { nombreTitular = _nombreTitular; }
    void setSaldo(float _saldo) { saldo = _saldo; }
    void setMovimientos(const vector<string>& _movimientos) { movimientos = _movimientos; }

    void realizarMovimiento(const string& movimiento) {
        movimientos.push_back(movimiento);
    }

    void mostrarMovimientos() const {
        cout << "Historial de movimientos:" << endl;
        for (const auto& movimiento : movimientos) {
            cout << movimiento << endl;
        }
    }

    void realizarPago(float monto, const string& beneficiario) {
        cout << "Saldo actual: $" << saldo << endl; 
        if (saldo >= monto) {
            saldo -= monto;
            realizarMovimiento("Pago a " + beneficiario + ": $" + to_string(monto));
            cout << "Pago de $" << monto << " realizado a " << beneficiario << ". Nuevo saldo: $" << saldo << endl;
        } else {
            cout << "Saldo insuficiente para realizar el pago." << endl;
        }
    }

    void realizarRecarga(float monto) {
        cout << "Saldo actual: $" << saldo << endl; 
        saldo += monto;
        realizarMovimiento("Recarga: +" + to_string(monto));
        cout << "Recarga de $" << monto << " realizada exitosamente. Nuevo saldo: $" << saldo << endl;
    }

    void consultarSaldo() const {
        cout << "Saldo actual: $" << saldo << endl;
    }
    void consultarUsuario() const{
        cout<<"Bienvenida "<<nombreTitular<<endl;
    }
};

int main() {
    Daviplata cuenta("Mafe", 5000);
    int opcion;

    do {
        cout << "----- Menú Daviplata -----" << endl;
        cuenta.consultarUsuario();
        cuenta.consultarSaldo(); 
        cout << "1. Realizar pago" << endl;
        cout << "2. Realizar recarga" << endl;
        cout << "3. Consultar saldo" << endl;
        cout << "4. Ver movimientos" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese su opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                float monto;
                string beneficiario;
                cout << "Ingrese el monto del pago: ";
                cin >> monto;
                cout << "Ingrese el nombre del beneficiario: ";
                cin.ignore();
                getline(cin, beneficiario);
                cuenta.realizarPago(monto, beneficiario);
                break;
            }
            case 2: {
                float monto;
                cout << "Ingrese el monto de la recarga: ";
                cin >> monto;
                cuenta.realizarRecarga(monto);
                break;
            }
            case 3:
                cuenta.consultarSaldo();
                break;
            case 4:
                cuenta.mostrarMovimientos();
                break;
            case 0:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción inválida. Por favor, ingrese una opción válida." << endl;
        }
    } while (opcion != 0);

    return 0;
}
