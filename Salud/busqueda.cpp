//metodos de busqueda
//lineal 
#include<vector>
#include<iostream>
using namespace std;
/*bool busquedaLineal(const vector <int>& array, int target){
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
}*/
// arbol binario
/*struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int value):data(value),left(nullptr),right(nullptr){};
};
Node* buscar(Node*root,int key){
    if(root==nullptr||root->data==key){
        return root;
    }
    if(root->data<key){ 
        return buscar(root->right, key);
 }
 return buscar(root->left, key);
}
int main() {
 // Construcción del árbol binario de búsqueda
 Node* root = new Node(10);
 root->left = new Node(5);
 root->right = new Node(15);
 root->left->left = new Node(3);
 root->left->right = new Node(7);

 int target = 7;
 Node* result = buscar(root, target);

 if (result != nullptr) {
 cout << "Elemento encontrado en el arbol." << endl;
 } else {
 cout << "Elemento no encontrado en el arbol." << endl;
 }
 return 0;
}*/
//Busqueda por hashing
int main() {
 unordered_map<int, string> hashTable;
 // Insertar elementos en la tabla hash
 hashTable[1] = "Alice";
 hashTable[2] = "Bob";
 hashTable[3] = "Charlie";
 int targetKey = 2;
 // Buscar un elemento en la tabla hash
 auto it = hashTable.find(targetKey);
 if (it != hashTable.end()) {
 cout << "Elemento encontrado en la tabla hash: " << it->second << endl;
 } else {
 cout << "Elemento no encontrado en la tabla hash." << endl;
 }
 return 0;
}
