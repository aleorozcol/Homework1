#include <iostream>

struct Node
{
    int data;
    Node* next;
};

struct LinkedList{
    Node* head;
    Node* tail;
    int size;
};