//metodos de busqueda
//lineal 
#include<vector>
#include<iostream>
using namespace std;
bool busquedaLineal(const vector <int>& array, int target){
    for(int element:array){
        if(element==target){
            return true;
        }
    }
    return false;

}
int main(){
    vector<int> numbers={1,2,8,5,4,56,9};
    int target=2;
    if(busquedaLineal(numbers,target)){
        cout<<"El elemento "<<target<<" esta en el array"<<endl;
    }else{
        cout<<"El elemento "<<target<<" no esta en el array"<<endl;
    }
    return 0;
}
// arbol binario
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int value):data(value),left(nullptr),right(nullptr){}:
};
Node* buscar(Node*root,int key){
    if(root==nullptr||root->data==key){
        return root;
    }
    if(root->data<key){
        return buscar()
    }
}