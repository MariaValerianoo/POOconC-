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

Cancion agregarCancion() {
    string a, b;
    float c;
    cout << "Cual es el nombre de la cancion?\n";
    cin.ignore();
    getline(cin, a);
    cout << "Cual es el artista de la cancion?\n";
    getline(cin, b);
    cout << "Cual es la duracion de la cancion?\n";
    cin >> c;
    cin.ignore(); // Para limpiar el buffer del salto de línea
    return Cancion(a, b, c);
}

void listaGene(list<Cancion>& lista) {
    int op2;
    cout << "Bienvenido esta va a ser tu lista general \n";
    cout << "Empecemos a agregar canciones: \n";
    do {
        lista.push_back(agregarCancion());
        for (const auto& cancion : lista) {
            cout << "Nombre: " << cancion.getNomCancion() << ", Artista: " << cancion.getArtista() << ", Duracion: " << cancion.getDuracion() << endl;
        }
        cout << "Quieres agregar otra cancion?\n 1)Si\n 2)No\n";
        cin >> op2;
        cin.ignore(); // Para limpiar el buffer del salto de línea

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
            cin.ignore(); // Para limpiar el buffer del salto de línea
            if (respuesta == 1) {
                listaGeneral.push_back(agregarCancion());
                canciones2.push_back(listaGeneral.back());
                cout << "Cancion agregada a la lista general y a tus Me gusta!" << endl;
            }
        }

        cout << "Te gustaria agregar otra cancion?: \n 1) Si \n 2) No \n";
        cin >> opcion;
        cin.ignore(); // Para limpiar el buffer del salto de línea

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
    cin >> opcion;
    if (opcion == 1 ) {
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
                cin.ignore(); // Para limpiar el buffer del salto de línea
                if (respuesta == 1) {
                    listaGeneral.push_back(agregarCancion());
                    canciones3.push_back(listaGeneral.back());
                    cout << "Cancion agregada a la lista general y a tus Me gusta!" << endl;
                }
            }

            cout << "Te gustaria agregar otra cancion?: \n 1) Si \n 2) No \n";
            cin >> opcion;
            cin.ignore(); // Para limpiar el buffer del salto de línea

            if (opcion != 1 && opcion != 2) {
                cout << "Opcion no valida. Por favor, ingresa 1 o 2." << endl;
            }

        } while (opcion == 1);

        cout << "Tu lista de me gusta es: " << endl;
        for (const auto &elemento : canciones3) {
            cout << "Nombre: " << elemento.getNomCancion() << ", Artista: " << elemento.getArtista() << ", Duracion: " << elemento.getDuracion() << endl;
        }
    } else if(opcion==2){
        cout << "Tu lista de me gusta es: " << endl;
        for (const auto &elemento : canciones3) {
            cout << "Nombre: " << elemento.getNomCancion() << ", Artista: " << elemento.getArtista() << ", Duracion: " << elemento.getDuracion() << endl;
        }

    }
}

class Nodo {
public:
    Cancion dato; 
    Nodo* siguiente;

    Nodo(const Cancion& cancion) : dato(cancion), siguiente(nullptr) {}
};

class ListaEnlazada {
private:
    Nodo* cabeza;

public:
    ListaEnlazada() {
        cabeza = nullptr;
    }

    void agregarAlInicio(const Cancion& cancion) { 
        Nodo* nuevoNodo = new Nodo(cancion); 
        nuevoNodo->siguiente = cabeza;
        cabeza = nuevoNodo;
    }

    void imprimir() {
        Nodo* temp = cabeza;
        while (temp != nullptr) {
            cout << "Nombre: " << temp->dato.getNomCancion() << ", Artista: " << temp->dato.getArtista() << ", Duracion: " << temp->dato.getDuracion() << endl;
            temp = temp->siguiente;
        }
        cout << endl;
    }
};

