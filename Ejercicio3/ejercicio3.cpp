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

// struct del nodo de la lista enlazada
struct Node {
    int value;
    shared_ptr<Node> next;
    Node(int val): value(val), next(nullptr){} // inicializa el nodo con un valor y un puntero nulo
};

// puntero global al inicio de la lista
shared_ptr<Node> head = nullptr;

// i. create_node(): devuelve un nodo.
shared_ptr<Node> create_node(int value){
    return make_shared<Node>(value);
}

// ii. push_front(): inserta un nodo al frente de la lista.
void push_front(int value) {
    auto new_node = create_node(value);
    new_node->next = head; // el nuevo nodo apunta al anterior head
    head = new_node; // actualizamos el head
}

// iii. push_back(): inserta un nodo al final de la lista.
void push_back(int value){
    auto new_node =create_node(value);
    if (!head) { // lista vacía, entonces el nuevo nodo es head
        head = new_node;
        return;
    }
    auto current = head;
    while (current->next){ // recorremos hasta el ultimo nodo
        current = current->next;
    }
    current->next = new_node;
}

// iv. insert(): inserta un nodo en la posición que se le pase a la función.
void insert(int value, int pos) {
    if (pos == 0) { // primera posición
        push_front(value);
        return;
    }

    auto new_node = create_node(value);
    auto current = head;
    int index = 0;

    while (current && index < pos-1){ // avanzamos hasta la pos que queremos o hasta el final
        current = current->next;
        index++;
    }

    if (!current) { // la pos es mayor al tamaño de la lista entonces lo insertamos al final
        cout << "El nodo fue insertado al final de la lista porque la posición elegida es mayor al tamaño de la lista.\n";
        push_back(value);
    } else {
        new_node-> next = current->next;
        current->next = new_node;
    }
}

// v. erase(): borra un nodo en la posición que se le pase a la función.
void erase(int pos){

    if (!head){
        cout << "La lista está vacía.\n";
        return;
    }

    if (pos==0){ // actualizamos el head
        head = head->next;
        return;
    }

    auto current = head;
    int index = 0;
    
    while (current->next && index < pos-1){ // avanzamos hasta el nodo anterior
        current = current->next;
        index++;
    }

    if (!current->next){
        if (head->next == nullptr){
            head = nullptr;
        } else {
            cout << "Se borró el último nodo porque la posición se excede del tamaño de la lista.\n";
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

//vi. print_list(): imprime la lista completa.
void print_list(){
    if (!head){
        cout << "La lista está vacía.\n";
    }
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
    // Test de push_front
    cout << "Insert de 3 veces un head (push_front):\n";
    push_front(30);
    push_front(20);
    push_front(10);
    print_list();
    // Test de push_back
    cout << "Insert de 3 veces un tail (push_back):\n";
    push_back(40);
    push_back(50);
    push_back(60);
    print_list();
    // Test de insert
    cout << "Insert 2 veces en posiciones dentro de la lista y 1 fuera (insert):\n";
    insert(15,1);
    insert(25,3);
    insert(70,15);
    print_list();    
    //Test de erase
    cout << "Erase de toda la lista:\n";
    erase(0);
    print_list();
    erase(0);
    print_list();
    erase(0);
    print_list();
    erase(0);
    print_list();
    erase(0);
    print_list();
    erase(0);
    print_list();
    erase(0);
    print_list();
    erase(0);
    print_list();
    erase(0);
    print_list();
}
