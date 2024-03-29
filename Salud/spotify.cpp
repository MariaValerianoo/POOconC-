#include <iostream>
#include <list>
#include <string>
using namespace std;

class Cancion {
private:
    string nomCancion;
    string artista;
    float duracion;

public:
    Cancion() {}

    string getNomCancion() const {
        return nomCancion;
    }

    string getArtista() const {
        return artista;
    }

    float getDuracion() const {
        return duracion;
    }

    void setNomCancion(string nombre) {
        nomCancion = nombre;
    }

    void setArtista(string art) {
        artista = art;
    }

    void setDuracion(float dur) {
        duracion = dur;
    }
};

Cancion agregarCancion(int opcion) {
    Cancion aux;
    string a;
    string b;
    float c;
    cout << "Cual es el nombre de la cancion?\n";
    cin >> a;
    cout << "Cual es el artista de la cancion?\n";
    cin >> b;
    cout << "Cual es la duracion de la cancion?\n";
    cin >> c;
    aux.setNomCancion(a);
    aux.setArtista(b);
    aux.setDuracion(c);

    return aux;
}class Nodo {
public:
    int dato;
    Nodo* siguiente;

    Nodo(int valor) {
        dato = valor;
        siguiente = nullptr;
    }
};

class ListaEnlazada {
private:
    Nodo* cabeza;

public:
    ListaEnlazada() {
        cabeza = nullptr;
    }

    void agregarAlInicio(int valor) {
        Nodo* nuevoNodo = new Nodo(valor);
        nuevoNodo->siguiente = cabeza;
        cabeza = nuevoNodo;
    }

    void imprimir() {
        Nodo* temp = cabeza;
        while (temp != nullptr) {
            cout << temp->dato << " ";
            temp = temp->siguiente;
        }
        cout << endl;
    }

    bool buscar(int valor) {
        Nodo* temp = cabeza;
        while (temp != nullptr) {
            if (temp->dato == valor) {
                return true;
            }
            temp = temp->siguiente;
        }
        return false;
    }
};

int main() {
    int opcion;
    do{ 
        cout<<"Bienvenido a spotify \n ¿Que deseas hacer?: \n"; 
        cout<<"1) Ir a tu lista general \n 2) Ir a tu lista \n 3)Ir a la lista de tu amigo\n 4)Ir a tu lista compartida\n 5)Salir\n";
        



    }while()
    
    list<Cancion> canciones;
    do{
        cout<<"Bienvenido esta va a ser tu lista general \n";
        cout<<"Empecemos a agregar canciones: \n";
        canciones.push_back(agregarCancion(opcion));
        for (const auto &cancion : canciones) {
            cout << "Nombre: " << cancion.getNomCancion() << ", Artista: " << cancion.getArtista() << ", Duracion: " << cancion.getDuracion() << endl;
        }



    }
    cout<<"Bienvenido a spotify esta va a ser tu lista general \n";
    cout<<"Empecemos a agregar canciones: \n";
    canciones.push_back(agregarCancion(opcion));
    for (const auto &cancion : canciones) {
        cout << "Nombre: " << cancion.getNomCancion() << ", Artista: " << cancion.getArtista() << ", Duracion: " << cancion.getDuracion() << endl;
    }


    /*do {
        cout << "¿Qué canción te gustaría agregar a tus 'Me gusta'?" << endl;
        string nueva_cancion;
        cin.ignore(); // Ignore newline character left in the buffer
        getline(cin, nueva_cancion);
        canciones2.push_back(nueva_cancion);
        cout << "¡Canción agregada a tus 'Me gusta'!" << endl;

        cout << "Te gustaría agregar otra canción?: \n 1) Si \n 2) No \n";
        cin >> opcion;
        cin.ignore(); // Ignore newline character left in the buffer

        if (opcion != 1 && opcion != 2) {
            cout << "Opción no válida. Por favor, ingresa 1 o 2." << endl;
        }

    } while (opcion == 1);

    cout << "Tu lista de me gusta es: " << endl;
    for (const auto &elemento : canciones2) {
        cout << elemento << endl;
    }*/

    return 0;
}
