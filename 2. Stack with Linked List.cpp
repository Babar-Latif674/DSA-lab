#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int d) : data(d), next(NULL){}
};

class StackLL{
    Node* top;

public:
    StackLL(){
        top = NULL;
    }
    void push(int value){
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    void pop(){
        if (!top){
            cout << "Stack Underflow\n";
            return;
        }
        cout << "Popped: " << top->data << endl;
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    void display(){
        Node* temp = top;
        while (temp){
            cout << temp->data << "  ";
            temp = temp->next;
        }
        cout << endl;
    }
};

