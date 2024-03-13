#include<iostream>
#include<list>
using namespace std;
int main(){
    list<string>frutas;
    frutas.push_back("Manzana");
    frutas.push_back("Pera");
    frutas.push_back("Uvas");
    frutas.push_back("Melon");
    frutas.push_back("Fresa");
    for (const auto & elemento: frutas)//auto es el iterador
    {
        cout<<elemento<<"";
    }
    auto it=next(frutas.begin(),1);
    frutas.insert(it,"arandanos");
    for (const auto & elemento: frutas)//auto es el iterador
    {
        cout<<elemento<<"";
    }
    frutas.pop_front();
    auto it1=next(frutas.begin(),2);
    frutas.erase(it1);
    frutas.remove("uvas"); //cuando tengo el dato
    frutas.front();//me muestra el primer elemento
    frutas.back();//me muestra el ultimo elemento
    auto it2=next(frutas.begin(),3);
    cout<<*it2; //imprime el apuntador del iterador
    frutas.get_allocator();//referencias de un elemento
    frutas.empty();//me muestra si esta
    frutas.size();//tamaño
    frutas.max_size(); //maximo de elementos de una lista
    

    return 0;

}