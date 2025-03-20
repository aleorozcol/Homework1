#include <iostream>
#include <memory>

using namespace std;
/*
3. Implemente una lista enlazada que utilice nodos que simplemente contengan un
valor y una dirección de memoria de un nodo. Adicionalmente, agregue las siguientes
funciones para manejar la lista:
i. create_node(): devuelve un nodo.
ii. push_front(): inserta un nodo al frente de la lista.
iii. push_back(): inserta un nodo al final de la lista.
iv. insert(): inserta un nodo en la posición que se le pase a la función. Si se le pasa
una posición mayor al largo de la lista, se debe indicar lo ocurrido y se debe de
agregar el nodo al final de la lista.
v. erase(): borra un nodo en la posición que se le pase a la función. Similar a la
función insert(), si la posición es mayor que el largo de la lista, se debe de borrar
el último nodo.
vi. print_list(): imprime la lista completa, separando el valor en cada nodo con “->”.
Presentar ejemplos que verifiquen el funcionamiento requerido en las funciones i-vi y,
muy importante para el ejercicio, sólo utilizar smart pointers. 
*/

struct Node {
    int value;
    shared_ptr<Node> next;
    Node(int val): value(val), next(nullptr){}
};

shared_ptr<Node> head = nullptr;

shared_ptr<Node> create_node(int value){
    return make_shared<Node>(value);
}

void push_front(int value) {
    auto new_node = create_node(value);
    new_node->next = head;
    head = new_node;
}

void push_back(int value){
    auto new_node =create_node(value);
    if (!head) {
        head = new_node;
    } else {
        auto current = head;
        while (current->next){
            current = current->next;
        }
        current->next = new_node;
    }
}

void insert(int value, int pos) {
    if (pos == 0) {
        push_front(value);
        return;
    }

    auto new_node = create_node(value);
    auto current = head;
    int index = 0;

    while (current && index < pos-1){
        current = current->next;
        index++;
    }

    if (!current) {
        cout << "Lo inserté al final porque se pasó del largo de la lista.\n";
        push_back(value);
    } else {
        new_node-> next = current->next;
        current->next = new_node;
    }
}

void erase(int pos){
    if (!head){
        cout << "La lista está vacía.\n";
        return;
    }
    if (pos==0){
        head = head->next;
        return;
    }
    auto current = head;
    int index = 0;
    while (current->next && index < pos-1){
        current = current->next;
        index++;
    }
    if (!current->next){
        cout << "Pos mayor, se borró el ult nodo.\n";
        if (head->next == nullptr){
            head = nullptr;
        } else {
            auto temp = head;
            while (temp->next && temp->next->next){
                temp = temp->next;
            }
            temp->next = nullptr;
        }
    } else {
        current->next = current->next->next;
    }
}

void print_list(){
    auto current = head;
    while (current){
        cout << current->value;
        if (current->next){
            cout << "->";
        }
        current = current->next;
    }
    cout << "\n";
}

int main(){
    push_front(10);
    push_front(20);
    push_front(30);
    print_list();
}
