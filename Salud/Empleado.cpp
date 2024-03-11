#include"Persona.cpp"
//lo incluye en la estructura, importar trae todo el paquete no more.

class Empleado:public Persona{
    private:
    string departamento;
    string cargo;
    int valorHora;
    int horasTrabajadas;
    double honorarios;
    double honorarios2;
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
    public:
    void calcularHonorarios(){
        double reteica=0.00966;
        honorarios=horasTrabajadas*valorHora;
        honorarios2=honorarios-reteica
    }; 

};
int main(){

}