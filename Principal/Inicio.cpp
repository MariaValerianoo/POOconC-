#include <iostream>
#include "../Salud/persona1.cpp"
#include "../Salud/Empleado.cpp"

using namespace std;

class Inicio {
    Persona1 user;
    Empleado empleado;

};

int main(){
    Persona1 user;
    Empleado empleado;

    user.pedirDatos();
    empleado.pedirDatos();
    int pesoActual=user.calcularmc();
    if (pesoActual<20.5){
            cout<<"El peso esta por debajo de lo ideal:("<<endl;
        }else if(pesoActual>=20.0 && pesoActual<=25.0){
            cout<<"El peso es el ideal :)"<<endl;
        }else if(pesoActual>25.0){
            cout<<"Tienes sobrepeso:("<<endl;
        };
    empleado get_fechaNacimiento();
    empleado get_dato();
    empleado.mostrarDatos();
    empleado.mayorEdad(fechaNacimiento, año);
    return 0;
}

/*if (pesoActual<20.5){
            cout<<"El peso esta por debajo de lo ideal:("<<endl;
        }else if(pesoActual>=20.0 && pesoActual<=25.0){
            cout<<"El peso es el ideal :)"<<endl;
        }else if(pesoActual>25.0){
            cout<<"Tienes sobrepeso:("<<endl;
        };*/