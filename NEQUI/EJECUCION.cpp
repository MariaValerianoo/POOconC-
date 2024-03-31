#include<iostream>
using namespace std;
class Cuenta{
    private:
}
class Recarga{
//tiene la opcion, plata al toque, con efectivo, desde otro banco, codigo de regalo
//plata al toque: el usuario tiene que ser mayor de edad, 
//recarga con efectivo: te dice a donde deberias ir bien sea un punto nequi o corresponsal bancolombia
//ademas de que debes hacer en el punto y lo minimo que debes recargar
//desde otro banco: simula tu un pse, pides el tipo de banco y ademas de ello la cuenta,saldo a recargar y demas
//codigo de regalo: "Si te diero un codigo para cambiarlo por plata en Nequi, escribe el numero y redimelo facilmente
    //atributos
    private: //identificador de acceso
    double saldo;
    int codigo;
    string banco;
    int tipoCuenta;
    int numeroRecargar;
    double valorRecargar;
    void setcodigo(int _codigo){

        codigo = _codigo;

    }

    int getcodigo(){

        return codigo;

    }
    void settipoCuenta(int _tipoCuenta){

        tipoCuenta = _tipoCuenta;

    }

    int getnumeroRecargar(){

        return numeroRecargar;

    }
    void setnumeroRecargar(int _numeroRecargar){

        numeroRecargar = _numeroRecargar;

    }

    int getnumeroRecargar(){

        return numeroRecargar;

    }
    void setsaldo(double _saldo){

        saldo = _saldo;

    }

    double getsaldo(){

        return saldo;

    }
    void setvalorRecargar(double _valorRecargar){

        valorRecargar = _valorRecargar;

    }

    double getvalorRecargar(){

        return valorRecargar;

    }
    
    
    
    //metodos modificador de acceso,valor de retorno, nombre (parametro)
    public:
    void plataToque(){
        cout<<"Por favor registra tu numero de cuenta";
        cin>>tipoCuenta;
    };
    void efectivo(){
        cout<<"RECARGA CON EFECTIVO "<<endl;
        cout<<"Ve a un punto nequi o Corresponsal Bancolombia "<<endl;
        cout<<"Busca tu punto mas cercano "<<endl;
        cout<<"Dile al encargadp que vas a recargar Nequi "<<endl;
        cout<<"-Tu numero de Nequi es tu numero de celular \n -Lo minimo que puedes recargar son $10.000"<<endl;
        //aqui va el ver los puntos d recarga

    };
    void desdeOtroBanco(){
        int opcion;
        int confirmacionNumRecargar;
        int tipoPersona;
        cout<<"Usa PSE\n ¿Por qué PSE?"<<endl;
        cout<<"Es un medio de pago rapido y seguro, que te permite recargar Nequi desde cualquier cuenta bancaria\n";
        cout<<"Estas listo?\n 1)Si \n 2)No"<<endl;
        cin>>opcion;
        if (opcion==1){
            cout<<"Recarga tu Nequi"<<endl;
            cout<<"Numero de celular: "<<endl;
            cin>>numeroRecargar;
            cout<<"Confirma el numero de celular: "<<endl;
            cin>>confirmacionNumRecargar;
            cout<<"¿Cuanto?"
            cin>>valorRecargar;
            cout<<"Tipo de persona: \n 1)Natural \n 2)Juridica"<<endl;
            cin>>tipoPersona;
        }

        };
    void codigoRegalo(){
        cout<<"Aun no sabemos como funciona\n";
    };

    };

class Colchon{
//te pregunta el monto que vas a ingresar y este debe ser obviamente inferior a tu saldo
//despues este monto puede ser protegido
//si lo quieres proteger te da 3 opciones: tiempo(

    //atributos
    public: //identificador de acceso
    int saldo;
    int monto;
    //metodos modificador de acceso,valor de retorno, nombre (parametro)
    public:
    void guardarSaldo(){
        cout<<"Por favor dime el saldo que quieres ingresar: ";
        cin>>leerSaldo;
    }
    void protegerMonto(){
        cout<<"Quieres proteger el monto? \n";
        cin>>leerMontoGuardar;
    }
};
class Meta{
//
    //atributos
    public: //identificador de acceso
    int saldo;
    string tiempo;
    int meta;
    //metodos modificador de acceso,valor de retorno, nombre (parametro)
    public:
    void crearMeta(){
        cout<<"De cuanto es la meta que quieres tener?";
        cin>>leerMeta;
    }
};
class Bolsillos{
    //atributos
    public: //identificador de acceso
    string bolsillo1;
    int valor;
    //metodos modificador de acceso,valor de retorno, nombre (parametro)
    public:
    void crearBolsillo(){
        cout<<"Que nombre le quieres agregar a tu bolsillo?";
        cin>>nombre.bolsillo1;
        cout<<"Cual es el saldo que vas a tener en el?\n";
        cin>>leer.valor;
        cout<<"El bolsillo fue creado exitosamente:) "<<endl;
        cout<<bolsillo1<<endl;
        cout<<valor<<endl;
    }
};

int main(){
    Recarga person1;
    Colchon person1;
    Meta person1;
    Bolsillos person1;
    int opcion;
    cout<<"Bienvenido a nequi:) \n";
    cout<<"Que opcion deseas elegir?\n ";
    cout<<"1)Recargar Nequi\n 2)Colchon\n3)Metas\n4)Bolsillos\n";
    cin>>opcion;
    switch (opcion)
    {
    case 1:
        cout<<"Que opcion deseas elegir?: \n";
        cout<<"1)Plata al toque\n 2)Efectivo\n 3)Desde otros bancos\n 4)Codigo de regalo\n";
        cin>>opcion;
        switch (opcion)
        {
        case 1:
            person1.plataToque();
            break;
        
        default 2:
            person1.efectivo();
            break;
        default 3:
            person1.desdeOtroBanco();
            break;
        default 4:
            person1.codigoRegalo();

        }
    
    default:
        break;
    }

}
