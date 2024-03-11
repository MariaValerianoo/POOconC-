#include <iostream>
#include "../Salud/Persona.cpp"

using namespace std;

class Inicio {
public:
    void ejecutar() {
        Persona user1;
        double imc = user1.calcularmc(); 

        if (imc < 20.5) {
            cout << "El peso está por debajo de lo ideal :(" << endl;
        } else if (imc >= 20.0 && imc <= 25.0) {
            cout << "El peso es el ideal :)" << endl;
        } else if (imc > 25.0) {
            cout << "Tienes sobrepeso :(" << endl;
        }
    }
};

int main(){
    Inicio inicio;
    inicio.ejecutar();
    return 0;
}

/*if (pesoActual<20.5){
            cout<<"El peso esta por debajo de lo ideal:("<<endl;
        }else if(pesoActual>=20.0 && pesoActual<=25.0){
            cout<<"El peso es el ideal :)"<<endl;
        }else if(pesoActual>25.0){
            cout<<"Tienes sobrepeso:("<<endl;
        };*/