void compartida(list<Cancion>& listaAmigo, list<Cancion>& miLista) {
    ListaEnlazada lista; 
    Node*head=nullptr;
    ordeLista(head);
    imprimirLista(head);

    for (const auto& cancion : listaAmigo) {
        lista.agregarAlInicio(cancion);
    }

    for (const auto& cancion : miLista) {
        lista.agregarAlInicio(cancion);
    }
    ordeLista(head);
    imprimirLista(head);
}
/* ordenamiento de listas*/
struct Node{
    int data;
    Node* next;
    Node(int val):data(val),next(nullptr){    }
};
//funcion para insertar un nodo al principio de la lista
void insertInicio(Node* &head,int val){
    Node*nuevoNodo= new Node (val);
    nuevoNodo->next=head;
    head=nuevoNodo;
}

//funcion para imprimirla lista
void imprimirLista(Node* head){
    while(head!=nullptr){
        cout<<head->data <<" ";
        head=head->next;

    }
    cout<<endl;
}
//funcion para ordenar
void ordeLista(Nodo*& head) {
    if (head == nullptr || head->siguiente == nullptr)
        return;
    Nodo* sorted = nullptr;
    Nodo* current = head;
    while (current != nullptr) {
        Nodo* nextNode = current->siguiente;
        if (sorted == nullptr || sorted->dato.getNomCancion() >= current->dato.getNomCancion()) {
            current->siguiente = sorted;
            sorted = current;
        } else {
            Nodo* temp = sorted;
            while (temp->siguiente != nullptr && temp->siguiente->dato.getNomCancion() < current->dato.getNomCancion()) {
                temp = temp->siguiente;
            }
            current->siguiente = temp->siguiente;
            temp->siguiente = current;
        }
        current = nextNode;
    }
    head = sorted;
}

void compartida(list<Cancion>& listaAmigo, list<Cancion>& miLista) {
    ListaEnlazada lista;
    Node* head = nullptr;

    for (const auto& cancion : listaAmigo) {
        lista.agregarAlInicio(cancion);
    }

    for (const auto& cancion : miLista) {
        lista.agregarAlInicio(cancion);
    }

    Nodo* temp = lista.getCabeza();
    while (temp != nullptr) {
        insertInicio(head, temp->dato);
        temp = temp->siguiente;
    }

    ordeLista(head);
    imprimirLista(head);
}

void miListaOrd(list<Cancion>& miLista) {
    ListaEnlazada lista;
    for (const auto& cancion : miLista) {
        lista.agregarAlInicio(cancion);
    }
    Nodo* head = lista.getCabeza();
    ordeLista(head);
    imprimirLista(head);
}

void listaAmigoOrd(list<Cancion>& listaAmigo) {
    ListaEnlazada lista;
    for (const auto& cancion : listaAmigo) {
        lista.agregarAlInicio(cancion);
    }
    Nodo* head = lista.getCabeza();
    ordeLista(head);
    imprimirLista(head);
}


int main() {
    int num;
    list<Cancion> listaGeneral;
    while (true) {
        cout << "Bienvenido a spotify \n Que deseas hacer?: \n";
        cout << "1) Ir a tu lista general \n2) Ir a tu lista \n3)Ir a la lista de tu amigo\n4)Ir a tu lista compartida\n";
        cout << "5)Ver las listas ordenadas\n 6) salir\n";
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
            compartida(listaAmigo, listaGeneral);
            break;
        case 5:
            cout << "Que lista quieres ver ordenada?\n ";
            cout << "1)Tu lista\n 2)Lista Amigo\n ";
            cin >> num;
            if(num==1){
                miListaOrd(listaGeneral);
            } else if(num==2){
                listaAmigoOrd(listaGeneral);
            }
            break;
        case 6:
            cout << "Gracias por utilizar spotify:) \n";
            return 0;
        default:
            cout << "Opción no válida. Por favor, selecciona una opción válida." << endl;
            break;
        }
    }

    return 0;
}



