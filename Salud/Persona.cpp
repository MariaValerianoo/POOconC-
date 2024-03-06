#include<iostream>
using namespace std;


class Persona{

    public:
    string tipoDoc;
    int documento;
    string nombre;
    string apellido;
    double estatura;
    int edad;
    int sexo;
    int peso;
    Persona(){
        
    };
    Persona person1;
    public:
    void pedirDatos(){
        cout<<"Ingresa tu tipo de documento\n 1)Cedula \n 2)Tarjeta de identidad \n 3)cedula extranjeria";
        cin>>person1.tipoDoc;
        cout<<"Cual es tu documento: \n";
        cin>>person1.documento;
        cout<<"Cual es tu nombre: \n";
        cin>>person1.nombre;
        cout<<"Cual es tu apellido: \n";
        cin>>person1.apellido;
        cout<<"Cual es tu estatura: \n";
        cin>>person1.estatura;
        cout<<"Cual es tu peso: \n";
        cin>>person1.peso;
        cout<<"Cual es tu edad: \n";
        cin>>person1.edad;
        cout<<"Cual es tu sexo 1)femenino\n 2)masculino: \n";
        cin>>person1.sexo;

    }
    void mostrarPersonal(){
        cout<<"Tus datos son:\n";
        cout<<"Tu tipo de documento es: "<<tipoDoc;
        cout<<"Tu documento es: "<<documento;
        cout<<"Tu nombre es: "<<nombre;
        cout<<"Tu apellido es: "<<apellido;
        cout<<"Tu estatura es: "<<estatura;
        cout<<"Tu peso es: "<<peso;
        cout<<"Tu edad es: "<<edad;
        cout<<"Tu sexo es: "<<sexo;

    }
    void calcularmc(){
        int pesoActual= peso/estatura^2;
        if (pesoActual<20){
            cout<<"El peso esta por debajo de lo ideal:(";
        }else if(pesoActual>=20 && pesoActual<=25){
            cout<<"El peso es el ideal :)";
        }else if(pesoActual>25){
            cout<<"Tienes sobrepeso:(";
        }

    }
    void mayorEdad(){
        if (edad>18){
            cout<<"Eres mayor de edad:)";
        }else if(edad<18){
            cout<<"Eres menos de edad:(";
        }
    }
};
int main(){
    Persona person1;
    person1.pedirDatos();
    person1.mostrarPersonal();
    person1.calcularmc();
}