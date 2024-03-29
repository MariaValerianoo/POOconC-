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

    Cancion(string nombre, string art, float dur) : nomCancion(nombre), artista(art), duracion(dur) {}

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
    cin.ignore(); 
    getline(cin, a);
    cout << "Cual es el artista de la cancion?\n";
    cin.ignore(); 
    getline(cin, b);
    cout << "Cual es la duracion de la cancion?\n";
    cin >> c;
    aux.setNomCancion(a);
    aux.setArtista(b);
    aux.setDuracion(c);

    return aux;
}

class Nodo {
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

void listaGene(list<Cancion>& lista) {
    int op2;
    cout << "Bienvenido esta va a ser tu lista general \n";
    cout << "Empecemos a agregar canciones: \n";
    do {
        lista.push_back(agregarCancion(op2)); // Cambio aquí
        for (const auto& cancion : lista) {
            cout << "Nombre: " << cancion.getNomCancion() << ", Artista: " << cancion.getArtista() << ", Duracion: " << cancion.getDuracion() << endl;
        }
        cout << "Quieres agregar otra cancion?\n 1)Si\n 2)No\n";
        cin >> op2;

    } while (op2 == 1);
}


void miLista(list<Cancion>& listaGeneral) {
    int opcion;
    list<Cancion> canciones2;
    cout << "Bienvenido a tu lista de Me gusta \n";
    cout << "Tu lista general es: \n";
    for (const auto& cancion : listaGeneral) {
        cout << "Nombre: " << cancion.getNomCancion() << ", Artista: " << cancion.getArtista() << ", Duracion: " << cancion.getDuracion() << endl;
    }
    do {
        cout << "Que cancion te gustaria agregar a tus Me gusta?" << endl;
        string nombreCancion;
        cin.ignore();
        getline(cin, nombreCancion);
        
        bool encontrada = false;
        for (const auto& cancion : listaGeneral) {
            if (cancion.getNomCancion() == nombreCancion) {
                canciones2.push_back(cancion);
                encontrada = true;
                cout << "¡Cancion agregada a tus Me gusta!" << endl;
                break;
            }
        }
        
        if (!encontrada) {
            int respuesta;
            cout << "No se encontro la cancion en tu lista general. Deseas agregarla a la lista general? \n 1)Si \n 2)No" << endl;
            cin >> respuesta;
            if (respuesta == 1) {
                listaGeneral.push_back(agregarCancion(opcion));
                canciones2.push_back(listaGeneral.back());
                cout << "Cancion agregada a la lista general y a tus Me gusta!" << endl;
            }
        }

        cout << "Te gustaria agregar otra cancion?: \n 1) Si \n 2) No \n";
        cin >> opcion;
        cin.ignore();

        if (opcion != 1 && opcion != 2) {
            cout << "Opcion no valida. Por favor, ingresa 1 o 2." << endl;
        }

    } while (opcion == 1);

    cout << "Tu lista de me gusta es: " << endl;
    for (const auto &elemento : canciones2) {
        cout << "Nombre: " << elemento.getNomCancion() << ", Artista: " << elemento.getArtista() << ", Duracion: " << elemento.getDuracion() << endl;
    }
}
void listaAmigo(list<Cancion>& listaGeneral) {
    int opcion;
    list<Cancion> canciones3;
    cout << "Bienvenido a tu lista de Me gusta \n";
    cout << "Tu lista general es: \n";
    for (const auto& cancion : listaGeneral) {
        cout << "Nombre: " << cancion.getNomCancion() << ", Artista: " << cancion.getArtista() << ", Duracion: " << cancion.getDuracion() << endl;
    }
    cout << "Que te gustaria hacer?\n ";
    cout << "1)Agregar canciones\n2)Ver lista de reproduccion ";
    cin>>opcion;
    if (opcion==1 )
    {
        do {
        cout << "Tu lista general es: \n";
        for (const auto& cancion : listaGeneral) {
            cout << "Nombre: " << cancion.getNomCancion() << ", Artista: " << cancion.getArtista() << ", Duracion: " << cancion.getDuracion() << endl;
        }   
        cout << "Que cancion te gustaria agregar a tus Me gusta?" << endl;
        string nombreCancion;
        cin.ignore();
        getline(cin, nombreCancion);
        
        bool encontrada = false;
        for (const auto& cancion : listaGeneral) {
            if (cancion.getNomCancion() == nombreCancion) {
                canciones3.push_back(cancion);
                encontrada = true;
                cout << "¡Cancion agregada a tus Me gusta!" << endl;
                break;
            }
        }
        
        if (!encontrada) {
            int respuesta;
            cout << "No se encontro la cancion en tu lista general. Deseas agregarla a la lista general? \n 1)Si \n 2)No" << endl;
            cin >> respuesta;
            if (respuesta == 1) {
                listaGeneral.push_back(agregarCancion(opcion));
                canciones3.push_back(listaGeneral.back());
                cout << "Cancion agregada a la lista general y a tus Me gusta!" << endl;
            }
        }

        cout << "Te gustaria agregar otra cancion?: \n 1) Si \n 2) No \n";
        cin >> opcion;
        cin.ignore();

        if (opcion != 1 && opcion != 2) {
            cout << "Opcion no valida. Por favor, ingresa 1 o 2." << endl;
        }

    } while (opcion == 1);

    cout << "Tu lista de me gusta es: " << endl;
    for (const auto &elemento : canciones3) {
        cout << "Nombre: " << elemento.getNomCancion() << ", Artista: " << elemento.getArtista() << ", Duracion: " << elemento.getDuracion() << endl;
    }
    }else if(opcion==2){
        cout << "Tu lista de me gusta es: " << endl;
    for (const auto &elemento : canciones3) {
        cout << "Nombre: " << elemento.getNomCancion() << ", Artista: " << elemento.getArtista() << ", Duracion: " << elemento.getDuracion() << endl;
    }

    }
    
    
}


int main() {
    int num;
    list<Cancion> listaGeneral;
    while (true) {
        cout << "Bienvenido a spotify \n Que deseas hacer?: \n";
        cout << "1) Ir a tu lista general \n2) Ir a tu lista \n3)Ir a la lista de tu amigo\n4)Ir a tu lista compartida\n5)Salir\n";
        cin >> num;
        switch (num) {
        case 1:
            listaGene(listaGeneral);
            break;

        case 2:
            miLista(listaGeneral);
            break;
        case 3:
            listaAmigo(listaGeneral);
            break;
        case 4:
            break;
        case 5:
            cout << "Gracias por utilizar spotify:) \n";
            return 0;
        }
    }

    return 0;
}


