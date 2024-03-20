#include<iostream>
using namespace std;
/* ordenamiento de arrays*/
//metodo de la clase carta
void ordBur(string cart[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (cart[j] > cart[j + 1]) {
                string temp = cart[j];
                cart[j] = cart[j + 1];
                cart[j + 1] = temp;
            }
        }
    }
}

// Mostrar el vector
void vecOrd(string cart[], int tamanio) {
    for (int i = 0; i < tamanio; i++) {
        cout << cart[i] << " ";
    }
    cout << endl;
}
/*int main(){
    int arr[]={115,45,85,485,685,471,652,6412,5852,85};
    int n=sizeof(arr)/sizeof(arr[0]);  //sizeoff es el metodo para guardar el espacio de memoria
    cout<<"El vector original es: "<<" ";
    vecOrd(arr,n);
    ordBur(arr,n);
    cout<<"El vector ordenado es: "<<" ";
    vecOrd(arr,n);
    return 0;
}*/
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
/*int main(){
    Node*head=nullptr;
    insertInicio(head,50);
    insertInicio(head,70);
    insertInicio(head,0);
    insertInicio(head,20);
    cout<<"Listas original es: "<<endl;
    imprimirLista(head);
    ordeLista(head);
    cout<<"Listas original es: "<<endl;
    imprimirLista(head);
    return 0;


}*/

class Carta{
private:
    string cart[12];

public:
    Carta() {
        cart[0] = "9";
        cart[1] = "j";
        cart[2] = "q";
        cart[3] = "k";
        cart[4] = "a";
        cart[5] = "2";
        cart[6] = "3";
        cart[7] = "4";
        cart[8] = "5";
        cart[9] = "6";
        cart[10] = "7";
        cart[11] = "8";
    }
    void setCarta(int index, const string& carta) {
        if (index >= 0 && index < 12)
            cart[index] = carta;
        else
            cout << "Índice fuera de rango." << endl;
    }
    string getCarta(int index) const {
        if (index >= 0 && index < 12)
            return cart[index];
        else {
            cout << "Índice fuera de rango. Se devuelve una cadena vacía." << endl;
            return "";
        }
    }
};
/*int main(){
    int arr[]={115,45,85,485,685,471,652,6412,5852,85};
    int n=sizeof(arr)/sizeof(arr[0]);  //sizeoff es el metodo para guardar el espacio de memoria
    cout<<"El vector original es: "<<" ";
    vecOrd(arr,n);
    ordBur(arr,n);
    cout<<"El vector ordenado es: "<<" ";
    vecOrd(arr,n);
    return 0;
}*/
int main() {
    string cart[12] = {"9", "j", "q", "k", "a", "2", "3", "4", "5", "6", "7", "8"};
    int n = sizeof(cart) / sizeof(cart[0]);
    cout << "El vector original es: ";
    vecOrd(cart, n);
    ordBur(cart, n);
    cout << "El vector ordenado es: ";
    vecOrd(cart, n);
    return 0;
}


/*
void ordBur(string cart[],string n){
    for(string i=0;i<n-1;i++){
        for(string j=0;j<n-i-1;j++){
            string temp=cart[j];
            cart[j]=cart[j+1];
            cart[j+1]=temp;
        }
    }

}
//mostrar el vector
void vecOrd(string cart[],string tamanio){
    for(string i=0;i<tamanio;i++){
        cout<<cart[i]<<" ";
        cout<<endl;
    }
}
int main(){
    string cart[12]={"9","j","q","k","a","2","3","4","5","6","7","8"};
    string n=sizeof(cart)/sizeof(cart[0]);
    cout<<"El vector original es: "<<" ";
    vecOrd(cart,n);
    ordBur(cart,n);
    cout<<"El vector ordenado es: "<<" ";
    vecOrd(cart,n);
    return 0;




}

POR REVISAR

*/