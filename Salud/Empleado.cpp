#include"Persona.cpp"
//lo incluye en la estructura, importar trae todo el paquete no more.

class Empleado:public Persona{
    private:
    string departamento;
    string cargo;
    int valorHora;
    int horasTrabajadas;
    int fechaNacimiento;
    int año;
    double honorarios;
    void setDepartamento(string _departamento){

        departamento = _departamento;

    }

    string getDepartamento(){

        return departamento;

    }
    void setCargo(string _cargo){

        cargo = _cargo;

    }

    string getCargo(){

        return cargo;

    }
    void setValorHora(int _valorHora){

        valorHora = _valorHora;

    }

    int getValorHora(){

        return valorHora;

    }
    void setHorasTrabajadas(int _horasTrabajadas){

        horasTrabajadas = _horasTrabajadas;

    }

    int getHorasTrabajadas(){

        return horasTrabajadas;

    }
    void setfechaNacimiento(int _fechaNacimiento){

        fechaNacimiento = _fechaNacimiento;

    }

    int getfechaNacimiento(){

        return fechaNacimiento;

    }
    void setaño(int _año){

        año = _año;

    }

    int getaño(){

        return año;

    }
    void setHonorarios(double _honorarios){

        honorarios = _honorarios;

    }

    int getHonorarios(){

        return honorarios;

    }

    public:
    void pedirDatos(){
        cout<<"En cual departamento trabajas?:  "<<endl;
        cin>>departamento;
        cout<<"Cual es el cargo que tienes?:  "<<endl;
        cin>>cargo;
        cout<<"Cual es el cargo que tienes?:  "<<endl;
        cin>>cargo;
        cout<<"Cuanto vale la hora?:  "<<endl;
        cin>>valorHora;
        cout<<"Cuantas horas trabajaste?:  "<<endl;
        cin>>horasTrabajadas;
        cout<<"En que año naciste?:  "<<endl;
        cin>>fechaNacimiento;
        cout<<"Cual es el año actual?:  "<<endl;
        cin>>año;

    };

    void calcularHonorarios(){
        double reteica=0.00966;
        honorarios=(horasTrabajadas*valorHora)-((horasTrabajadas*valorHora)*reteica);
    };
    int mayorEdad(int fechaNacimiento, int año){
        int edad;
        edad=año-fechaNacimiento;
        if (edad>=18){
            cout<<"Eres mayor de edad:)";
        }else{
            cout<<"Eres menos de edad:("<<endl;
        }
        
    };
    void mostrarDatos(){
        Persona mostrarPersonal();
        cout<<"Tu cargo es: "<<cargo<<endl;
        cout<<"Tus horas trabajadas son: "<<horasTrabajadas<<endl;
        cout<<"Tus honorarios son: "<<honorarios<<endl;
    }

    };
    

/*int main(){
    Empleado pedro;
    pedro.mostrarDatos();
    pedro.mayorEdad(int fechaNacimiento, int año);

}*/