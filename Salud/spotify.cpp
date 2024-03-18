#include <iostream>
#include <list>
#include <string>
using namespace std;

class Cancion{
    private:
    string nomCancion;
    string artista;
    float duracion;
    public:
    Cancion(string nombre, string art, float dur) {
        nomCancion = nombre;
        artista = art;
        duracion = dur;
    }
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
void agregarCancion(){
    Cancion aux;
    string a;
    string b;
    float c;
    cout<<"Cual es el nombre de la cancion?\n";
    cin>>a;
    cout<<"Cual es el artista de la cancion?\n";
    cin>>b;
    cout<<"Cual es la duracion de la cancion?\n";
    cin>>c;
    aux.setNomCancion(a);
    aux.setArtista(b);
    aux.setDuracion(c);

}

int main() {
    canciones.
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
