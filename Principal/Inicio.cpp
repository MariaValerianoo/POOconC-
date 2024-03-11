#include <iostream>
#include "../Salud/Persona.cpp"
#include "../Salud/Empleado.cpp"

using namespace std;

class Inicio {
    Persona user;
    Empleado usuario;

}

int main(){
    Persona user;
    Empleado usuario;
    user.pedirDatos();
    usuario.pedirDatos();
    int pesoActual=user.calcularmc();
    if (pesoActual<20.5){
            cout<<"El peso esta por debajo de lo ideal:("<<endl;
        }else if(pesoActual>=20.0 && pesoActual<=25.0){
            cout<<"El peso es el ideal :)"<<endl;
        }else if(pesoActual>25.0){
            cout<<"Tienes sobrepeso:("<<endl;
        };
    usuario.mostrarDatos();
    usuario.mayorEdad(int fechaNacimiento, int año);

    return 0;
}

/*if (pesoActual<20.5){
            cout<<"El peso esta por debajo de lo ideal:("<<endl;
        }else if(pesoActual>=20.0 && pesoActual<=25.0){
            cout<<"El peso es el ideal :)"<<endl;
        }else if(pesoActual>25.0){
            cout<<"Tienes sobrepeso:("<<endl;
        };*/