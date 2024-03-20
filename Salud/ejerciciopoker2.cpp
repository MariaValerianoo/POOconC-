#include<iostream>
using namespace std;
#include<list>

/* ordenamiento de listas*/
struct Node{
    int data;
    Node* next;
    Node(int val):data(val),next(nullptr){    }
};
//funcion para insertar un nodo al principio de la lista
void insertInicio(Node* &head,int val){
    Node*nuevoNodo= new Node (val);
    nuevoNodo->next=head;
    head=nuevoNodo;
}

//funcion para imprimirla lista
void imprimirLista(Node* head){
    while(head!=nullptr){
        cout<<head->data <<" ";
        head=head->next;

    }
    cout<<endl;
}
//funcion para ordenar
void ordeLista(Node* & head){
    if(head==nullptr|| head->next==nullptr)
    return;
    Node* sorted=nullptr;
    Node* current=head;
    while(current!=nullptr){
        Node* nextNode=current->next;
        if(sorted==nullptr || sorted->data >= current->data){
            current->next=sorted;
            sorted=current;
        }else{
            Node* temp=sorted;
            while(temp->next!=nullptr && temp->next->data < current->data){
                temp=temp->next;
            }
            current->next=temp->next;
            temp->next=current;
        }
        current=nextNode;
    }
    head=sorted;

};
int main(){
    Node*head=nullptr;
    list<string>cart;
    list<string>pinta;
    cart={"2","3","5","8","6"};
    pinta={"picas","diamantes","corazones","treboles"};
    for (auto it = cart.rbegin(); it != cart.rend(); ++it) {
        insertInicio(head, stoi(*it));
    }
    cout<<"Listas original es: "<<endl;
    imprimirLista(head);
    ordeLista(head);
    cout<<"Lista ordenada es: "<<endl;
    imprimirLista(head);
    return 0;


}