#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
    int opcion;
    list<string> canciones;
    list<string> canciones2;
    cout<<"Bienvenido a esta lista general, mira las opciones que tenemos: "<<endl;
    canciones.push_back("La noche mas linda del mundo, salsa");
    canciones.push_back("Persona Ideal, salsa");
    canciones.push_back("Luna, reguetón");
    canciones.push_back("Sabes una cosa, Balada");
    canciones.push_back("Lady madriz, Reguetón");
    for (const auto &elemento : canciones) {
        cout << elemento << endl;
    }
    cout << endl;
    
    do {
        cout << "¿Qué canción te gustaría agregar a tus 'Me gusta'?" << endl;
        string nueva_cancion;
        getline(cin, nueva_cancion);
        canciones2.push_back(nueva_cancion);
        cout << "¡Canción agregada a tus 'Me gusta'!" << endl;
        
        cout << "Te gustaría agregar otra canción?: \n 1) Si \n 2) No \n";
        cin >> opcion;
        cin.ignore(); 
        
        if (opcion != 1 && opcion != 2) {
            cout << "Opción no válida. Por favor, ingresa 1 o 2." << endl;
        }
        
    } while (opcion == 1);
    
    cout << "Tu lista de me gusta es: " << endl;
    for (const auto &elemento : canciones2) {
        cout << elemento << endl;
    }

    return 0;
}
