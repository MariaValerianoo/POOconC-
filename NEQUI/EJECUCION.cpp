#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <ctime>

using namespace std;

class CuentaNequi {
private:
    string nombreTitular;
    int edad;
    float saldo;
    vector<float> movimientos;

public:
    // Constructor
    CuentaNequi(string nombre, int edad_inicial, float saldo_inicial) : nombreTitular(nombre), edad(edad_inicial), saldo(saldo_inicial) {}

    // Accesores
    string getNombreTitular() const {
        return nombreTitular;
    }

    int getEdad() const {
        return edad;
    }

    float getSaldo() const {
        return saldo;
    }

    vector<float> getMovimientos() const {
        return movimientos;
    }

    void realizarMovimiento(float monto) {
        saldo += monto;
        movimientos.push_back(monto);
    }

    virtual void ordenarMovimientosPorLetra() = 0;
    virtual void ordenarMovimientosPorNumero() = 0;
    virtual void agregarAlColchon(float monto) = 0;
    virtual void establecerMeta(float montoMeta) = 0;
    virtual void agregarABolsillos(float monto) = 0;
    virtual void sacarPlata(float monto) = 0;
    virtual void mostrarMovimientos() = 0;
};

class CuentaNequiImpl : public CuentaNequi {
private:
    vector<float> colchon;
    float metaDiaria;
    float metaSemanal;
    float metaMensual;
    time_t ultimoDescuento;

public:
    CuentaNequiImpl(string _nombreTitular, int _edad, float _saldo) : CuentaNequi(_nombreTitular, _edad, _saldo), metaDiaria(0), metaSemanal(0), metaMensual(0) {
        ultimoDescuento = time(nullptr);
    }

    void recargar(float monto) {
        if (getEdad() >= 18) {
            realizarMovimiento(monto);
            cout << "Recarga al toque exitosa. Nuevo saldo: " << getSaldo() << endl;
        } else {
            cout << "El usuario no es mayor de edad." << endl;
        }
    }

    void agregarAlColchon(float monto) override {
        if (monto <= getSaldo()) {
            realizarMovimiento(-monto);
            colchon.push_back(monto);
            cout << "Se ha agregado $" << monto << " al colchon." << endl;
        } else {
            cout << "Saldo insuficiente para agregar al colchon." << endl;
        }
    }

    void establecerMeta(float montoMeta) override {
        metaDiaria = montoMeta / 30; 
        metaSemanal = montoMeta / 4;  
        metaMensual = montoMeta;  
        cout << "Meta establecida correctamente." << endl;
    }

    void agregarABolsillos(float monto) override {
        if (monto <= getSaldo()) {
            realizarMovimiento(-monto);
            cout << "Se ha agregado $" << monto << " a los bolsillos." << endl;
        } else {
            cout << "Saldo insuficiente para agregar a los bolsillos." << endl;
        }
    }

    void sacarPlata(float monto) override {
        if (getSaldo() >= monto) {
            realizarMovimiento(-monto);
            cout << "Retiro exitoso. Nuevo saldo: " << getSaldo() << endl;
        } else {
            cout << "Saldo insuficiente." << endl;
        }
    }

    void mostrarMovimientos() override {
        cout << "Historial de movimientos:" << endl;
        for (const auto& movimiento : getMovimientos()) {
            if (movimiento > 0) {
                cout << "Recarga: " << movimiento << " COP" << endl;
            } else {
                cout << "Retiro: " << -movimiento << " COP" << endl;
            }
        }
    }

    void ordenarMovimientosPorNumero() override {
        int n = getMovimientos().size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (getMovimientos()[j] < getMovimientos()[j + 1]) {
                    float temp = getMovimientos()[j];
                    getMovimientos()[j] = getMovimientos()[j + 1];
                    getMovimientos()[j + 1] = temp;
                }
            }
        }
    }

    void ordenarMovimientosPorLetra() override {
        int n = getMovimientos().size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (to_string(getMovimientos()[j])[0] > to_string(getMovimientos()[j + 1])[0]) {
                    float temp = getMovimientos()[j];
                    getMovimientos()[j] = getMovimientos()[j + 1];
                    getMovimientos()[j + 1] = temp;
                }
            }
        }
    }

    void realizarDescuento() {
        time_t ahora = time(nullptr);
        tm* tiempoLocal = localtime(&ahora);
        tm* tiempoUltimoDescuento = localtime(&ultimoDescuento);

    
        if (tiempoLocal->tm_yday != tiempoUltimoDescuento->tm_yday) {
            realizarMovimiento(-metaDiaria);
            cout << "Se ha realizado el descuento diario. Nuevo saldo: " << getSaldo() << endl;
            ultimoDescuento = ahora;
        }
    }

    void realizarDescuentoSemanal() {
        time_t ahora = time(nullptr);
        tm* tiempoLocal = localtime(&ahora);
        tm* tiempoUltimoDescuento = localtime(&ultimoDescuento);

    
        if (tiempoLocal->tm_yday / 7 != tiempoUltimoDescuento->tm_yday / 7) {
            realizarMovimiento(-metaSemanal);
            cout << "Se ha realizado el descuento semanal. Nuevo saldo: " << getSaldo() << endl;
            ultimoDescuento = ahora;
        }
    }

    void realizarDescuentoMensual() {
        time_t ahora = time(nullptr);
        tm* tiempoLocal = localtime(&ahora);
        tm* tiempoUltimoDescuento = localtime(&ultimoDescuento);


        if (tiempoLocal->tm_mon != tiempoUltimoDescuento->tm_mon) {
            realizarMovimiento(-metaMensual);
            cout << "Se ha realizado el descuento mensual. Nuevo saldo: " << getSaldo() << endl;
            ultimoDescuento = ahora;
        }
    }
};

void limpiarBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    CuentaNequiImpl cuenta("Luna", 20, 4000);
    int opcion;
    int op2;
    int op3;

    do {
        cout << "----- Menu -----" << endl;
        cout << "Bienvenida " << cuenta.getNombreTitular() << endl;
        cout << "Saldo actual: $" << cuenta.getSaldo() << endl; 
        cout << "1. Realizar recarga" << endl;
        cout << "2. Agregar al colchon" << endl;
        cout << "3. Establecer meta" << endl;
        cout << "4. Agregar a bolsillos" << endl;
        cout << "5. Sacar plata" << endl;
        cout << "6. Mostrar movimientos" << endl;
        cout << "7. Salir" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        limpiarBuffer();

        switch (opcion) {
            case 1: {
                do {
                    cout << "Bienvenido a la opcion de recargar " << endl;
                    cout << "1. Realizar recarga al toque" << endl;
                    cout << "2. Realizar recarga con efectivo" << endl;
                    cout << "3. Realizar recarga desde otro banco" << endl;
                    cout << "4. Realizar recarga con codigo de regalo" << endl;
                    cin >> op2;
                    if (op2 == 1 || op2 == 2) {
                        float monto;
                        cout << "Ingrese el monto a recargar: ";
                        cin >> monto;
                        cuenta.recargar(monto);
                        break;
                    } else if (op2 == 4) {
                        string codigo;
                        float monto;
                        cout << "Ingrese el codigo de regalo: ";
                        cin >> codigo;
                        monto = stof(codigo);
                        cuenta.recargar(monto);
                        break;
                    } else {
                        cout << "Opcion invalida" << endl;
                    }
                } while (true);
                break;
            }
            case 2: {
                float monto;
                cout << "Ingrese el monto a agregar al colchon: ";
                cin >> monto;
                cuenta.agregarAlColchon(monto);
                break;
            }
            case 3: {
                float montoMeta;
                cout << "Ingrese el monto de la meta mensual: ";
                cin >> montoMeta;
                cuenta.establecerMeta(montoMeta);
                break;
            }
            case 4: {
                float monto;
                cout << "Ingrese el monto a agregar a bolsillos: ";
                cin >> monto;
                cuenta.agregarABolsillos(monto);
                break;
            }
            case 5: {
                float monto;
                cout << "Ingrese el monto a sacar: ";
                cin >> monto;
                cuenta.sacarPlata(monto);
                break;
            }
            case 6: {
                cout << "------Movimientos------" << endl;
                cuenta.mostrarMovimientos();
                do {
                    cout << "1. Ordenar movimientos por numero" << endl;
                    cout << "2. Ordenar movimientos por letra" << endl;
                    cin >> op3;
                    if (op3 == 1) {
                        cuenta.ordenarMovimientosPorNumero();
                        cout << "Movimientos ordenados por numero." << endl;
                    } else if (op3 == 2) {
                        cuenta.ordenarMovimientosPorLetra();
                        cout << "Movimientos ordenados por letra." << endl;
                    } else {
                        cout << "Opcion incorrecta" << endl;
                    }
                } while (op3 != 1 && op3 != 2);
                break;
            }
            case 7: {
                cout << "Saliendo del programa." << endl;
                break;
            }
            default:
                cout << "Opcion invalida. Por favor, ingrese una opcion valida." << endl;
        }


        cuenta.realizarDescuento();
        cuenta.realizarDescuentoSemanal();
        cuenta.realizarDescuentoMensual();

    } while (opcion != 7);

    return 0;
}
