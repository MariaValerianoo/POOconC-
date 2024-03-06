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
    double peso;
    Persona(){
        
    };
    Persona persona1;
    public:
    void pedirDatos(){
        cout<<"Ingresa tu tipo de documento\n 1)Cedula \n 2)Tarjeta de identidad \n 3)cedula extranjeria";
        cin>>persona1.tipoDoc;
        cout<<"Cual es tu documento: \n";
        cin>>persona1.documento;
        cout<<"Cual es tu nombre: \n";
        cin>>persona1.nombre;
        cout<<"Cual es tu apellido: \n";
        cin>>persona1.apellido;
        cout<<"Cual es tu estatura: \n";
        cin>>persona1.estatura;
        cout<<"Cual es tu peso: \n";
        cin>>persona1.peso;
        cout<<"Cual es tu edad: \n";
        cin>>persona1.edad;
        cout<<"Cual es tu sexo 1)femenino\n 2)masculino: \n";
        cin>>persona1.sexo;

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

    };
    void calcularmc(){
        double pesoActual = peso/estatura^2;
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
    Persona persona1;
    persona1.pedirDatos();
    persona1.mostrarPersonal();
    persona1.calcularmc();
}
